#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <WriteBufferFixedSize.h>
#include <MessageInterface.h>
#include <Arduino.h>

#include <generated/common.h>

class CommandManager;
class SerialCommunication {
  public:
    SerialCommunication(Stream& port) : 
      port(port) {}

    void init();
    void poll_recv(CommandManager& command_manager);

    template<uint32_t N>
    void send(const proto::Data<N>& data) {
        ::EmbeddedProto::WriteBufferFixedSize<512> buffer;

        if (data.serialize(buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
            this->send_raw(buffer.get_data(), buffer.get_size());
        }
    }

    template<uint32_t N>
    void send_info(const char* message_text) {
      proto::Data<N> data;
      data.mutable_info_packet().mutable_message().set(message_text);
      this->send(data);
    }

  private:
    Stream& port;

    void send_raw(const uint8_t* data, size_t len);
};
