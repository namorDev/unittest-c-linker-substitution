#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
  #include "led.h"
}

#include "zephyr/drivers/gpio_mock.hpp"

using namespace ::testing;

TEST(LedTest, set_led_ready_success) 
{
  GpioMock_createNice();

  EXPECT_CALL(*pGpioMock, gpio_is_ready_dt(_)).WillOnce(Return(true));
  EXPECT_CALL(*pGpioMock, gpio_pin_configure_dt(_,_)).WillOnce(Return(0));

  EXPECT_EQ(set_led_ready(), 0);

  pGpioMock.reset();  
}