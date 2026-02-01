#include <gpio_defs.hpp>
#include <mtch_i2c.hpp>

#include <Arduino.h>

void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);

  Serial.begin(115200);
  delay(2000);
  Serial.println("Starting");
  esp_err_t res = i2c_master_init();
  mtch_reset();
  delay(100);
  Serial.println(mtch_ping());
  

}

void loop() {
  digitalWrite(STATUS_LED, HIGH);
  delay(1000);
  digitalWrite(STATUS_LED, LOW);
  delay(1000);

}