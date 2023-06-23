
#ifndef MY_GPIO_H_
#define MY_GPIO_H_

int gpio_pin_set(const struct device *port, gpio_pin_t pin, int value);
int gpio_pin_configure(const struct device *port, gpio_pin_t pin, gpio_flags_t flags);

#endif /* MY_GPIO_H_ */