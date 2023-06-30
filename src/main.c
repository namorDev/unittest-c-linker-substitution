/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include "led.h"

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000



int main(void)
{
	int ret;

	ret = set_led_ready();
	if (ret < 0) {
		return 0;
	}

	while (1) {

		ret = toggle_led();
		if (ret < 0) {
			return 0;
		}
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
