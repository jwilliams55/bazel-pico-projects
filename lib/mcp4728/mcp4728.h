/**
 *
 * Driver for the MCP4728 I2C DAC.
 *
 */

#pragma once

#include <array>
#include <cstdint>
#include <cstdio>

#include "hardware/i2c.h"
#include "pw_status/status.h"

constexpr uint8_t MCP4728_DEFAULT_ADDRESS = 0x60;

class mcp4728 {
public:
  mcp4728(i2c_inst_t *i2c, uint8_t address = MCP4728_DEFAULT_ADDRESS)
      : address_(address), i2c_(i2c) {}

  // TODO: enum the acceptable values
  pw::Status set_gain_vref(uint8_t gain, uint8_t vref);

  // TODO: should i convert V->counts?
  pw::Status set_outputs(uint16_t dac0, uint16_t dac1, uint16_t dac2, uint16_t dac3);

  // TODO: how to do this w/ a generic device? Need to manually switch the pin (unless tied into a GPIO...)
  pw::Status set_address(uint8_t address);

  pw::Status log_registers();

private:
  uint8_t address_;
  i2c_inst_t *i2c_;
};
