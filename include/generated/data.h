/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: data.proto
 */

// This file is generated. Please do not edit!
#ifndef DATA_H
#define DATA_H

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

template<
    uint32_t InfoMessagePacket_message_LENGTH
>
class InfoMessagePacket final: public ::EmbeddedProto::MessageInterface
{
  public:
    InfoMessagePacket() = default;
    InfoMessagePacket(const InfoMessagePacket& rhs )
    {
      set_message(rhs.get_message());
    }

    InfoMessagePacket(const InfoMessagePacket&& rhs ) noexcept
    {
      set_message(rhs.get_message());
    }

    ~InfoMessagePacket() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      MESSAGE = 1
    };

    InfoMessagePacket& operator=(const InfoMessagePacket& rhs)
    {
      set_message(rhs.get_message());
      return *this;
    }

    InfoMessagePacket& operator=(const InfoMessagePacket&& rhs) noexcept
    {
      set_message(rhs.get_message());
      return *this;
    }

    static constexpr char const* MESSAGE_NAME = "message";
    inline void clear_message() { message_.clear(); }
    inline ::EmbeddedProto::FieldString<InfoMessagePacket_message_LENGTH>& mutable_message() { return message_; }
    inline void set_message(const ::EmbeddedProto::FieldString<InfoMessagePacket_message_LENGTH>& rhs) { message_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<InfoMessagePacket_message_LENGTH>& get_message() const { return message_; }
    inline const char* message() const { return message_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = message_.serialize_with_id(static_cast<uint32_t>(FieldNumber::MESSAGE), buffer, false);
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
          case FieldNumber::MESSAGE:
            return_value = message_.deserialize_check_type(buffer, wire_type);
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
      clear_message();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::MESSAGE:
          name = MESSAGE_NAME;
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

      left_chars = message_.to_string(left_chars, indent_level + 2, MESSAGE_NAME, true);
  
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


      ::EmbeddedProto::FieldString<InfoMessagePacket_message_LENGTH> message_;

};

class TouchPacket final: public ::EmbeddedProto::MessageInterface
{
  public:
    TouchPacket() = default;
    TouchPacket(const TouchPacket& rhs )
    {
      set_touch_id(rhs.get_touch_id());
      set_pen_down(rhs.get_pen_down());
      set_x(rhs.get_x());
      set_y(rhs.get_y());
    }

    TouchPacket(const TouchPacket&& rhs ) noexcept
    {
      set_touch_id(rhs.get_touch_id());
      set_pen_down(rhs.get_pen_down());
      set_x(rhs.get_x());
      set_y(rhs.get_y());
    }

    ~TouchPacket() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      TOUCH_ID = 1,
      PEN_DOWN = 2,
      X = 3,
      Y = 4
    };

    TouchPacket& operator=(const TouchPacket& rhs)
    {
      set_touch_id(rhs.get_touch_id());
      set_pen_down(rhs.get_pen_down());
      set_x(rhs.get_x());
      set_y(rhs.get_y());
      return *this;
    }

    TouchPacket& operator=(const TouchPacket&& rhs) noexcept
    {
      set_touch_id(rhs.get_touch_id());
      set_pen_down(rhs.get_pen_down());
      set_x(rhs.get_x());
      set_y(rhs.get_y());
      return *this;
    }

    static constexpr char const* TOUCH_ID_NAME = "touch_id";
    inline void clear_touch_id() { touch_id_.clear(); }
    inline void set_touch_id(const int32_t& value) { touch_id_ = value; }
    inline void set_touch_id(const int32_t&& value) { touch_id_ = value; }
    inline int32_t& mutable_touch_id() { return touch_id_.get(); }
    inline const int32_t& get_touch_id() const { return touch_id_.get(); }
    inline int32_t touch_id() const { return touch_id_.get(); }

    static constexpr char const* PEN_DOWN_NAME = "pen_down";
    inline void clear_pen_down() { pen_down_.clear(); }
    inline void set_pen_down(const bool& value) { pen_down_ = value; }
    inline void set_pen_down(const bool&& value) { pen_down_ = value; }
    inline bool& mutable_pen_down() { return pen_down_.get(); }
    inline const bool& get_pen_down() const { return pen_down_.get(); }
    inline bool pen_down() const { return pen_down_.get(); }

    static constexpr char const* X_NAME = "x";
    inline void clear_x() { x_.clear(); }
    inline void set_x(const int32_t& value) { x_ = value; }
    inline void set_x(const int32_t&& value) { x_ = value; }
    inline int32_t& mutable_x() { return x_.get(); }
    inline const int32_t& get_x() const { return x_.get(); }
    inline int32_t x() const { return x_.get(); }

    static constexpr char const* Y_NAME = "y";
    inline void clear_y() { y_.clear(); }
    inline void set_y(const int32_t& value) { y_ = value; }
    inline void set_y(const int32_t&& value) { y_ = value; }
    inline int32_t& mutable_y() { return y_.get(); }
    inline const int32_t& get_y() const { return y_.get(); }
    inline int32_t y() const { return y_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != touch_id_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = touch_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TOUCH_ID), buffer, false);
      }

      if((false != pen_down_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = pen_down_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PEN_DOWN), buffer, false);
      }

      if((0 != x_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = x_.serialize_with_id(static_cast<uint32_t>(FieldNumber::X), buffer, false);
      }

      if((0 != y_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = y_.serialize_with_id(static_cast<uint32_t>(FieldNumber::Y), buffer, false);
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
          case FieldNumber::TOUCH_ID:
            return_value = touch_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PEN_DOWN:
            return_value = pen_down_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::X:
            return_value = x_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::Y:
            return_value = y_.deserialize_check_type(buffer, wire_type);
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
      clear_touch_id();
      clear_pen_down();
      clear_x();
      clear_y();

    }

#ifndef DISABLE_FIELD_NUMBER_TO_NAME 

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::TOUCH_ID:
          name = TOUCH_ID_NAME;
          break;
        case FieldNumber::PEN_DOWN:
          name = PEN_DOWN_NAME;
          break;
        case FieldNumber::X:
          name = X_NAME;
          break;
        case FieldNumber::Y:
          name = Y_NAME;
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

      left_chars = touch_id_.to_string(left_chars, indent_level + 2, TOUCH_ID_NAME, true);
      left_chars = pen_down_.to_string(left_chars, indent_level + 2, PEN_DOWN_NAME, false);
      left_chars = x_.to_string(left_chars, indent_level + 2, X_NAME, false);
      left_chars = y_.to_string(left_chars, indent_level + 2, Y_NAME, false);
  
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


      EmbeddedProto::int32 touch_id_ = 0;
      EmbeddedProto::boolean pen_down_ = false;
      EmbeddedProto::int32 x_ = 0;
      EmbeddedProto::int32 y_ = 0;

};

} // End of namespace proto
#endif // DATA_H