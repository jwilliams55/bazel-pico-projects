
#include "tc9548a.h"

pw::Status write_to_device(i2c_inst_t* i2c, uint8_t address, uint8_t data) {
  absolute_time_t until = delayed_by_ms(get_absolute_time(), 500);
  int bytes = i2c_write_blocking_until(i2c, address, &data, 1, false, until);
  if (bytes != 1) {
    return pw::Status::Unavailable();
  }
  return pw::OkStatus();
}

pw::Status tc9548a::select_channel(uint8_t channel) {
  if (channel > 7) {
    return pw::Status::InvalidArgument();
  }
  uint8_t data = 1 << channel;

  return write_to_device(i2c_, address_, data);
}

pw::Status tc9548a::clear() {
  uint8_t data = 0;
  return write_to_device(i2c_, address_, data);
}
