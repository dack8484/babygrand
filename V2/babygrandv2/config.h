#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Dack8484
#define PRODUCT         BabyGrand
#define DESCRIPTION     A 31-key Alpha-staggered low profile keyboard.



/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, D1, B6}
#define MATRIX_COL_PINS { F4, F5, F6, D1, D0, C6, D7, E6, B4, B5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5



/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE




