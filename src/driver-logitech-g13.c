/*
 * Copyright © 2020 Dylan Baker
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "config.h"
#include <assert.h>
#include <errno.h>
#include <libevdev/libevdev.h>
#include <linux/input.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "libratbag-private.h"
#include "libratbag-hidraw.h"

#define LOGITECH_G13_NUM_PROFILES			1
#define LOGITECH_G13_NUM_BUTTONS			48
#define LOGITECH_G13_NUM_DPI				0
#define LOGITECH_G13_NUM_LED				1
#define LOGITECH_G13_REPORT_ID_GET_ACTIVE 0xf0

struct logitech_g13_data {
};

static int
logitech_g13_test_hidraw(struct ratbag_device *device)
{
	return ratbag_hidraw_has_report(device, LOGITECH_G13_REPORT_ID_GET_ACTIVE);
}


static int
logitech_g13_probe(struct ratbag_device *device)
{
	struct logitech_g13_data *drv_data = NULL;
	struct ratbag_profile *profile;

	int rc = ratbag_find_hidraw(device, logitech_g13_test_hidraw);
	if (rc) {
		goto err;
	}
	drv_data = zalloc(sizeof(*drv_data));
	ratbag_set_drv_data(device, drv_data);

	ratbag_device_init_profiles(device,
				    LOGITECH_G13_NUM_PROFILES,
				    LOGITECH_G13_NUM_DPI,
				    LOGITECH_G13_NUM_BUTTONS,
				    LOGITECH_G13_NUM_LED);

	return 0;
err:
	free(drv_data);
	ratbag_set_drv_data(device, NULL);
	return rc;
}

static int
logitech_g13_set_active_profile(struct ratbag_device *device, unsigned int index)
{
	return 0;
}

static int
logitech_g13_commit(struct ratbag_device *device)
{
	return 0;
}

static void
logitech_g13_remove(struct ratbag_device *device)
{
	ratbag_close_hidraw(device);
	free(ratbag_get_drv_data(device));
}

struct ratbag_driver logitech_g13_driver = {
	.name = "Logitech G13 Gameboard",
	.id = "logitech_g13",
	.probe = logitech_g13_probe,
	.remove = logitech_g13_remove,
	.commit = logitech_g13_commit,
	.set_active_profile = logitech_g13_set_active_profile,
};
