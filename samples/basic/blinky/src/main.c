/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000

/* The devicetree node identifier for the "led0" alias. */
#define SIMSEL_NODE DT_ALIAS(simsel)

#if DT_NODE_HAS_STATUS(SIMSEL_NODE, okay)
#define SIMSEL	DT_GPIO_LABEL(SIMSEL_NODE, gpios)
#define PIN	DT_GPIO_PIN(SIMSEL_NODE, gpios)
#define FLAGS	DT_GPIO_FLAGS(SIMSEL_NODE, gpios)
#else
/* A build error here means your board isn't set up to blink an LED. */
#error "Unsupported board: SIMSEL devicetree alias is not defined"
#define SIMSEL	""
#define PIN	0
#define FLAGS	0
#endif

void main(void)
{
	const struct device *dev;
	//bool led_is_on = true;
	int ret;

	dev = device_get_binding(SIMSEL);
	if (dev == NULL) {
		return;
	}

	ret = gpio_pin_configure(dev, PIN, GPIO_OUTPUT_ACTIVE | FLAGS);
	if (ret < 0) {
		return;
	}

	/*while (1) {
		gpio_pin_set(dev, PIN, (int)led_is_on);
		led_is_on = !led_is_on;
		k_msleep(SLEEP_TIME_MS);
	}*/
}
