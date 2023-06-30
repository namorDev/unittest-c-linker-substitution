#ifndef GPIO_MOCK_HPP
#define GPIO_MOCK_HPP

#include <gmock/gmock.h>
#include <memory>

extern "C"
{
    #include "gpio.h"
}

class GpioMock
{
public:
    MOCK_METHOD1(gpio_is_ready_dt, bool (const struct gpio_dt_spec *spec));
    MOCK_METHOD2(gpio_pin_configure_dt, int(const struct gpio_dt_spec *spec, gpio_flags_t extra_flags));
    MOCK_METHOD1(gpio_pin_toggle_dt, int(const struct gpio_dt_spec *spec));
};

extern std::unique_ptr<GpioMock> pGpioMock;

void GpioMock_createNice(void);

void GpioMock_createStrict(void);


#endif