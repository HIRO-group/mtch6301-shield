#pragma once
#include <Arduino.h>
#include <esp_err.h>
#include <driver/i2c.h>
#include <cstdint>
#include <unordered_map>
#include <array>

#include <communication/serial.hpp>


#define MTCH_I2C_ADDR 0x25

#define I2C_FREQUENCY 400000
#define I2C_PORT I2C_NUM_0
#define I2C_TIMEOUT_TICKS pdMS_TO_TICKS(100)

constexpr std::array<uint8_t, 18> MTCH_TX_MAP = {2, 3, 6, 13, 4, 7, 28, 29, 30, 14, 15, 16, 5, 8, 31, 32, 33, 34};
constexpr std::array<uint8_t, 13> MTCH_RX_MAP = {8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 10, 11, 12};

void IRAM_ATTR i2c_master_isr();

enum MtchResCode : uint8_t {
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
    { I2C_ERROR, "I2C_ERROR" }
};

inline const char* mtch_res_to_string(uint8_t res) {
    auto it = mtch_res_map.find(res);
    return (it != mtch_res_map.end()) ? it->second : "UNKNOWN_MTCH_RES_CODE";
}

esp_err_t i2c_master_init(void);

class Mtch {
  public:
    Mtch(SerialCommunication& comm) : comm(comm) {
      instance = this;
      attachInterrupt(MTCH_INT, int_isr, RISING);
    }
    
    MtchResCode write_register(uint8_t reg_index, uint8_t offset_start, const uint8_t* value, size_t len);
    MtchResCode read_register(uint8_t reg_index, uint8_t offset_start, uint8_t* res, size_t len);
    MtchResCode enable_touch(bool enable);
    MtchResCode scan_baseline();
    MtchResCode sleep();
    MtchResCode device_id(uint8_t* device_id);
    MtchResCode write_nvram();
    MtchResCode init();

    void reset();
    bool ping();
  private:
    SerialCommunication& comm;
    volatile bool mtch_ready = false;
    static Mtch* instance;
    static void IRAM_ATTR int_isr();
    
    void handle_error(MtchResCode error);
    void wait_for_ready();
    MtchResCode read_single_register(uint8_t index, uint8_t offset, uint8_t* res);
    MtchResCode write_single_register(uint8_t index, uint8_t offset, const uint8_t* value);
};