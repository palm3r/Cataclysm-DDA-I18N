#ifndef _WEATHER_DATA_H_
#define _WEATHER_DATA_H_

#include "weather.h"

extern std::string season_name[4];
extern weather_datum weather_data[NUM_WEATHER_TYPES];

/* Chances for each season, for the weather listed on the left to shift to the
 * weather listed across the top.
 */
const int weather_shift[4][NUM_WEATHER_TYPES][NUM_WEATHER_TYPES] = {
{ // SPRING
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* NUL */ {  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLR */ {  0,  5,  2,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* SUN */ {  0,  4,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLD */ {  0,  3,  0,  4,  3,  1,  0,  0,  1,  0,  1,  0,  0},
/* DRZ */ {  0,  1,  0,  3,  6,  3,  1,  0,  2,  0,  0,  0,  0},
/* RAI */ {  0,  0,  0,  4,  5,  7,  3,  1,  0,  0,  0,  0,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* TND */ {  0,  0,  0,  2,  2,  4,  5,  3,  0,  0,  0,  0,  0},
/* LGT */ {  0,  0,  0,  1,  1,  4,  5,  5,  0,  0,  0,  0,  0},
/* AC1 */ {  0,  1,  0,  1,  1,  1,  0,  0,  3,  3,  0,  0,  0},
/* AC2 */ {  0,  0,  0,  1,  1,  1,  0,  0,  4,  2,  0,  0,  0},
/* SN1 */ {  0,  1,  0,  3,  2,  1,  1,  0,  0,  0,  2,  1,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* SN2 */ {  0,  0,  0,  1,  1,  2,  1,  0,  0,  0,  3,  1,  1},
/* SN3 */ {  0,  0,  0,  0,  1,  3,  2,  1,  0,  0,  1,  1,  1}
},

{ // SUMMER
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* NUL */ {  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLR */ {  0,  5,  5,  2,  2,  1,  1,  0,  1,  0,  1,  0,  0},
/* SUN */ {  0,  3,  7,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLD */ {  0,  1,  1,  6,  5,  2,  1,  0,  2,  0,  1,  0,  0},
/* DRZ */ {  0,  2,  2,  3,  6,  3,  1,  0,  2,  0,  0,  0,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* RAI */ {  0,  1,  1,  3,  4,  5,  4,  2,  0,  0,  0,  0,  0},
/* TND */ {  0,  0,  0,  2,  3,  5,  4,  5,  0,  0,  0,  0,  0},
/* LGT */ {  0,  0,  0,  0,  0,  3,  3,  5,  0,  0,  0,  0,  0},
/* AC1 */ {  0,  1,  1,  2,  1,  1,  0,  0,  3,  4,  0,  0,  0},
/* AC2 */ {  0,  1,  0,  1,  1,  1,  0,  0,  5,  3,  0,  0,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* SN1 */ {  0,  4,  0,  4,  2,  2,  1,  0,  0,  0,  2,  1,  0},
/* SN2 */ {  0,  0,  0,  2,  2,  4,  2,  0,  0,  0,  3,  1,  1},
/* SN3 */ {  0,  0,  0,  2,  1,  3,  3,  1,  0,  0,  2,  2,  0}
},

{ // AUTUMN
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* NUL */ {  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLR */ {  0,  6,  3,  3,  3,  1,  1,  0,  1,  0,  1,  0,  0},
/* SUN */ {  0,  4,  5,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLD */ {  0,  1,  1,  8,  5,  2,  0,  0,  2,  0,  1,  0,  0},
/* DRZ */ {  0,  1,  0,  3,  6,  3,  1,  0,  2,  0,  0,  0,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* RAI */ {  0,  1,  1,  3,  4,  5,  4,  2,  0,  0,  0,  0,  0},
/* TND */ {  0,  0,  0,  2,  3,  5,  4,  5,  0,  0,  0,  0,  0},
/* LGT */ {  0,  0,  0,  0,  0,  3,  3,  5,  0,  0,  0,  0,  0},
/* AC1 */ {  0,  1,  1,  2,  1,  1,  0,  0,  3,  4,  0,  0,  0},
/* AC2 */ {  0,  0,  0,  1,  1,  1,  0,  0,  4,  4,  0,  0,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* SN1 */ {  0,  2,  0,  4,  2,  1,  0,  0,  0,  0,  2,  1,  0},
/* SN2 */ {  0,  0,  0,  2,  2,  5,  2,  0,  0,  0,  2,  1,  1},
/* SN3 */ {  0,  0,  0,  2,  1,  5,  2,  0,  0,  0,  2,  1,  1}
},

{ // WINTER
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* NUL */ {  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
/* CLR */ {  0,  9,  3,  4,  1,  0,  0,  0,  1,  0,  2,  0,  0},
/* SUN */ {  0,  4,  8,  1,  0,  0,  0,  0,  0,  0,  1,  0,  0},
/* CLD */ {  0,  1,  1,  8,  1,  0,  0,  0,  1,  0,  4,  2,  1},
/* DRZ */ {  0,  1,  0,  4,  3,  1,  0,  0,  1,  0,  3,  0,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* RAI */ {  0,  0,  0,  3,  2,  2,  1,  1,  0,  0,  4,  4,  0},
/* TND */ {  0,  0,  0,  2,  1,  2,  2,  1,  0,  0,  2,  4,  1},
/* LGT */ {  0,  0,  0,  3,  0,  3,  3,  1,  0,  0,  2,  4,  4},
/* AC1 */ {  0,  1,  1,  4,  1,  0,  0,  0,  3,  1,  1,  0,  0},
/* AC2 */ {  0,  0,  0,  2,  1,  1,  0,  0,  4,  1,  1,  1,  0},
//         NUL CLR SUN CLD DRZ RAI THN LGT AC1 AC2 SN1 SN2 SN3
/* SN1 */ {  0,  1,  0,  5,  1,  0,  0,  0,  0,  0,  7,  2,  0},
/* SN2 */ {  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  2,  7,  3},
/* SN3 */ {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  4,  6}
}
};

#endif // _WEATHER_DATA_H_
