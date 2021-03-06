/*
 * This file is produced by tools!!
 *
 * Copyright (C) 2012 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/io.h>
#include <asm/arch/pinmap.h>

static pinmap_t  ctrl[] = {
{REG_PIN_CTRL0,			0},	//modify it later
{REG_PIN_CTRL1,			0},	//modify it later
{REG_PIN_CTRL2,(4<<28)|(1<<27)/*CP1 Control RF SBI0*/|(1<<24)/*CP1 Control SIM2*/|(1<<22)/*CP1 Control SIM1*/|(1<<20)/*CP1 Control SIM0*/|(1<<16)|(2<<10)},
{REG_PIN_CTRL3,			0},	//modify it later1
};

void pinctrl_init(void)
{
    int i;
    for (i = 0; i < sizeof(ctrl)/sizeof(ctrl[0]); i++) {
        __raw_writel(ctrl[i].val, CTL_PIN_BASE + ctrl[i].reg);
    }
}
