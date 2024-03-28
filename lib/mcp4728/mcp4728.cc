
#include "mcp4728.h"

pw::Status write_to_device(i2c_inst_t *i2c, uint8_t address, uint8_t data) {
  absolute_time_t until = delayed_by_ms(get_absolute_time(), 500);
  int bytes = i2c_write_blocking_until(i2c, address, &data, 1, false, until);
  if (bytes != 1) {
    return pw::Status::Unavailable();
  }
  return pw::OkStatus();
}

pw::Status mcp4728::set_gain_vref(uint8_t gain, uint8_t vref) {
  uint8_t tmp = vref << 2 | gain; // Random to stop compile errors
  if (tmp > 0x3) {
    return pw::Status::InvalidArgument();
  }
  return pw::Status::Unimplemented(); // TODO: Implement
}

pw::Status mcp4728::set_outputs(uint16_t dac0, uint16_t dac1, uint16_t dac2,
                                uint16_t dac3) {
  uint8_t tmp = dac0 | dac1 | dac2 | dac3; // Random to stop compile errors
  if (tmp > 0xF) {
    return pw::Status::InvalidArgument();
  }
  return pw::Status::Unimplemented(); // TODO: Implement
}

pw::Status mcp4728::set_address(uint8_t address) {
  if (address > 0x77) { // Random to stop compile errors
    return pw::Status::InvalidArgument();
  }
  return pw::Status::Unimplemented(); // TODO: Implement
}

pw::Status mcp4728::log_registers() {
  return pw::Status::Unimplemented(); // TODO: Implement
}
