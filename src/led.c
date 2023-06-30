#include "led.h"

#include <zephyr/drivers/gpio.h>

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int set_led_ready(void)
{
    if (!gpio_is_ready_dt(&led)) {
		return -1;
	}

	return gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
}

int toggle_led(void)
{
    return gpio_pin_toggle_dt(&led);
}
