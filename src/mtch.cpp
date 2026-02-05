#include <driver/i2c.h>
#include <Arduino.h>

#include <mtch.hpp>
#include <gpio_defs.hpp>
#include <communication/serial.hpp>

esp_err_t i2c_master_init(void) {
  i2c_config_t conf = {};
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = (gpio_num_t)SDA_PIN;
  conf.scl_io_num = (gpio_num_t)SCL_PIN;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = I2C_FREQUENCY;
  conf.clk_flags = I2C_SCLK_SRC_FLAG_FOR_NOMAL;

  esp_err_t res = i2c_param_config(I2C_PORT, &conf);
  if (res != ESP_OK) {
    return res;
  }

  return i2c_driver_install(I2C_PORT, conf.mode, 0, 0, 0);
}

Mtch* Mtch::instance = nullptr;
SemaphoreHandle_t Mtch::int_isr_lock = nullptr;

void IRAM_ATTR Mtch::int_isr() {
  if (instance != nullptr && int_isr_lock != nullptr) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    xSemaphoreGiveFromISR(int_isr_lock, &xHigherPriorityTaskWoken);
    
    if (xHigherPriorityTaskWoken) {
        portYIELD_FROM_ISR();
    }
  }
}

void Mtch::wait_for_ready() {
  if (xSemaphoreTake(int_isr_lock, pdMS_TO_TICKS(100)) == pdFALSE) {
    this->comm.send_info<32>("Wait Ready Timeout");
  }
}

void Mtch::handle_error(MtchResCode error) {
  char buf[32];
  snprintf(buf, sizeof(buf), "Chip Error: %s", mtch_res_to_string(error));
  this->comm.send_info<32>(buf);
}

MtchResCode Mtch::read_single_register(uint8_t index, uint8_t offset, uint8_t* res) {
  uint8_t payload[5] = {0x55, 0x03, 0x16, index, offset};
  uint8_t resp[6];

  esp_err_t ret = i2c_master_write_to_device(
    I2C_PORT,
    MTCH_I2C_ADDR,
    payload,
    sizeof(payload),
    I2C_TIMEOUT_TICKS
  );

  if (ret != ESP_OK) {
    char buf[32];
    snprintf(buf, sizeof(buf), "I2C ERROR: %s", esp_err_to_name(ret));
    this->comm.send_info<32>(buf);
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  ret = i2c_master_read_from_device(
    I2C_PORT,
    MTCH_I2C_ADDR,
    resp,
    sizeof(resp),
    I2C_TIMEOUT_TICKS
  );
  if (ret != ESP_OK) {
    char buf[32];
    snprintf(buf, sizeof(buf), "I2C ERROR: %s", esp_err_to_name(ret));
    this->comm.send_info<32>(buf);
    return MtchResCode::I2C_ERROR;
  }

  *res = resp[5];

  return static_cast<MtchResCode>(resp[3]);
}

MtchResCode Mtch::read_register(uint8_t reg_index, uint8_t offset_start, uint8_t* res, size_t len) {
  for (int i = 0; i < len; i++) {
    MtchResCode ret = this->read_single_register(reg_index, offset_start + i, &res[i]);
    if (ret != MtchResCode::SUCCESS) {
      return ret;
    }
  }

  return MtchResCode::SUCCESS;
}

MtchResCode Mtch::write_single_register(uint8_t index, uint8_t offset, const uint8_t* value) {
  uint8_t payload[6] = {0x55, 0x04, 0x15, index, offset, *value};
  uint8_t resp[5];

  esp_err_t ret = i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS);
  if (ret != ESP_OK) {
    char buf[32];
    snprintf(buf, sizeof(buf), "I2C ERROR: %s", esp_err_to_name(ret));
    this->comm.send_info<32>(buf);
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  ret = i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS);
  if (ret != ESP_OK) {
    char buf[32];
    snprintf(buf, sizeof(buf), "I2C ERROR: %s", esp_err_to_name(ret));
    this->comm.send_info<32>(buf);

    return MtchResCode::I2C_ERROR;
  }

  return static_cast<MtchResCode>(resp[3]);
}

MtchResCode Mtch::write_register(uint8_t reg_index, uint8_t offset_start, const uint8_t* value, size_t len) {
  for (int i = 0; i < len; i++) {
    MtchResCode ret = this->write_single_register(reg_index, offset_start + i, &value[i]);
    if (ret != MtchResCode::SUCCESS) {
      return ret;
    }
  }

  return MtchResCode::SUCCESS;
}

MtchResCode Mtch::device_id(uint8_t* device_id) {
  uint8_t payload[3] = {0x55, 0x01, 0x83};
  uint8_t resp[9];
  if (i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  if (i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  } 

  device_id[0] = resp[6];
  device_id[1] = resp[7];
  device_id[2] = resp[8];
  return static_cast<MtchResCode>(resp[3]);
}

MtchResCode Mtch::enable_touch(bool enable) {
  uint8_t payload[3] = {0x55, 0x01, static_cast<uint8_t>(enable ? 0x01 : 0x00)};
  uint8_t resp[5];

  if (i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS) != ESP_OK) {
    this->comm.send_info<32>("I2C ERROR touch");
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  if (i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS) != ESP_OK) {
    this->comm.send_info<32>("I2C ERROR touch readback");
    return MtchResCode::I2C_ERROR;
  }

  return static_cast<MtchResCode>(resp[3]);
}

MtchResCode Mtch::scan_baseline() {
  uint8_t payload[3] = {0x55, 0x01, 0x14};
  uint8_t resp[5];
  if (i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  if (i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  }

  return static_cast<MtchResCode>(resp[3]);
}

MtchResCode Mtch::sleep() {
  uint8_t payload[3] = {0x55, 0x01, 0x18};
  uint8_t resp[5];

  if (i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS)) {
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  if (i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  }

  return static_cast<MtchResCode>(resp[3]);
}

MtchResCode Mtch::write_nvram() {
  uint8_t payload[3] = {0x55, 0x01, 0x17};
  uint8_t resp[5];
  if (i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  }

  this->wait_for_ready();
  if (i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MtchResCode::I2C_ERROR;
  }

  return static_cast<MtchResCode>(resp[3]);
}

void Mtch::reset() {
  digitalWrite(MTCH_RESET, LOW);
  delayMicroseconds(10);
  digitalWrite(MTCH_RESET, HIGH);
}

bool Mtch::ping() { 
  uint8_t test;
  esp_err_t res = i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, &test, 1, pdMS_TO_TICKS(100));
  if (res != ESP_OK) {
    char buf[32];
    snprintf(buf, sizeof(buf), "I2C ERROR: %s", esp_err_to_name(res));
    this->comm.send_info<32>(buf);
    return false;
  }
  return true;

}

MtchResCode Mtch::init() {
  this->reset();
  delay(100);
  this->enable_touch(false);

  uint8_t current_tx_pin_map[18];
  uint8_t current_rx_pin_map[13];
  MtchResCode ret = this->read_register(0x02, 0x00, current_tx_pin_map, sizeof(current_tx_pin_map));
  if (ret != MtchResCode::SUCCESS) {
    this->comm.send_info<35>("Failed to read MTCH NVRM pinmap tx");
    handle_error(ret);
    return ret;
  }

  ret = this->read_register(0x01, 0x00, current_rx_pin_map, sizeof(current_rx_pin_map));
  if (ret != MtchResCode::SUCCESS) {
    this->comm.send_info<35>("Failed to read MTCH NVRM pinmap rx");
    handle_error(ret);
    return ret;
  }

  bool should_write = false;
  for (int i = 0; i < sizeof(current_tx_pin_map); i++) {
    if (current_tx_pin_map[i] != MTCH_TX_MAP[i]) {
      should_write = true;
      char buf[64];
      snprintf(buf, sizeof(buf), "TX PIN MAP MISMATCH: %d != %d", current_tx_pin_map[i], MTCH_TX_MAP[i]);
      this->comm.send_info<64>(buf);
      break;
    }
  }

  for (int i = 0; i < sizeof(current_rx_pin_map); i++) {
    if (current_rx_pin_map[i] != MTCH_RX_MAP[i]) {
      should_write = true;
      char buf[64];
      snprintf(buf, sizeof(buf), "RX PIN MAP MISMATCH: %d != %d", current_rx_pin_map[i], MTCH_RX_MAP[i]);
      this->comm.send_info<64>(buf);
      break;
    }
  }


  if (should_write) {
    this->comm.send_info<32>("Updating MTCH NVRM pinmap");
    this->write_register(0x02, 0x00, MTCH_TX_MAP.data(), 18);
    this->write_register(0x01, 0x00, MTCH_RX_MAP.data(), 13);
    this->write_nvram();
  }

  this->enable_touch(true);
  MtchResCode res = this->scan_baseline();
  char buf[32];
  snprintf(buf, sizeof(buf), "Scan Baseline: %s", mtch_res_to_string(res));
  this->comm.send_info<32>(buf);
  return MtchResCode::SUCCESS;
}

void Mtch::poll_sensor() {}