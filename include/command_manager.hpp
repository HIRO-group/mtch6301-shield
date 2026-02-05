#pragma once
#include <Arduino.h>

#include <generated/common.h>
#include <gpio_defs.hpp>

class CommandManager {
  public:
    void process_command(const proto::Command& command) {
      switch (command.get_which_payload()) {
        case proto::Command::FieldNumber::TEST_COMMAND:
          handle_test_command(command.get_test_command());
          break;
        default:
          break;
      }
    }

  private:
    bool light_on = false;

    void handle_test_command(const proto::TestCommand& test_command) {
      light_on = !light_on;
      digitalWrite(STATUS_LED, light_on ? HIGH : LOW);    
    }
};