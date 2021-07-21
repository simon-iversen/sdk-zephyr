/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>
#include <devicetree.h>

#define SPI2 DT_NODELABEL(spi2)

void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
	printk("CS GPIOS %d\n", DT_PHA_BY_IDX(SPI2, cs_gpios, 0, pin));
	printk("CS FLAGS %d\n", DT_PHA_BY_IDX(SPI2, cs_gpios, 0, flags));
}
