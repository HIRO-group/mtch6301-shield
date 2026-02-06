/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: common.proto
 */

// This file is generated. Please do not edit!
#ifndef COMMON_H
#define COMMON_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions
#include "commands.h"
#include "data.h"

namespace proto {

class Command final: public ::EmbeddedProto::MessageInterface
{
  public:
    Command() = default;
    Command(const Command& rhs )
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::TEST_COMMAND:
          set_test_command(rhs.get_test_command());
          break;

        case FieldNumber::SET_NUM_CHANNELS_COMMAND:
          set_set_num_channels_command(rhs.get_set_num_channels_command());
          break;

        default:
          break;
      }

    }

    Command(const Command&& rhs ) noexcept
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::TEST_COMMAND:
          set_test_command(rhs.get_test_command());
          break;

        case FieldNumber::SET_NUM_CHANNELS_COMMAND:
          set_set_num_channels_command(rhs.get_set_num_channels_command());
          break;

        default:
          break;
      }

    }

    ~Command() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TEST_COMMAND = 1,
      SET_NUM_CHANNELS_COMMAND = 2
    };

    Command& operator=(const Command& rhs)
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::TEST_COMMAND:
          set_test_command(rhs.get_test_command());
          break;

        case FieldNumber::SET_NUM_CHANNELS_COMMAND:
          set_set_num_channels_command(rhs.get_set_num_channels_command());
          break;

        default:
          break;
      }

      return *this;
    }

    Command& operator=(const Command&& rhs) noexcept
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::TEST_COMMAND:
          set_test_command(rhs.get_test_command());
          break;

        case FieldNumber::SET_NUM_CHANNELS_COMMAND:
          set_set_num_channels_command(rhs.get_set_num_channels_command());
          break;

        default:
          break;
      }

      return *this;
    }

    FieldNumber get_which_payload() const { return which_payload_; }

    static constexpr char const* TEST_COMMAND_NAME = "test_command";
    inline bool has_test_command() const
    {
      return FieldNumber::TEST_COMMAND == which_payload_;
    }
    inline void clear_test_command()
    {
      if(FieldNumber::TEST_COMMAND == which_payload_)
      {
        which_payload_ = FieldNumber::NOT_SET;
        payload_.test_command_.~TestCommand();
      }
    }
    inline void set_test_command(const TestCommand& value)
    {
      if(FieldNumber::TEST_COMMAND != which_payload_)
      {
        init_payload(FieldNumber::TEST_COMMAND);
      }
      payload_.test_command_ = value;
    }
    inline void set_test_command(const TestCommand&& value)
    {
      if(FieldNumber::TEST_COMMAND != which_payload_)
      {
        init_payload(FieldNumber::TEST_COMMAND);
      }
      payload_.test_command_ = value;
    }
    inline TestCommand& mutable_test_command()
    {
      if(FieldNumber::TEST_COMMAND != which_payload_)
      {
        init_payload(FieldNumber::TEST_COMMAND);
      }
      return payload_.test_command_;
    }
    inline const TestCommand& get_test_command() const { return payload_.test_command_; }
    inline const TestCommand& test_command() const { return payload_.test_command_; }

    static constexpr char const* SET_NUM_CHANNELS_COMMAND_NAME = "set_num_channels_command";
    inline bool has_set_num_channels_command() const
    {
      return FieldNumber::SET_NUM_CHANNELS_COMMAND == which_payload_;
    }
    inline void clear_set_num_channels_command()
    {
      if(FieldNumber::SET_NUM_CHANNELS_COMMAND == which_payload_)
      {
        which_payload_ = FieldNumber::NOT_SET;
        payload_.set_num_channels_command_.~SetNumChannelsCommand();
      }
    }
    inline void set_set_num_channels_command(const SetNumChannelsCommand& value)
    {
      if(FieldNumber::SET_NUM_CHANNELS_COMMAND != which_payload_)
      {
        init_payload(FieldNumber::SET_NUM_CHANNELS_COMMAND);
      }
      payload_.set_num_channels_command_ = value;
    }
    inline void set_set_num_channels_command(const SetNumChannelsCommand&& value)
    {
      if(FieldNumber::SET_NUM_CHANNELS_COMMAND != which_payload_)
      {
        init_payload(FieldNumber::SET_NUM_CHANNELS_COMMAND);
      }
      payload_.set_num_channels_command_ = value;
    }
    inline SetNumChannelsCommand& mutable_set_num_channels_command()
    {
      if(FieldNumber::SET_NUM_CHANNELS_COMMAND != which_payload_)
      {
        init_payload(FieldNumber::SET_NUM_CHANNELS_COMMAND);
      }
      return payload_.set_num_channels_command_;
    }
    inline const SetNumChannelsCommand& get_set_num_channels_command() const { return payload_.set_num_channels_command_; }
    inline const SetNumChannelsCommand& set_num_channels_command() const { return payload_.set_num_channels_command_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      switch(which_payload_)
      {
        case FieldNumber::TEST_COMMAND:
          if(has_test_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = payload_.test_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TEST_COMMAND), buffer, true);
          }
          break;

        case FieldNumber::SET_NUM_CHANNELS_COMMAND:
          if(has_set_num_channels_command() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = payload_.set_num_channels_command_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SET_NUM_CHANNELS_COMMAND), buffer, true);
          }
          break;

        default:
          break;
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::TEST_COMMAND:
          case FieldNumber::SET_NUM_CHANNELS_COMMAND:
            return_value = deserialize_payload(id_tag, buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_payload();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TEST_COMMAND:
          name = TEST_COMMAND_NAME;
          break;
        case FieldNumber::SET_NUM_CHANNELS_COMMAND:
          name = SET_NUM_CHANNELS_COMMAND_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = to_string_payload(left_chars, indent_level + 2, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:



      FieldNumber which_payload_ = FieldNumber::NOT_SET;
      union payload
      {
        payload() {}
        ~payload() {}
        TestCommand test_command_;
        SetNumChannelsCommand set_num_channels_command_;
      };
      payload payload_;

      void init_payload(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_payload_)
        {
          // First delete the old object in the oneof.
          clear_payload();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::TEST_COMMAND:
            new(&payload_.test_command_) TestCommand;
            break;

          case FieldNumber::SET_NUM_CHANNELS_COMMAND:
            new(&payload_.set_num_channels_command_) SetNumChannelsCommand;
            break;

          default:
            break;
         }

         which_payload_ = field_id;
      }

      void clear_payload()
      {
        switch(which_payload_)
        {
          case FieldNumber::TEST_COMMAND:
            ::EmbeddedProto::destroy_at(&payload_.test_command_);
            break;
          case FieldNumber::SET_NUM_CHANNELS_COMMAND:
            ::EmbeddedProto::destroy_at(&payload_.set_num_channels_command_);
            break;
          default:
            break;
        }
        which_payload_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_payload(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_payload_)
        {
          init_payload(field_id);
        }

        switch(which_payload_)
        {
          case FieldNumber::TEST_COMMAND:
            return_value = payload_.test_command_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::SET_NUM_CHANNELS_COMMAND:
            return_value = payload_.set_num_channels_command_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_payload();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_payload(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_payload_)
        {
          case FieldNumber::TEST_COMMAND:
            left_chars = payload_.test_command_.to_string(left_chars, indent_level, TEST_COMMAND_NAME, first_field);
            break;
          case FieldNumber::SET_NUM_CHANNELS_COMMAND:
            left_chars = payload_.set_num_channels_command_.to_string(left_chars, indent_level, SET_NUM_CHANNELS_COMMAND_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

template<
    uint32_t Data_info_packet_InfoMessagePacket_message_LENGTH
>
class Data final: public ::EmbeddedProto::MessageInterface
{
  public:
    Data() = default;
    Data(const Data& rhs )
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::INFO_PACKET:
          set_info_packet(rhs.get_info_packet());
          break;

        case FieldNumber::TOUCH_PACKET:
          set_touch_packet(rhs.get_touch_packet());
          break;

        default:
          break;
      }

    }

    Data(const Data&& rhs ) noexcept
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::INFO_PACKET:
          set_info_packet(rhs.get_info_packet());
          break;

        case FieldNumber::TOUCH_PACKET:
          set_touch_packet(rhs.get_touch_packet());
          break;

        default:
          break;
      }

    }

    ~Data() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      INFO_PACKET = 1,
      TOUCH_PACKET = 2
    };

    Data& operator=(const Data& rhs)
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::INFO_PACKET:
          set_info_packet(rhs.get_info_packet());
          break;

        case FieldNumber::TOUCH_PACKET:
          set_touch_packet(rhs.get_touch_packet());
          break;

        default:
          break;
      }

      return *this;
    }

    Data& operator=(const Data&& rhs) noexcept
    {
      if(rhs.get_which_payload() != which_payload_)
      {
        // First delete the old object in the oneof.
        clear_payload();
      }

      switch(rhs.get_which_payload())
      {
        case FieldNumber::INFO_PACKET:
          set_info_packet(rhs.get_info_packet());
          break;

        case FieldNumber::TOUCH_PACKET:
          set_touch_packet(rhs.get_touch_packet());
          break;

        default:
          break;
      }

      return *this;
    }

    FieldNumber get_which_payload() const { return which_payload_; }

    static constexpr char const* INFO_PACKET_NAME = "info_packet";
    inline bool has_info_packet() const
    {
      return FieldNumber::INFO_PACKET == which_payload_;
    }
    inline void clear_info_packet()
    {
      if(FieldNumber::INFO_PACKET == which_payload_)
      {
        which_payload_ = FieldNumber::NOT_SET;
        payload_.info_packet_.~InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>();
      }
    }
    inline void set_info_packet(const InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>& value)
    {
      if(FieldNumber::INFO_PACKET != which_payload_)
      {
        init_payload(FieldNumber::INFO_PACKET);
      }
      payload_.info_packet_ = value;
    }
    inline void set_info_packet(const InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>&& value)
    {
      if(FieldNumber::INFO_PACKET != which_payload_)
      {
        init_payload(FieldNumber::INFO_PACKET);
      }
      payload_.info_packet_ = value;
    }
    inline InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>& mutable_info_packet()
    {
      if(FieldNumber::INFO_PACKET != which_payload_)
      {
        init_payload(FieldNumber::INFO_PACKET);
      }
      return payload_.info_packet_;
    }
    inline const InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>& get_info_packet() const { return payload_.info_packet_; }
    inline const InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>& info_packet() const { return payload_.info_packet_; }

    static constexpr char const* TOUCH_PACKET_NAME = "touch_packet";
    inline bool has_touch_packet() const
    {
      return FieldNumber::TOUCH_PACKET == which_payload_;
    }
    inline void clear_touch_packet()
    {
      if(FieldNumber::TOUCH_PACKET == which_payload_)
      {
        which_payload_ = FieldNumber::NOT_SET;
        payload_.touch_packet_.~TouchPacket();
      }
    }
    inline void set_touch_packet(const TouchPacket& value)
    {
      if(FieldNumber::TOUCH_PACKET != which_payload_)
      {
        init_payload(FieldNumber::TOUCH_PACKET);
      }
      payload_.touch_packet_ = value;
    }
    inline void set_touch_packet(const TouchPacket&& value)
    {
      if(FieldNumber::TOUCH_PACKET != which_payload_)
      {
        init_payload(FieldNumber::TOUCH_PACKET);
      }
      payload_.touch_packet_ = value;
    }
    inline TouchPacket& mutable_touch_packet()
    {
      if(FieldNumber::TOUCH_PACKET != which_payload_)
      {
        init_payload(FieldNumber::TOUCH_PACKET);
      }
      return payload_.touch_packet_;
    }
    inline const TouchPacket& get_touch_packet() const { return payload_.touch_packet_; }
    inline const TouchPacket& touch_packet() const { return payload_.touch_packet_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      switch(which_payload_)
      {
        case FieldNumber::INFO_PACKET:
          if(has_info_packet() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = payload_.info_packet_.serialize_with_id(static_cast<uint32_t>(FieldNumber::INFO_PACKET), buffer, true);
          }
          break;

        case FieldNumber::TOUCH_PACKET:
          if(has_touch_packet() && (::EmbeddedProto::Error::NO_ERRORS == return_value))
          {
            return_value = payload_.touch_packet_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TOUCH_PACKET), buffer, true);
          }
          break;

        default:
          break;
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::INFO_PACKET:
          case FieldNumber::TOUCH_PACKET:
            return_value = deserialize_payload(id_tag, buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_payload();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::INFO_PACKET:
          name = INFO_PACKET_NAME;
          break;
        case FieldNumber::TOUCH_PACKET:
          name = TOUCH_PACKET_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#endif

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = to_string_payload(left_chars, indent_level + 2, true);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:



      FieldNumber which_payload_ = FieldNumber::NOT_SET;
      union payload
      {
        payload() {}
        ~payload() {}
        InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH> info_packet_;
        TouchPacket touch_packet_;
      };
      payload payload_;

      void init_payload(const FieldNumber field_id)
      {
        if(FieldNumber::NOT_SET != which_payload_)
        {
          // First delete the old object in the oneof.
          clear_payload();
        }

        // C++11 unions only support nontrivial members when you explicitly call the placement new statement.
        switch(field_id)
        {
          case FieldNumber::INFO_PACKET:
            new(&payload_.info_packet_) InfoMessagePacket<Data_info_packet_InfoMessagePacket_message_LENGTH>;
            break;

          case FieldNumber::TOUCH_PACKET:
            new(&payload_.touch_packet_) TouchPacket;
            break;

          default:
            break;
         }

         which_payload_ = field_id;
      }

      void clear_payload()
      {
        switch(which_payload_)
        {
          case FieldNumber::INFO_PACKET:
            ::EmbeddedProto::destroy_at(&payload_.info_packet_);
            break;
          case FieldNumber::TOUCH_PACKET:
            ::EmbeddedProto::destroy_at(&payload_.touch_packet_);
            break;
          default:
            break;
        }
        which_payload_ = FieldNumber::NOT_SET;
      }

      ::EmbeddedProto::Error deserialize_payload(const FieldNumber field_id, 
                                    ::EmbeddedProto::ReadBufferInterface& buffer,
                                    const ::EmbeddedProto::WireFormatter::WireType wire_type)
      {
        ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
        
        if(field_id != which_payload_)
        {
          init_payload(field_id);
        }

        switch(which_payload_)
        {
          case FieldNumber::INFO_PACKET:
            return_value = payload_.info_packet_.deserialize_check_type(buffer, wire_type);
            break;
          case FieldNumber::TOUCH_PACKET:
            return_value = payload_.touch_packet_.deserialize_check_type(buffer, wire_type);
            break;
          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS != return_value)
        {
          clear_payload();
        }
        return return_value;
      }

#ifdef MSG_TO_STRING 
      ::EmbeddedProto::string_view to_string_payload(::EmbeddedProto::string_view& str, const uint32_t indent_level, const bool first_field) const
      {
        ::EmbeddedProto::string_view left_chars = str;

        switch(which_payload_)
        {
          case FieldNumber::INFO_PACKET:
            left_chars = payload_.info_packet_.to_string(left_chars, indent_level, INFO_PACKET_NAME, first_field);
            break;
          case FieldNumber::TOUCH_PACKET:
            left_chars = payload_.touch_packet_.to_string(left_chars, indent_level, TOUCH_PACKET_NAME, first_field);
            break;
          default:
            break;
        }

        return left_chars;
      }

#endif // End of MSG_TO_STRING
};

} // End of namespace proto
#endif // COMMON_H