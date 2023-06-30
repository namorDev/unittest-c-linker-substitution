#include "gpio_mock.hpp"

#include <assert.h>

std::unique_ptr<GpioMock> pGpioMock;

void GpioMock_createNice(void)
{
    pGpioMock = std::unique_ptr<GpioMock>(new ::testing::NiceMock<GpioMock>());
}

void GpioMock_createStrict(void)
{
    pGpioMock = std::unique_ptr<GpioMock>(new ::testing::StrictMock<GpioMock>());
}


bool gpio_is_ready_dt(const struct gpio_dt_spec *spec)
{
    assert(pGpioMock);
    return pGpioMock->gpio_is_ready_dt(spec); // call mock
}

int gpio_pin_configure_dt(const struct gpio_dt_spec *spec, gpio_flags_t extra_flags)
{
    assert(pGpioMock);
    return pGpioMock->gpio_pin_configure_dt(spec, extra_flags); // call mock
}

int gpio_pin_toggle_dt(const struct gpio_dt_spec *spec)
{
    assert(pGpioMock);
    return pGpioMock->gpio_pin_toggle_dt(spec); // call mock
}