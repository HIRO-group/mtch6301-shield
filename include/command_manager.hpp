#pragma once

#include <generated/common.h>
#include <gpio_defs.hpp>
#include <mtch.hpp>

class SerialCommunication;

class CommandManager {
  public:
    CommandManager(SerialCommunication& comm, Mtch* mtch) : comm(comm), mtch(mtch) {}

    void process_command(const proto::Command& command) {
      switch (command.get_which_payload()) {
        case proto::Command::FieldNumber::TEST_COMMAND:
          handle_test_command(command.get_test_command());
          break;
        case proto::Command::FieldNumber::SET_NUM_CHANNELS_COMMAND:
          handle_set_number_channels_command(command.get_set_num_channels_command());
          break;
        default:
          break;
      }
    }

  private:
    SerialCommunication& comm;
    Mtch* mtch;
    
    bool light_on = false;

    void handle_test_command(const proto::TestCommand& test_command);
    void handle_set_number_channels_command(const proto::SetNumChannelsCommand& set_num_channels_command);
};