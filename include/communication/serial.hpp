#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <WriteBufferFixedSize.h>
#include <MessageInterface.h>

#include <generated/common.h>
#include <command_manager.hpp>

class SerialCommunication {
  public:
    SerialCommunication(Stream& port, CommandManager& command_manager) : 
      port(port), command_manager(command_manager) {}

    void init();
    void poll_recv();

    template<uint32_t N>
    void send_info(const char* message_text) {
      proto::Data<N> data;
      data.mutable_info_packet().mutable_message().set(message_text);
      this->send(data);
    }

  private:
    Stream& port;
    CommandManager& command_manager;

    void send_raw(const uint8_t* data, size_t len);

    template<uint32_t N>
    void send(const proto::Data<N>& data) {
        ::EmbeddedProto::WriteBufferFixedSize<512> buffer;

        if (data.serialize(buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
            this->send_raw(buffer.get_data(), buffer.get_size());
        }
    }
};
