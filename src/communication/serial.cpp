#include <communication/serial.hpp>
#include <Arduino.h>
#include <MessageInterface.h>
#include <WriteBufferFixedSize.h>
#include <ReadBufferFixedSize.h>

#include <command_manager.hpp>

void SerialCommunication::init() {
  // port.begin(115200);
}

void SerialCommunication::send_raw(const uint8_t* data, size_t len) {
  if (len == 0) return;

  uint16_t packet_len = static_cast<uint16_t>(len);
  size_t total_to_send = sizeof(packet_len) + len;

  while (port.availableForWrite() < total_to_send) {
      delay(1); 
  }

  port.write(reinterpret_cast<uint8_t*>(&packet_len), sizeof(packet_len));

  port.write(data, len);
}

void SerialCommunication::poll_recv(CommandManager& command_manager) {
    if (port.available() >= sizeof(uint16_t)) {
        uint16_t packet_len = 0;
        
        port.readBytes(reinterpret_cast<uint8_t*>(&packet_len), sizeof(packet_len));

        if (packet_len > 256) {
            return;
        }

        unsigned long timeout = millis() + 50; 
        while (port.available() < packet_len && millis() < timeout) {
            delay(1); 
        }

        if (port.available() >= packet_len) {
            EmbeddedProto::ReadBufferFixedSize<256> readBuffer;
            Serial.readBytes(readBuffer.get_data(), packet_len);
            readBuffer.set_bytes_written(packet_len);

            proto::Command cmd;

            if (cmd.deserialize(readBuffer) == ::EmbeddedProto::Error::NO_ERRORS) {
                command_manager.process_command(cmd);
            }
        }
    }
}


