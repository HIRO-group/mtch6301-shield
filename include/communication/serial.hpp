#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <WriteBufferFixedSize.h>
#include <MessageInterface.h>

class SerialCommunication {
  private:
    static void send_raw(const uint8_t* data, size_t len);
  public:
    static void init();

    template<typename T>
    static void send(const T& message) {
        ::EmbeddedProto::WriteBufferFixedSize<512> buffer;

        if (message.serialize(buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
            send_raw(buffer.get_data(), buffer.get_size());
        }
    }
    
    static void poll_recv();
};