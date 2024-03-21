
#include <stdio.h>

#include "pico/stdlib.h"

int main() {
  stdio_init_all();
  gpio_init(PICO_DEFAULT_LED_PIN);
  gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
  
  uint8_t status = 0;
  while (true) {
    gpio_put(PICO_DEFAULT_LED_PIN, status);
    status = !status;
    printf("Hello, world!\n");
    sleep_ms(1000);
  }

  return 0;
}
