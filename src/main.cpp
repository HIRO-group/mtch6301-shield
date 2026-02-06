#include <gpio_defs.hpp>
#include <mtch.hpp>
#include <communication/serial.hpp>
#include <generated/common.h>
#include <command_manager.hpp>

#include <Arduino.h>

int count = 0;

SerialCommunication comm(Serial);
Mtch* mtch;
CommandManager* command_manager;


void setup() {
  pinMode(MTCH_RESET, OUTPUT);
  pinMode(MTCH_INT, INPUT);
  pinMode(STATUS_LED, OUTPUT);
  digitalWrite(STATUS_LED, LOW);

  Serial.begin(115200);
  comm.init();
  delay(5000);

  comm.send_info<16>("Initializing...");
  esp_err_t res = i2c_master_init();
  mtch = new Mtch(comm);
  command_manager = new CommandManager(comm, mtch);

  mtch->init();
  comm.send_info<5>("Ready");
}

void loop() {
  comm.poll_recv(*command_manager);
  mtch->poll_sensor();
}