#pragma once
#include <esp_err.h>
#include <driver/i2c.h>

#include <cstdint>
#include <unordered_map>

#define MTCH_I2C_ADDR 0x25

#define I2C_FREQUENCY 400000
#define I2C_PORT I2C_NUM_0
#define I2C_TIMEOUT_TICKS pdMS_TO_TICKS(100)

enum MTCH_RES_CODE : uint8_t {
  SUCCESS = 0x00,
  PARAM_OUT_OF_RANGE = 0x80,
  TIMEOUT = 0xFE,
  UNRECONGNIZED_CMD = 0xFF,
  INVALID_PARAM = 0xFD,
  MISSING_OR_EXTRA_PARAMETER = 0xFC,
  I2C_ERROR = 0xAA
};

static const std::unordered_map<uint8_t, const char*> mtch_res_map = {
    { SUCCESS, "SUCCESS" },
    { PARAM_OUT_OF_RANGE, "PARAM_OUT_OF_RANGE" },
    { MISSING_OR_EXTRA_PARAMETER, "MISSING_OR_EXTRA_PARAMETER" },
    { INVALID_PARAM, "INVALID_PARAM" },
    { TIMEOUT, "TIMEOUT" },
    { UNRECONGNIZED_CMD, "UNRECONGNIZED_CMD" },
};

inline const char* mtch_res_to_string(uint8_t res) {
    auto it = mtch_res_map.find(res);
    return (it != mtch_res_map.end()) ? it->second : "UNKNOWN_MTCH_RES_CODE";
}


esp_err_t i2c_master_init(void);

esp_err_t mtch_write_register(uint8_t reg_index, uint8_t offset_start, const uint8_t* value, size_t len);
esp_err_t mtch_read_register(uint8_t reg_index, uint8_t offset_start, uint8_t* res, size_t len);
esp_err_t mtch_enable_touch(bool enable);
esp_err_t mtch_scan_baseline();
esp_err_t mtch_sleep();
MTCH_RES_CODE mtch_device_id(uint8_t* device_id);
esp_err_t mtch_write_nvram(uint8_t reg_index, uint8_t offset_start, const uint8_t* value, size_t len);

void mtch_reset();
bool mtch_ping();