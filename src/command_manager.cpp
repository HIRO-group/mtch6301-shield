#include <algorithm>
#include <command_manager.hpp>
#include <Arduino.h>
#include <communication/serial.hpp>
#include <mtch.hpp>


void CommandManager::handle_test_command(const proto::TestCommand& test_command) {
  this->light_on = !this->light_on;
  digitalWrite(STATUS_LED, this->light_on ? HIGH : LOW);  
}

void CommandManager::handle_set_number_channels_command(const proto::SetNumChannelsCommand& set_num_channels_command) {
  this->mtch->enable_touch(false);
  int clamped_rx = std::clamp((int)set_num_channels_command.num_rx(), 3, 13);
  int clamped_tx = std::clamp((int)set_num_channels_command.num_tx(), 3, 18);
  char buf[64];
  snprintf(buf, sizeof(buf), "Set Num Channels Command: num_rx=%d, num_tx=%d", clamped_rx, clamped_tx);
  this->comm.send_info<64>(buf);
  
  MtchResCode res = this->mtch->write_register(0x00, 0x01, (uint8_t*)&clamped_rx, 1);
  if (res != MtchResCode::SUCCESS) {
    this->mtch->handle_error(res);
    return;
  }
  res = this->mtch->write_register(0x00, 0x02, (uint8_t*)&clamped_tx, 1);
  if (res != MtchResCode::SUCCESS) {
    this->mtch->handle_error(res);
    return;
  }
  this->comm.send_info<34>("Set num_rx and num_tx sucessfully");
  uint16_t rx_scaling_coe = SCALING_COEFFICIENTS[clamped_rx - 3];
  uint16_t tx_scaling_coe = SCALING_COEFFICIENTS[clamped_tx - 3];
  snprintf(buf, sizeof(buf), "RX Scaling Coeff: %d, TX Scaling Coeff: %d", rx_scaling_coe, tx_scaling_coe);
  this->comm.send_info<64>(buf);
  
  res = this->mtch->write_register(0x00, 0x04, (uint8_t*)&rx_scaling_coe, 2);
  if (res != MtchResCode::SUCCESS) {
    this->mtch->handle_error(res);
    return;
  }

  res = this->mtch->write_register(0x00, 0x06, (uint8_t*)&tx_scaling_coe, 2);
  if (res != MtchResCode::SUCCESS) {
    this->mtch->handle_error(res);
    return;
  }

  this->comm.send_info<34>("Set scaling coefficients sucessfully"); 
  this->mtch->scan_baseline();
  this->mtch->enable_touch(true);
}