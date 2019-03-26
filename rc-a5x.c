/* Keytable for A5X IR Remote Controller
 *
 * Copyright (c) 2019 madmalkav
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <media/rc-map.h>
#include <linux/module.h>

static struct rc_map_table a5x[] = {
	{ 0x8081, KEY_POWER },
	{ 0x8083, KEY_MENU },
	{ 0x8038, KEY_UP },
	{ 0x8040, KEY_DOWN },
	{ 0x8037, KEY_LEFT },
	{ 0x8039, KEY_RIGHT },
	{ 0x8013, KEY_OK },
	{ 0x8089, KEY_VOLUMEDOWN },
	{ 0x8048, KEY_MUTE },
	{ 0x8087, KEY_VOLUMEUP },
	{ 0x8027, KEY_BACK },
	{ 0x8073, KEY_HOME },
};

static struct rc_map_list a5x_map = {
	.map = {
		.scan    = a5x,
		.size    = ARRAY_SIZE(a5x),
		.rc_type = RC_TYPE_NEC,
		.name    = RC_MAP_A5X,
	}
};

static int __init init_rc_map_a5x(void)
{
	return rc_map_register(&a5x_map);
}

static void __exit exit_rc_map_a5x(void)
{
	rc_map_unregister(&a5x_map);
}

module_init(init_rc_map_a5x)
module_exit(exit_rc_map_a5x)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("madmalkav");
