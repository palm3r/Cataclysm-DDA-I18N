#include "weather_data.h"
#include "i18n.h"

extern std::string season_name[4];
std::string season_name[4] = {
N_("Spring"), N_("Summer"), N_("Autumn"), N_("Winter")
};

/* Name, color in UI, {seasonal temperatures}, ranged penalty, sight penalty,
 * light_modifier, minimum time (in minutes), max time (in minutes), warn player?
 * Note that max time is NOT when the weather is guaranteed to stop; it is
 *  simply when the weather is guaranteed to be recalculated.  Most weather
 *  patterns have "stay the same" as a highly likely transition; see below
 * Note light modifier assumes baseline of DAYLIGHT_LEVEL at 60
 */
extern weather_datum weather_data[NUM_WEATHER_TYPES];
weather_datum weather_data[NUM_WEATHER_TYPES] = {
{"NULL Weather - BUG", c_magenta,
 {0, 0, 0, 0}, 0, 0, 0, 0, false,
 &weather_effect::none},
{N_("Clear"), c_cyan,
 {55, 85, 60, 30}, 0, 0, 0, 30, 120, false,
 &weather_effect::none},
{N_("Sunny"), c_ltcyan,
 {70, 100, 70, 40}, 0, 0, 20, 60, 300, false,
 &weather_effect::glare},
{N_("Cloudy"), c_ltgray,
 {50, 75, 60, 20}, 0, 2, -20, 60, 300, false,
 &weather_effect::none},
{N_("Drizzle"), c_ltblue,
 {45, 70, 45, 35}, 1, 3, -30, 10, 60, true,
 &weather_effect::wet},
{N_("Rain"), c_blue,
 {42, 65, 40, 30}, 3, 5, -40, 30, 180, true,
 &weather_effect::very_wet},
{N_("Thunder Storm"), c_dkgray,
 {42, 70, 40, 30}, 4, 7, -50, 30, 120, true,
 &weather_effect::thunder},
{N_("Lightning Storm"), c_yellow,
 {45, 52, 42, 32}, 4, 8, -50, 10, 30, true,
 &weather_effect::lightning},
{N_("Acidic Drizzle"), c_ltgreen,
 {45, 70, 45, 35}, 2, 3, -30, 10, 30, true,
 &weather_effect::light_acid},
{N_("Acid Rain"), c_green,
 {45, 70, 45, 30}, 4, 6, -40, 10, 30, true,
 &weather_effect::acid},
{N_("Flurries"), c_white,
 {30, 30, 30, 20}, 2, 4, -30, 10, 60, true,
 &weather_effect::flurry},
{N_("Snowing"), c_white,
 {25, 25, 20, 10}, 4, 7, -30, 30, 360, true,
 &weather_effect::snow},
{N_("Snowstorm"), c_white,
 {20, 20, 20,  5}, 6, 10, -55, 60, 180, true,
 &weather_effect::snowstorm}
};

