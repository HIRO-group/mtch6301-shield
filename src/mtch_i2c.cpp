#include <mtch_i2c.hpp>
#include <gpio_defs.hpp>

#include <driver/i2c.h>
#include <Arduino.h>

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

MTCH_RES_CODE mtch_device_id(uint8_t* device_id) {
  uint8_t payload[3] = {0x55, 0x01, 0x83};
  uint8_t resp[9];
  esp_err_t ret = i2c_master_write_to_device(I2C_PORT, MTCH_I2C_ADDR, payload, sizeof(payload), I2C_TIMEOUT_TICKS);
  if (ret != ESP_OK) {
    return MTCH_RES_CODE::I2C_ERROR;
  }

  vTaskDelay(pdMS_TO_TICKS(2));
  if (i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, resp, sizeof(resp), I2C_TIMEOUT_TICKS) != ESP_OK) {
    return MTCH_RES_CODE::I2C_ERROR;
  } 

  device_id[0] = resp[6];
  device_id[1] = resp[7];
  device_id[2] = resp[8];
  return static_cast<MTCH_RES_CODE>(resp[3]);
}

void mtch_reset() {
  digitalWrite(MTCH_RESET, LOW);
  delayMicroseconds(10);
  digitalWrite(MTCH_RESET, HIGH);
}

bool mtch_ping() {
  uint8_t test;
  esp_err_t res = i2c_master_read_from_device(I2C_PORT, MTCH_I2C_ADDR, &test, 1, pdMS_TO_TICKS(100));
  if (res != ESP_OK) {
    Serial.printf("ESP ERROR: %s\n", esp_err_to_name(res));
    return false;
  }
  return true;

}