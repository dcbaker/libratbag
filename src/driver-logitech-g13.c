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

#include "libratbag-private.h"
#include "libratbag-hidraw.h"
static int
logitech_g13_probe(struct ratbag_device *device)
{
	return 0;
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
}

struct ratbag_driver logitech_g24 = {
	.name = "Logitech G13 Gameboard",
	.id = "logitech_g13",
	.probe = logitech_g13_probe,
	.remove = logitech_g13_remove,
	.commit = logitech_g13_commit,
	.set_active_profile = logitech_g13_set_active_profile,
};
