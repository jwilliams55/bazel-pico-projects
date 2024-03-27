#include <stdio.h>
#include <array>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

constexpr uint8_t I2C_PIN_SDA = 20;
constexpr uint8_t I2C_PIN_SCL = 21;

uint8_t scan_i2c_bus(i2c_inst_t* i2c, uint8_t start, uint8_t end, std::array<uint8_t, 16> devices_found) {
  uint8_t qty_devices = 0;
  for (uint8_t address = start; address < end; address++) {
    absolute_time_t delay = delayed_by_ms(get_absolute_time(), 500);
    int8_t status = i2c_read_blocking_until(i2c, address, NULL, 0, false, delay);
    if (status >= 0) {
      printf("Found device at address 0x%02x\n", address);
      devices_found[qty_devices] = address;
      qty_devices++;
    }
  }
  return qty_devices;
}

int main() {
  stdio_init_all();
  i2c_init(i2c0, 100 * 1000);
  gpio_set_function(I2C_PIN_SCL, GPIO_FUNC_I2C);
  gpio_set_function(I2C_PIN_SDA, GPIO_FUNC_I2C);

  std::array<uint8_t, 16> devices_found;
  uint8_t devices = scan_i2c_bus(i2c0, 0x08, 0x78, devices_found);
  printf("Found %d I2C devices\n", devices);

  // TODO: what else should we do here?
  while (true) {
    sleep_ms(1000);
  }

  return 0;
}
