#include <gpio_defs.hpp>
#include <mtch.hpp>
#include <communication/serial.hpp>
#include <generated/common.h>
#include <command_manager.hpp>

#include <Arduino.h>

int count = 0;

CommandManager command_manager;
SerialCommunication comm(Serial, command_manager);


void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, LOW);

  comm.init();
  delay(5000);

  comm.send_info<11>("Starting...\n");

  esp_err_t res = i2c_master_init();
  // Mtch::init();
  Mtch mtch(comm);
  mtch.init();


  comm.send_info<4>("Done\n");

  // // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(false)));
  // delay(500);
  // // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(true)));

}

void loop() {
  comm.poll_recv();
}