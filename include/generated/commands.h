/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: commands.proto
 */

// This file is generated. Please do not edit!
#ifndef COMMANDS_H
#define COMMANDS_H

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

namespace proto {

class SetNumChannelsCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    SetNumChannelsCommand() = default;
    SetNumChannelsCommand(const SetNumChannelsCommand& rhs )
    {
      set_num_rx(rhs.get_num_rx());
      set_num_tx(rhs.get_num_tx());
    }

    SetNumChannelsCommand(const SetNumChannelsCommand&& rhs ) noexcept
    {
      set_num_rx(rhs.get_num_rx());
      set_num_tx(rhs.get_num_tx());
    }

    ~SetNumChannelsCommand() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      NUM_RX = 1,
      NUM_TX = 2
    };

    SetNumChannelsCommand& operator=(const SetNumChannelsCommand& rhs)
    {
      set_num_rx(rhs.get_num_rx());
      set_num_tx(rhs.get_num_tx());
      return *this;
    }

    SetNumChannelsCommand& operator=(const SetNumChannelsCommand&& rhs) noexcept
    {
      set_num_rx(rhs.get_num_rx());
      set_num_tx(rhs.get_num_tx());
      return *this;
    }

    static constexpr char const* NUM_RX_NAME = "num_rx";
    inline void clear_num_rx() { num_rx_.clear(); }
    inline void set_num_rx(const int32_t& value) { num_rx_ = value; }
    inline void set_num_rx(const int32_t&& value) { num_rx_ = value; }
    inline int32_t& mutable_num_rx() { return num_rx_.get(); }
    inline const int32_t& get_num_rx() const { return num_rx_.get(); }
    inline int32_t num_rx() const { return num_rx_.get(); }

    static constexpr char const* NUM_TX_NAME = "num_tx";
    inline void clear_num_tx() { num_tx_.clear(); }
    inline void set_num_tx(const int32_t& value) { num_tx_ = value; }
    inline void set_num_tx(const int32_t&& value) { num_tx_ = value; }
    inline int32_t& mutable_num_tx() { return num_tx_.get(); }
    inline const int32_t& get_num_tx() const { return num_tx_.get(); }
    inline int32_t num_tx() const { return num_tx_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != num_rx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = num_rx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NUM_RX), buffer, false);
      }

      if((0 != num_tx_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = num_tx_.serialize_with_id(static_cast<uint32_t>(FieldNumber::NUM_TX), buffer, false);
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
          case FieldNumber::NUM_RX:
            return_value = num_rx_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NUM_TX:
            return_value = num_tx_.deserialize_check_type(buffer, wire_type);
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
      clear_num_rx();
      clear_num_tx();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::NUM_RX:
          name = NUM_RX_NAME;
          break;
        case FieldNumber::NUM_TX:
          name = NUM_TX_NAME;
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

      left_chars = num_rx_.to_string(left_chars, indent_level + 2, NUM_RX_NAME, true);
      left_chars = num_tx_.to_string(left_chars, indent_level + 2, NUM_TX_NAME, false);
  
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


      EmbeddedProto::int32 num_rx_ = 0;
      EmbeddedProto::int32 num_tx_ = 0;

};

class TestCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    TestCommand() = default;
    TestCommand(const TestCommand& rhs )
    {
    }

    TestCommand(const TestCommand&& rhs ) noexcept
    {
    }

    ~TestCommand() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
    };

    TestCommand& operator=(const TestCommand& rhs)
    {
      return *this;
    }

    TestCommand& operator=(const TestCommand&& rhs) noexcept
    {
      return *this;
    }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

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

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
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



};

} // End of namespace proto
#endif // COMMANDS_H