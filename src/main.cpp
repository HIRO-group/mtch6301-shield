#include <gpio_defs.hpp>
#include <mtch.hpp>
#include <communication/serial.hpp>
#include <generated/common.h>

#include <Arduino.h>

void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);
  attachInterrupt(MTCH_INT, i2c_master_isr, RISING);
  SerialCommunication::init();
  delay(1000);

  proto::Envelope<32> env;
  auto &info = env.mutable_info_packet();
  info.mutable_name().set("Hello, World!");
  SerialCommunication::send(env);

  esp_err_t res = i2c_master_init();
  MtchCommands::mtch_init();
  // // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(false)));
  // delay(500);
  // // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(true)));

}

void loop() {
  digitalWrite(STATUS_LED, HIGH);
  delay(1000);
  digitalWrite(STATUS_LED, LOW);
  delay(1000);

}