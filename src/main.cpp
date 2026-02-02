#include <gpio_defs.hpp>
#include <mtch.hpp>

#include <Arduino.h>

void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);
  attachInterrupt(MTCH_INT, i2c_master_isr, RISING);

  Serial.begin(115200);
  delay(2000);
  Serial.println("Starting");
  esp_err_t res = i2c_master_init();
  MtchCommands::mtch_init();
  // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(false)));
  // delay(500);
  // Serial.println(mtch_res_to_string(MtchCommands::mtch_enable_touch(true)));

}

void loop() {
  digitalWrite(STATUS_LED, HIGH);
  delay(1000);
  digitalWrite(STATUS_LED, LOW);
  delay(1000);

}