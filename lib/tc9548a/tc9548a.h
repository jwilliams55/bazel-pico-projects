/**
 *
 * Driver for the TC9548A I2C multiplexer.
 *
 */

#pragma once

#include <array>
#include <cstdint>
#include <cstdio>

#include "pw_status/status.h"
#include "hardware/i2c.h"

constexpr uint8_t TC9548A_DEFAULT_ADDRESS = 0x70;

class tc9548a {
  public:
    tc9548a(i2c_inst_t* i2c, uint8_t address = TC9548A_DEFAULT_ADDRESS) : address_(address), i2c_(i2c) {}
    pw::Status select_channel(uint8_t channel);
    pw::Status clear();

  private:
    uint8_t address_;
    i2c_inst_t* i2c_;
    std::array<uint8_t, 8> channels_;

};



