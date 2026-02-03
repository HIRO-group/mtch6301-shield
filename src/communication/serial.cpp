#include <communication/serial.hpp>
#include <Arduino.h>
#include <MessageInterface.h>
#include <WriteBufferFixedSize.h>

void SerialCommunication::init() {
  Serial.begin(115200);
}

void SerialCommunication::send_raw(const uint8_t* data, size_t len) {
  Serial.write(data, len);
}

void SerialCommunication::poll_recv() {
  // if (Serial.available()) {
  //   Serial.read();
  // }
}



