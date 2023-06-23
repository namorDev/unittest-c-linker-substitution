#include "gpio.h"

#include "vendor_hal/gpio.h"

int gpio_pin_set(const struct device *port, gpio_pin_t pin, int value)
{
	// call vendor_hal gpio_pin_set()
}

int gpio_pin_configure(const struct device *port, gpio_pin_t pin, gpio_flags_t flags)
{
	// call vendor_hal gpio_pin_configure();
}