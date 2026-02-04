#include <gpio_defs.hpp>
#include <mtch.hpp>
#include <communication/serial.hpp>
#include <generated/common.h>

#include <Arduino.h>

int count = 0;

void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);
  attachInterrupt(MTCH_INT, i2c_master_isr, RISING);
  digitalWrite(STATUS_LED, LOW);

  SerialCommunication::init();
  delay(5000);

  SerialCommunication::send_info<11>("Starting...\n");

  esp_err_t res = i2c_master_init();
  MtchCommands::mtch_init();

  SerialCommunication::send_info<4>("Done\n");

  // // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(false)));
  // delay(500);
  // // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(true)));

}

void loop() {
  SerialCommunication::poll_recv();
}