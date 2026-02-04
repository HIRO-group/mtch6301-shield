#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <WriteBufferFixedSize.h>
#include <MessageInterface.h>
#include <generated/common.h>

class SerialCommunication {
  private:
    static void send_raw(const uint8_t* data, size_t len);

    template<uint32_t N>
    static void send(const proto::Data<N>& data) {
        ::EmbeddedProto::WriteBufferFixedSize<512> buffer;

        if (data.serialize(buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
            send_raw(buffer.get_data(), buffer.get_size());
        }
    }
  public:
    static void init();
    static void poll_recv();

    template<uint32_t N>
    static void send_info(const char* message_text) {
      proto::Data<N> data;
      data.mutable_info_packet().mutable_message().set(message_text);
      SerialCommunication::send(data);
    }
};