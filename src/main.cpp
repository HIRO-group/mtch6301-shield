#include <gpio_defs.hpp>
#include <mtch.hpp>
#include <communication/serial.hpp>
#include <generated/common.h>
#include <command_manager.hpp>

#include <Arduino.h>

int count = 0;

CommandManager command_manager;
SerialCommunication comm(Serial, command_manager);
Mtch* mtch;


void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, LOW);

  comm.init();
  delay(5000);

  comm.send_info<16>("Initializing...");
  esp_err_t res = i2c_master_init();
  mtch = new Mtch(comm);

  mtch->init();
  comm.send_info<5>("Ready");
}

void loop() {
  comm.poll_recv();
  mtch->poll_sensor();
}