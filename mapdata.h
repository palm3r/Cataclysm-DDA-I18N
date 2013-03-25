#ifndef _MAPDATA_H_
#define _MAPDATA_H_

#include <vector>
#include <string>
#include "color.h"
#include "item.h"
#include "trap.h"
#include "monster.h"
#include "enums.h"
#include "computer.h"
#include "vehicle.h"
#include "graffiti.h"
#include "basecamp.h"
#include <iosfwd>
#include "i18n.h"

class game;
class monster;

#ifndef SEEX 	// SEEX is how far the player can see in the X direction (at
#define SEEX 12	// least, without scrolling).  All map segments will need to be
#endif		// at least this wide. The map therefore needs to be 3x as wide.

#ifndef SEEY	// Same as SEEX
#define SEEY 12 // Requires 2*SEEY+1= 25 vertical squares
#endif	        // Nuts to 80x24 terms. Mostly exists in graphical clients, and
	        // those fatcats can resize.

// mfb(t_flag) converts a flag to a bit for insertion into a bitfield
#ifndef mfb
#define mfb(n) long(1 << (n))
#endif

enum t_flag {
 transparent = 0,// Player & monsters can see through/past it
 bashable,     // Player & monsters can bash this & make it the next in the list
 container,    // Items on this square are hidden until looted by the player
 place_item,   // Valid terrain for place_item() to put items on
 door,         // Can be opened--used for NPC pathfinding.
 flammable,    // May be lit on fire
 l_flammable,  // Harder to light on fire, but still possible
 explodes,     // Explodes when on fire
 diggable,     // Digging monsters, seeding monsters, digging w/ shovel, etc.
 tentable,     // I'm lazy, this is just diggable with a few more tacked on.
 liquid,       // Blocks movement but isn't a wall, e.g. lava or water
 swimmable,    // You (and monsters) swim here
 sharp,	       // May do minor damage to players/monsters passing it
 painful,      // May cause a small amount of pain
 rough,        // May hurt the player's feet
 sealed,       // Can't 'e' to retrieve items here
 noitem,       // Items "fall off" this space
 goes_down,    // Can '>' to go down a level
 goes_up,      // Can '<' to go up a level
 console,      // Used as a computer
 alarmed,      // Sets off an alarm if smashed
 supports_roof,// Used as a boundary for roof construction
               // can also knock down adjacent supports_roof and collapses tiles when destroyed
 thin_obstacle,// passable by player and monsters, but not by vehicles
 collapses,    // Tiles that have a roof over them (which can collapse)
 flammable2,   // Burn to ash rather than rubble.
 deconstruct,  // Can be deconstructed
 reduce_scent, // Reduces the scent even more, only works if object is bashable as well
 num_t_flags   // MUST be last
};

struct ter_t {
 std::string name;
 char sym;
 nc_color color;
 unsigned char movecost;
 trap_id trap;
 unsigned long flags;// : num_t_flags;
};

enum ter_id {
t_null = 0,
t_hole,	// Real nothingness; makes you fall a z-level
// Ground
t_dirt, t_sand, t_dirtmound, t_pit_shallow, t_pit,
t_pit_corpsed, t_pit_covered, t_pit_spiked, t_pit_spiked_covered,
t_rock_floor, t_rubble, t_ash, t_metal, t_wreckage,
t_grass,
t_metal_floor,
t_pavement, t_pavement_y, t_sidewalk,
t_floor,
t_dirtfloor,//Dirt floor(Has roof)
t_hay,
t_grate,
t_slime,
t_bridge,
// Tent Walls & doors
t_canvas_wall, t_canvas_door, t_canvas_door_o, t_groundsheet, t_fema_groundsheet,
t_skin_wall, t_skin_door, t_skin_door_o,  t_skin_groundsheet,
// Lighting related
t_skylight, t_emergency_light_flicker, t_emergency_light,
// Walls
t_wall_log_half, t_wall_log, t_wall_log_chipped, t_wall_log_broken, t_palisade, t_palisade_gate,
t_wall_half, t_wall_wood, t_wall_wood_chipped, t_wall_wood_broken,
t_wall_v, t_wall_h, t_concrete_v, t_concrete_h,
t_wall_metal_v, t_wall_metal_h,
t_wall_glass_v, t_wall_glass_h,
t_wall_glass_v_alarm, t_wall_glass_h_alarm,
t_reinforced_glass_v, t_reinforced_glass_h,
t_bars,
t_door_c, t_door_b, t_door_o, t_door_locked, t_door_locked_alarm, t_door_frame,
t_chaingate_l, t_fencegate_c, t_fencegate_o, t_chaingate_c, t_chaingate_o, t_door_boarded,
t_door_metal_c, t_door_metal_o, t_door_metal_locked,
t_door_glass_c, t_door_glass_o,
t_bulletin,
t_portcullis,
t_recycler, t_window, t_window_taped, t_window_domestic, t_window_domestic_taped, t_window_open, t_curtains,
t_window_alarm, t_window_alarm_taped, t_window_empty, t_window_frame, t_window_boarded,
t_rock, t_fault,
t_paper,
// Tree
t_tree, t_tree_young, t_tree_apple, t_underbrush, t_shrub, t_shrub_blueberry, t_log,
t_root_wall,
t_wax, t_floor_wax,
t_fence_v, t_fence_h, t_chainfence_v, t_chainfence_h, t_chainfence_posts,
t_fence_post, t_fence_wire, t_fence_barbed, t_fence_rope,
t_railing_v, t_railing_h,
// Nether
t_marloss, t_fungus, t_tree_fungal,
// Water, lava, etc.
t_water_sh, t_water_dp, t_sewage,
t_lava,
// Embellishments
t_bed, t_toilet, t_makeshift_bed,
// More embellishments than you can shake a stick at.
t_sink, t_oven, t_woodstove, t_bathtub, t_chair, t_armchair, t_sofa, t_cupboard, t_trashcan, t_desk,
t_sandbox, t_slide, t_monkey_bars, t_backboard,
t_bench, t_table, t_pool_table,
t_gas_pump, t_gas_pump_smashed, t_gas_pump_empty,
t_missile, t_missile_exploded,
t_counter,
t_radio_tower, t_radio_controls,
t_console_broken, t_console, t_gates_mech_control, t_barndoor, t_palisade_pulley,
t_sewage_pipe, t_sewage_pump,
t_centrifuge,
t_column,
// Containers
t_fridge, t_glass_fridge, t_dresser, t_locker,
t_rack, t_bookcase,
t_dumpster,
t_vat, t_crate_c, t_crate_o,
// Staircases etc.
t_stairs_down, t_stairs_up, t_manhole, t_ladder_up, t_ladder_down, t_slope_down,
 t_slope_up, t_rope_up,
t_manhole_cover,
// Special
t_card_science, t_card_military, t_card_reader_broken, t_slot_machine,
 t_elevator_control, t_elevator_control_off, t_elevator, t_pedestal_wyrm,
 t_pedestal_temple,
// Temple tiles
t_rock_red, t_rock_green, t_rock_blue, t_floor_red, t_floor_green, t_floor_blue,
 t_switch_rg, t_switch_gb, t_switch_rb, t_switch_even,
// found at fields
 t_mutpoppy, //mutated poppy flower

num_terrain_types
};

const ter_t terlist[num_terrain_types] = {  // MUST match enum ter_id above!
{"nothing",	     ' ', c_white,   2, tr_null,
	mfb(transparent)|mfb(diggable)},
{N_("empty space"),      ' ', c_black,   2, tr_ledge,
	mfb(transparent)},
{N_("dirt"),	     '.', c_brown,   2, tr_null,
	mfb(transparent)|mfb(diggable)|mfb(tentable)},
{N_("sand"),	     '.', c_yellow,   2, tr_null,
	mfb(transparent)|mfb(diggable)|mfb(tentable)},
{N_("mound of dirt"),    '#', c_brown,   3, tr_null,
	mfb(transparent)|mfb(diggable)},
{N_("shallow pit"),	     '0', c_yellow,  8, tr_null,
	mfb(transparent)|mfb(diggable)},
{N_("pit"),              '0', c_brown,  10, tr_pit,
	mfb(transparent)|mfb(diggable)},
{N_("corpse filled pit"),'#', c_green,  5,  tr_null,
        mfb(transparent)|mfb(diggable)},
{N_("covered pit"),       '#', c_ltred,   2, tr_null,
	mfb(transparent)},
{N_("spiked pit"),       '0', c_ltred,  10, tr_spike_pit,
	mfb(transparent)|mfb(diggable)},
{N_("covered spiked pit"),'#',c_ltred,   2, tr_null,
	mfb(transparent)},
{N_("rock floor"),       '.', c_ltgray,  2, tr_null,
	mfb(transparent)},
{N_("pile of rubble"),   '^', c_ltgray,  4, tr_null,
	mfb(transparent)|mfb(rough)|mfb(diggable)},
{N_("pile of ash"),   '#', c_ltgray,  2, tr_null,
	mfb(transparent)|mfb(diggable)},
{N_("twisted metal"),    '#', c_cyan,    5, tr_null,
        mfb(transparent)|mfb(rough)|mfb(sharp)|mfb(place_item)},
{N_("metal wreckage"),   '#', c_cyan,    5, tr_null,
        mfb(transparent)|mfb(rough)|mfb(sharp)|mfb(place_item)},
{N_("grass"),	     '.', c_green,   2, tr_null,
	mfb(transparent)|mfb(diggable)|mfb(tentable)},
{N_("metal floor"),      '.', c_ltcyan,  2, tr_null,
	mfb(transparent)},
{N_("pavement"),	     '.', c_dkgray,  2, tr_null,
	mfb(transparent)},
{N_("yellow pavement"),  '.', c_yellow,  2, tr_null,
	mfb(transparent)},
{N_("sidewalk"),         '.', c_ltgray,  2, tr_null,
	mfb(transparent)},
{N_("floor"),	     '.', c_cyan,    2, tr_null,
	mfb(transparent)|mfb(l_flammable)|mfb(supports_roof)|mfb(collapses)},
{N_("dirt floor"),	     '.', c_brown,    2, tr_null,  //Dirt Floor, must have roofs!
	mfb(transparent)|mfb(diggable)|mfb(supports_roof)|mfb(collapses)},
{N_("hay"),              '#', i_brown, 5, tr_null,
	mfb(transparent)|mfb(container)|mfb(flammable2)|mfb(collapses)},
{N_("metal grate"),      '#', c_dkgray,  2, tr_null,
	mfb(transparent)},
{N_("slime"),            '~', c_green,   6, tr_null,
        mfb(transparent)|mfb(container)|mfb(flammable2)|mfb(place_item)},
{N_("walkway"),          '#', c_yellow,  2, tr_null,
	mfb(transparent)},
{N_("canvas wall"),      '#', c_blue,   0, tr_null,
        mfb(l_flammable)|mfb(bashable)|mfb(noitem)|mfb(tentable)},
{N_("canvas flap"),      '+', c_blue,   0, tr_null,
        mfb(l_flammable)|mfb(bashable)|mfb(noitem)|mfb(tentable)},
{N_("open canvas flap"), '.', c_blue,   2, tr_null,
        mfb(transparent)},
{N_("groundsheet"),      ';', c_green,   2, tr_null,
        mfb(transparent)|mfb(tentable)},
{N_("groundsheet"),      ';', c_green,   2, tr_null,
        mfb(transparent)},
{N_("animalskin wall"),      '#', c_brown,   0, tr_null,
        mfb(l_flammable)|mfb(bashable)|mfb(noitem)|mfb(tentable)},
{N_("animalskin flap"),      '+', c_white,   0, tr_null,
        mfb(l_flammable)|mfb(bashable)|mfb(noitem)|mfb(tentable)},
{N_("open animalskin flap"), '.', c_white,   2, tr_null,
        mfb(transparent)},
{N_("animalskin floor"),      ';', c_brown,   2, tr_null,
        mfb(transparent)|mfb(tentable)},
{N_("floor"),	     '.', c_white,    2, tr_null,
	mfb(transparent)|mfb(l_flammable)|mfb(supports_roof)|mfb(collapses)}, // Skylight
{N_("floor"),	     '.', c_white,    2, tr_null,
	mfb(transparent)|mfb(l_flammable)|mfb(supports_roof)|mfb(collapses)}, // Emergency Light
{N_("floor"),	     '.', c_white,    2, tr_null,
	mfb(transparent)|mfb(l_flammable)|mfb(supports_roof)|mfb(collapses)}, // Regular Light
{N_("half-built wall"), '#', c_brown,   4, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(noitem)},
{N_("log wall"),        '#', c_brown,   0, tr_null,
        mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("chipped log wall"),'#', c_brown,   0, tr_null,
        mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("broken log wall"), '&', c_brown,   0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(noitem)|
	mfb(supports_roof)},
{N_("palisade wall"),        '#', c_brown,   0, tr_null,
        mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)|mfb(transparent)},
{N_("palisade gate"),        '+', c_ltred,    0, tr_null,
        mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)|mfb(door)|mfb(transparent)},
{N_("half-built wall"),  '#', c_ltred,   4, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(noitem)},
{N_("wooden wall"),      '#', c_ltred,   0, tr_null,
        mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("chipped wood wall"),'#', c_ltred,   0, tr_null,
        mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("broken wood wall"), '&', c_ltred,   0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(noitem)|
    mfb(supports_roof)},
{N_("wall"),             '|', c_ltgray,  0, tr_null,
        mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("wall"),             '-', c_ltgray,  0, tr_null,
        mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("concrete wall"),    '|', c_dkgray,  0, tr_null,
        mfb(noitem)|mfb(supports_roof)},
{N_("concrete wall"),    '-', c_dkgray,  0, tr_null,
        mfb(noitem)|mfb(supports_roof)},
{N_("metal wall"),       '|', c_cyan,    0, tr_null,
        mfb(noitem)|mfb(noitem)|mfb(supports_roof)},
{N_("metal wall"),       '-', c_cyan,    0, tr_null,
        mfb(noitem)|mfb(noitem)|mfb(supports_roof)},
{N_("glass wall"),       '|', c_ltcyan,  0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(noitem)|mfb(supports_roof)},
{N_("glass wall"),       '-', c_ltcyan,  0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(noitem)|mfb(supports_roof)},
{N_("glass wall"),       '|', c_ltcyan,  0, tr_null, // Alarmed
	mfb(transparent)|mfb(bashable)|mfb(alarmed)|mfb(noitem)|
 mfb(supports_roof)},
{N_("glass wall"),       '-', c_ltcyan,  0, tr_null, // Alarmed
	mfb(transparent)|mfb(bashable)|mfb(alarmed)|mfb(noitem)|
 mfb(supports_roof)},
{N_("reinforced glass"), '|', c_ltcyan,  0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(noitem)|mfb(supports_roof)},
{N_("reinforced glass"), '-', c_ltcyan,  0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(noitem)|mfb(supports_roof)},
{N_("metal bars"),       '"', c_ltgray,  0, tr_null,
	mfb(transparent)|mfb(noitem)},
{N_("closed wood door"), '+', c_brown,   0, tr_null,
        mfb(bashable)|mfb(flammable2)|mfb(door)|mfb(noitem)|mfb(supports_roof)},
{N_("damaged wood door"),'&', c_brown,   0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(noitem)|
        mfb(supports_roof)},
{N_("open wood door"),  '\'', c_brown,   2, tr_null,
        mfb(flammable2)|mfb(transparent)|mfb(supports_roof)},
{N_("closed wood door"), '+', c_brown,   0, tr_null,	// Actually locked
        mfb(bashable)|mfb(flammable2)|mfb(noitem)|mfb(supports_roof)},
{N_("closed wood door"), '+', c_brown,   0, tr_null, // Locked and alarmed
	mfb(bashable)|mfb(flammable2)|mfb(alarmed)|mfb(noitem)|mfb(supports_roof)},
{N_("empty door frame"), '.', c_brown,   2, tr_null,
        mfb(transparent)|mfb(supports_roof)},
{N_("locked wire gate"), '+', c_cyan,   0, tr_null,
        mfb(transparent)|mfb(supports_roof)},
{N_("closed wooden gate"), '+', c_brown,   3, tr_null,
        mfb(transparent)|mfb(supports_roof) |mfb(bashable)|mfb(flammable2)},
{N_("open wooden gate"),   '.', c_brown,   2, tr_null,
        mfb(transparent)|mfb(supports_roof) |mfb(bashable)|mfb(flammable2)},
{N_("closed wire gate"), '+', c_cyan,   0, tr_null,
        mfb(transparent)|mfb(supports_roof)},
{N_("open wire gate"),   '.', c_cyan,   2, tr_null,
        mfb(transparent)|mfb(supports_roof)},
{N_("boarded up door"),  '#', c_brown,   0, tr_null,
	mfb(bashable)|mfb(flammable2)|mfb(noitem)|mfb(supports_roof)},
{N_("closed metal door"),'+', c_cyan,    0, tr_null,
	mfb(noitem)|mfb(supports_roof)},
{N_("open metal door"), '\'', c_cyan,    2, tr_null,
	mfb(transparent)|mfb(supports_roof)},
{N_("closed metal door"),'+', c_cyan,    0, tr_null, // Actually locked
	mfb(noitem)|mfb(supports_roof)},
{N_("closed glass door"),'+', c_ltcyan,  0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(door)|mfb(noitem)|mfb(supports_roof)},
{N_("open glass door"), '\'', c_ltcyan,  2, tr_null,
	mfb(transparent)|mfb(supports_roof)},
{N_("bulletin board"),   '6', c_blue,    0, tr_null,
	mfb(flammable)|mfb(noitem)},
{N_("makeshift portcullis"), '&', c_cyan, 0, tr_null,
	mfb(noitem)},
{N_("steel compactor"),      '&', c_green, 0, tr_null,
        mfb(transparent)},
{N_("window"),	     '"', c_ltcyan,  0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable)|mfb(noitem)|
        mfb(supports_roof)|mfb(deconstruct)}, // Plain Ol' window
{N_("taped window"),  '"', c_dkgray,    0, tr_null,
	mfb(bashable)|mfb(flammable)|mfb(noitem)| mfb(supports_roof)| mfb(reduce_scent)}, // Regular window
{N_("window"),	     '"', c_ltcyan,  0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable)|mfb(noitem)|
        mfb(supports_roof)|mfb(deconstruct)}, //has curtains
{N_("taped window"),  '"', c_dkgray,    0, tr_null,
	mfb(bashable)|mfb(flammable)|mfb(noitem)| mfb(supports_roof)| mfb(reduce_scent)}, // Curtain window
{N_("open window"),      '\'', c_ltcyan, 4, tr_null,
	mfb(transparent)|mfb(flammable)|mfb(noitem)| mfb(supports_roof)},
{N_("closed curtains"),  '"', c_dkgray,    0, tr_null,
	mfb(bashable)|mfb(flammable)|mfb(noitem)| mfb(supports_roof)},
{N_("window"),	     '"', c_ltcyan,  0, tr_null, // Actually alarmed
	mfb(transparent)|mfb(bashable)|mfb(flammable)|mfb(alarmed)|mfb(noitem)|
        mfb(supports_roof)},
{N_("taped window"),  '"', c_dkgray,    0, tr_null,
	mfb(bashable)|mfb(flammable)|mfb(noitem)| mfb(supports_roof)|mfb(alarmed)| mfb(reduce_scent)}, //Alarmed, duh.
{N_("empty window"),     '0', c_yellow,  8, tr_null,
	mfb(transparent)|mfb(flammable)|mfb(supports_roof)},
{N_("window frame"),     '0', c_ltcyan,  8, tr_null,
	mfb(transparent)|mfb(sharp)|mfb(flammable)|mfb(noitem)|
        mfb(supports_roof)},
{N_("boarded up window"),'#', c_brown,   0, tr_null,
	mfb(bashable)|mfb(flammable)|mfb(noitem)|mfb(supports_roof)},
{N_("solid rock"),       '#', c_white,   0, tr_null,
	mfb(noitem)|mfb(supports_roof)},
{N_("odd fault"),        '#', c_magenta, 0, tr_null,
	mfb(noitem)|mfb(supports_roof)},
{N_("paper wall"),       '#', c_white,   0, tr_null,
	mfb(bashable)|mfb(flammable2)|mfb(noitem)},
{N_("tree"),	     '7', c_green,   0, tr_null,
	mfb(flammable2)|mfb(noitem)|mfb(supports_roof)},
{N_("young tree"),       '1', c_green,   4, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(noitem)},
{N_("apple tree"), '7', c_ltgreen,   0, tr_null,
	mfb(flammable2)|mfb(noitem)|mfb(supports_roof)},
{N_("underbrush"),       '#', c_ltgreen, 6, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(diggable)|mfb(container)|
        mfb(flammable2)|mfb(thin_obstacle)|mfb(place_item)},
{N_("shrub"),            '#', c_green,   8, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(container)|mfb(flammable2)|
        mfb(thin_obstacle)|mfb(place_item)},
{N_("blueberry bush"),   '#', c_ltgreen,   8, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(container)|mfb(flammable2)|mfb(thin_obstacle)},
{N_("tree trunk"),              '1', c_brown,   4, tr_null,
	mfb(transparent)|mfb(flammable2)|mfb(diggable)},
{N_("root wall"),        '#', c_brown,   0, tr_null,
	mfb(noitem)|mfb(supports_roof)},
{N_("wax wall"),         '#', c_yellow,  0, tr_null,
        mfb(flammable2)|mfb(noitem)|mfb(supports_roof)|mfb(place_item)},
{N_("wax floor"),        '.', c_yellow,  2, tr_null,
	mfb(transparent)|mfb(l_flammable)},
{N_("picket fence"),     '|', c_brown,   3, tr_null,
	mfb(transparent)|mfb(diggable)|mfb(flammable2)|mfb(noitem)|mfb(thin_obstacle)},
{N_("picket fence"),     '-', c_brown,   3, tr_null,
	mfb(transparent)|mfb(diggable)|mfb(flammable2)|mfb(noitem)|mfb(thin_obstacle)},
{N_("chain link fence"), '|', c_cyan,    0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(noitem)|mfb(thin_obstacle)},
{N_("chain link fence"), '-', c_cyan,    0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(noitem)|mfb(thin_obstacle)},
{N_("metal post"),       '#', c_cyan,    2, tr_null,
        mfb(transparent)|mfb(thin_obstacle)},
{N_("fence post"),       '#', c_brown,   2, tr_null,
        mfb(transparent)|mfb(thin_obstacle)},
{N_("wire fence"),       '$', c_blue,    4, tr_null,
        mfb(transparent)|mfb(thin_obstacle)},
{N_("barbed wire fence"),'$', c_blue,    4, tr_null,
        mfb(transparent)|mfb(sharp)|mfb(thin_obstacle)},
{N_("rope fence"),       '$', c_brown,   3, tr_null,
        mfb(transparent)|mfb(thin_obstacle)},
{N_("railing"),          '|', c_yellow,  3, tr_null,
	mfb(transparent)|mfb(noitem)|mfb(thin_obstacle)},
{N_("railing"),          '-', c_yellow,  3, tr_null,
	mfb(transparent)|mfb(noitem)|mfb(thin_obstacle)},
{N_("marloss bush"),     '1', c_dkgray,  0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(flammable2)},
{N_("fungal bed"),       '#', c_dkgray,  3, tr_null,
	mfb(transparent)|mfb(flammable2)|mfb(diggable)},
{N_("fungal tree"),      '7', c_dkgray,  0, tr_null,
	mfb(flammable2)|mfb(noitem)},
{N_("shallow water"),    '~', c_ltblue,  5, tr_null,
	mfb(transparent)|mfb(liquid)|mfb(swimmable)},
{N_("deep water"),       '~', c_blue,    0, tr_null,
	mfb(transparent)|mfb(liquid)|mfb(swimmable)},
{N_("sewage"),           '~', c_ltgreen, 6, tr_null,
	mfb(transparent)|mfb(swimmable)},
{N_("lava"),             '~', c_red,     4, tr_lava,
	mfb(transparent)|mfb(liquid)},
{N_("bed"),              '#', c_magenta, 5, tr_null,
        mfb(transparent)|mfb(container)|mfb(flammable2)|mfb(collapses)|
        mfb(deconstruct)|mfb(place_item)},
{N_("toilet"),           '&', c_white,   4, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(l_flammable)|mfb(collapses)},
{N_("makeshift bed"),    '#', c_magenta, 5, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)},
{N_("sink"),             '&', c_white,   4, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(l_flammable)|mfb(collapses)|mfb(container)|mfb(place_item)},
{N_("oven"),             '#', c_dkgray,   4, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(l_flammable)|mfb(collapses)|mfb(container)|mfb(place_item)},

{N_("wood stove"),             '#', i_red,   4, tr_null,
        mfb(transparent)|mfb(container)|mfb(place_item)},


{N_("bathtub"),          '~', c_white,   4, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(l_flammable)|mfb(collapses)|mfb(container)|mfb(place_item)},

{N_("chair"),            '#', c_brown,   2, tr_null,
	mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)},

{N_("arm chair"),            'H', c_green,   3, tr_null,
	mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)},

{N_("sofa"),            'H', i_red,   3, tr_null,
	mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)},
{N_("cupboard"),         '#', c_blue,    3, tr_null,
        mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)|
        mfb(container)|mfb(place_item)},
{N_("trash can"),        '&', c_ltcyan,  3, tr_null,
        mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(container)|mfb(place_item)},
{N_("desk"),             '#', c_ltred,   3, tr_null,
        mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)|
        mfb(container)|mfb(place_item)},
{N_("sandbox"), '#', c_yellow, 3, tr_null,
	mfb(transparent)|mfb(deconstruct)},
{N_("slide"),            '#', c_ltcyan,  4, tr_null,
	mfb(transparent)|mfb(deconstruct)},
{N_("monkey bars"),      '#', c_cyan,    4, tr_null,
	mfb(transparent)|mfb(deconstruct)},
{N_("backboard"),        '7', c_red,     0, tr_null,
	mfb(transparent)|mfb(deconstruct)},
{N_("bench"),            '#', c_brown,   3, tr_null,
	mfb(transparent)|mfb(flammable2)|mfb(collapses)|mfb(deconstruct)},
{N_("table"),            '#', c_red,     4, tr_null,
	mfb(transparent)|mfb(flammable)|mfb(collapses)|mfb(deconstruct)},
{N_("pool table"),       '#', c_green,   4, tr_null,
	mfb(transparent)|mfb(flammable)|mfb(collapses)|mfb(deconstruct)},
{N_("gasoline pump"),    '&', c_red,     0, tr_null,
	mfb(transparent)|mfb(explodes)|mfb(noitem)},
{N_("smashed gas pump"), '&', c_ltred,   0, tr_null,
	mfb(transparent)|mfb(noitem)},
{N_("out-of-order gasoline pump"),    '&', c_red,     0, tr_null,
	mfb(transparent)|mfb(noitem)},
{N_("missile"),          '#', c_ltblue,  0, tr_null,
	mfb(explodes)|mfb(noitem)},
{N_("blown-out missile"),'#', c_ltgray,  0, tr_null,
	mfb(noitem)},
{N_("counter"),	     '#', c_blue,    4, tr_null,
	mfb(transparent)|mfb(flammable)|mfb(collapses)|mfb(deconstruct)},
{N_("radio tower"),      '&', c_ltgray,  0, tr_null,
	mfb(noitem)},
{N_("radio controls"),   '6', c_green,   0, tr_null,
	mfb(transparent)|mfb(bashable)|mfb(noitem)},
{N_("broken console"),   '6', c_ltgray,  0, tr_null,
	mfb(transparent)|mfb(noitem)|mfb(collapses)},
{N_("computer console"), '6', c_blue,    0, tr_null,
	mfb(transparent)|mfb(console)|mfb(noitem)|mfb(collapses)},
{N_("mechanical winch"), '6', c_cyan_red, 0, tr_null,
        mfb(transparent)|mfb(noitem)|mfb(collapses)},
{N_("rope and pulley"), '|', c_brown, 0, tr_null,
        mfb(transparent)|mfb(noitem)|mfb(collapses)},
{N_("rope and pulley"), '|', c_brown, 0, tr_null,
        mfb(transparent)|mfb(noitem)|mfb(collapses)},
{N_("sewage pipe"),      '1', c_ltgray,  0, tr_null,
	mfb(transparent)},
{N_("sewage pump"),      '&', c_ltgray,  0, tr_null,
	mfb(noitem)},
{N_("centrifuge"),       '{', c_magenta, 0, tr_null,
	mfb(transparent)},
{N_("column"),           '1', c_ltgray,  0, tr_null,
	mfb(flammable)},
{N_("refrigerator"),     '{', c_ltcyan,  0, tr_null,
	mfb(container)|mfb(collapses)|mfb(bashable)|mfb(place_item)},
{N_("glass door fridge"),'{', c_ltcyan,  0, tr_null,
        mfb(collapses)|mfb(bashable)|mfb(place_item)},
{N_("dresser"),          '{', c_brown,   0, tr_null,
        mfb(transparent)|mfb(container)|mfb(flammable)|mfb(collapses)|
        mfb(bashable)|mfb(deconstruct)|mfb(place_item)},
{N_("locker"),           '{', c_ltgray,  0, tr_null,
        mfb(container)|mfb(collapses)|mfb(bashable)|mfb(place_item)},
{N_("display rack"),     '{', c_ltgray,  0, tr_null,
        mfb(transparent)|mfb(l_flammable)|mfb(collapses)|mfb(bashable)|
        mfb(deconstruct)|mfb(place_item)},
{N_("book case"),        '{', c_brown,   0, tr_null,
        mfb(flammable)|mfb(collapses)|mfb(bashable)|mfb(deconstruct)|mfb(place_item)},
{N_("dumpster"),	     '{', c_green,   0, tr_null,
        mfb(container)|mfb(bashable)|mfb(place_item)},
{N_("cloning vat"),      '0', c_ltcyan,  0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(sealed)|mfb(place_item)},
{N_("crate"),            'X', i_brown,   0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(container)|mfb(sealed)|
        mfb(flammable)|mfb(deconstruct)|mfb(place_item)},
{N_("open crate"),       'O', i_brown,   0, tr_null,
        mfb(transparent)|mfb(bashable)|mfb(container)|mfb(flammable)|mfb(place_item)},
{N_("stairs down"),      '>', c_yellow,  2, tr_null,
        mfb(transparent)|mfb(goes_down)|mfb(place_item)},
{N_("stairs up"),        '<', c_yellow,  2, tr_null,
        mfb(transparent)|mfb(goes_up)|mfb(place_item)},
{N_("manhole"),          '>', c_dkgray,  2, tr_null,
        mfb(transparent)|mfb(goes_down)|mfb(place_item)},
{N_("ladder"),           '<', c_dkgray,  2, tr_null,
        mfb(transparent)|mfb(goes_up)|mfb(place_item)},
{N_("ladder"),           '>', c_dkgray,  2, tr_null,
        mfb(transparent)|mfb(goes_down)|mfb(place_item)},
{N_("downward slope"),   '>', c_brown,   2, tr_null,
        mfb(transparent)|mfb(goes_down)|mfb(place_item)},
{N_("upward slope"),     '<', c_brown,   2, tr_null,
        mfb(transparent)|mfb(goes_up)|mfb(place_item)},
{N_("rope leading up"),  '<', c_white,   2, tr_null,
	mfb(transparent)|mfb(goes_up)},
{N_("manhole cover"),    '0', c_dkgray,  2, tr_null,
	mfb(transparent)},
{N_("card reader"),	     '6', c_pink,    0, tr_null,	// Science
	mfb(noitem)},
{N_("card reader"),	     '6', c_pink,    0, tr_null,	// Military
	mfb(noitem)},
{N_("broken card reader"),'6',c_ltgray,  0, tr_null,
	mfb(noitem)},
{N_("slot machine"),     '6', c_green,   0, tr_null,
	mfb(bashable)|mfb(noitem)},
{N_("elevator controls"),'6', c_ltblue,  0, tr_null,
	mfb(noitem)},
{N_("powerless controls"),'6',c_ltgray,  0, tr_null,
	mfb(noitem)},
{N_("elevator"),         '.', c_magenta, 2, tr_null,
	0},
{N_("dark pedestal"),    '&', c_dkgray,  0, tr_null,
	mfb(transparent)},
{N_("light pedestal"),   '&', c_white,   0, tr_null,
	mfb(transparent)},
{N_("red stone"),        '#', c_red,     0, tr_null,
	0},
{N_("green stone"),      '#', c_green,   0, tr_null,
	0},
{N_("blue stone"),       '#', c_blue,    0, tr_null,
	0},
{N_("red floor"),        '.', c_red,     2, tr_null,
	mfb(transparent)},
{N_("green floor"),      '.', c_green,   2, tr_null,
	mfb(transparent)},
{N_("blue floor"),       '.', c_blue,    2, tr_null,
	mfb(transparent)},
{N_("yellow switch"),    '6', c_yellow,  0, tr_null,
	mfb(transparent)},
{N_("cyan switch"),      '6', c_cyan,    0, tr_null,
	mfb(transparent)},
{N_("purple switch"),    '6', c_magenta, 0, tr_null,
	mfb(transparent)},
{N_("checkered switch"), '6', c_white,   0, tr_null,
	mfb(transparent)},
{N_("mutated poppy flower"), 'f', c_red, 3, tr_null,
        mfb(transparent)}
};

enum map_extra {
 mx_null = 0,
 mx_helicopter,
 mx_military,
 mx_science,
 mx_stash,
 mx_drugdeal,
 mx_supplydrop,
 mx_portal,
 mx_minefield,
 mx_wolfpack,
 mx_cougar,
 mx_puddle,
 mx_crater,
 mx_fumarole,
 mx_portal_in,
 mx_anomaly,
 num_map_extras
};

// Chances are relative to eachother; e.g. a 200 chance is twice as likely
// as a 100 chance to appear.
const int map_extra_chance[num_map_extras + 1] = {
  0,	// Null - 0 chance
 40,	// Helicopter
 50,	// Military
120,	// Science
200,	// Stash
 20,	// Drug deal
 10, // Supply drop
  5,	// Portal
 70,	// Minefield
 30,	// Wolf pack
 40, // Cougar
250,	// Puddle
 10,	// Crater
  8,	// Fumarole
  7,	// One-way portal into this world
 10,	// Anomaly
  0	 // Just a cap value; leave this as the last one
};

struct map_extras {
 unsigned int chance;
 int chances[num_map_extras + 1];
 map_extras(unsigned int embellished, int helicopter = 0, int mili = 0,
            int sci = 0, int stash = 0, int drug = 0, int supply = 0,
            int portal = 0, int minefield = 0, int wolves = 0, int cougar = 0, int puddle = 0,
            int crater = 0, int lava = 0, int marloss = 0, int anomaly = 0)
            : chance(embellished)
 {
  chances[ 0] = 0;
  chances[ 1] = helicopter;
  chances[ 2] = mili;
  chances[ 3] = sci;
  chances[ 4] = stash;
  chances[ 5] = drug;
  chances[ 6] = supply;
  chances[ 7] = portal;
  chances[ 8] = minefield;
  chances[ 9] = wolves;
  chances[10] = cougar;
  chances[11] = puddle;
  chances[12] = crater;
  chances[13] = lava;
  chances[14] = marloss;
  chances[15] = anomaly;
  chances[16] = 0;
 }
};

struct field_t {
 std::string name[3];
 char sym;
 nc_color color[3];
 bool transparent[3];
 bool dangerous[3];
 int halflife;	// In turns
};

enum field_id {
 fd_null = 0,
 fd_blood,
 fd_bile,
 fd_web,
 fd_slime,
 fd_acid,
 fd_sap,
 fd_fire,
 fd_smoke,
 fd_toxic_gas,
 fd_tear_gas,
 fd_nuke_gas,
 fd_gas_vent,
 fd_fire_vent,
 fd_flame_burst,
 fd_electricity,
 fd_fatigue,
 fd_push_items,
 fd_shock_vent,
 fd_acid_vent,
 num_fields
};

const field_t fieldlist[] = {
{{"",	"",	""},					'%',
 {c_white, c_white, c_white},	{true, true, true}, {false, false, false},   0},

{{N_("blood splatter"), N_("blood stain"), N_("puddle of blood")},	'%',
 {c_red, c_red, c_red},		{true, true, true}, {false, false, false},2500},

{{N_("bile splatter"), N_("bile stain"), N_("puddle of bile")},	'%',
 {c_pink, c_pink, c_pink},	{true, true, true}, {false, false, false},2500},

{{N_("cobwebs"),N_("webs"), N_("thick webs")},			'}',
 {c_white, c_white, c_white},	{true, true, false},{false, false, false},   0},

{{N_("slime trail"), N_("slime stain"), N_("puddle of slime")},	'%',
 {c_ltgreen, c_ltgreen, c_green},{true, true, true},{false, false, false},2500},

{{N_("acid splatter"), N_("acid streak"), N_("pool of acid")},	'5',
 {c_ltgreen, c_green, c_green},	{true, true, true}, {true, true, true},	    10},

{{N_("sap splatter"), N_("glob of sap"), N_("pool of sap")},	'5',
 {c_yellow, c_brown, c_brown},	{true, true, true}, {true, true, true},     20},

{{N_("small fire"),	N_("fire"),	N_("raging fire")},			'4',
 {c_yellow, c_ltred, c_red},	{true, true, true}, {true, true, true},	   800},

{{N_("thin smoke"),	N_("smoke"), N_("thick smoke")},		'8',
 {c_white, c_ltgray, c_dkgray},	{true, false, false},{false, true, true},  300},

{{N_("hazy cloud"),N_("toxic gas"),N_("thick toxic gas")},		'8',
 {c_white, c_ltgreen, c_green}, {true, false, false},{false, true, true},  900},

{{N_("hazy cloud"),N_("tear gas"),N_("thick tear gas")},		'8',
 {c_white, c_yellow, c_brown},	{true, false, false},{true, true, true},   600},

{{N_("hazy cloud"),N_("radioactive gas"), N_("thick radioactive gas")}, '8',
 {c_white, c_ltgreen, c_green},	{true, true, false}, {true, true, true},  1000},

{{N_("gas vent"), N_("gas vent"), N_("gas vent")}, '%',
 {c_white, c_white, c_white}, {true, true, true}, {false, false, false}, 0},

{{"", "", ""}, '&', // fire vents
 {c_white, c_white, c_white}, {true, true, true}, {false, false, false}, 0},

{{N_("fire"), N_("fire"), N_("fire")}, '5',
 {c_red, c_red, c_red}, {true, true, true}, {true, true, true}, 0},

{{N_("sparks"), N_("electric crackle"), N_("electric cloud")},	'9',
 {c_white, c_cyan, c_blue},	{true, true, true}, {true, true, true},	     2},

{{N_("odd ripple"), N_("swirling air"), N_("tear in reality")},	'*',
 {c_ltgray, c_dkgray, c_magenta},{true, true, false},{false, false, false},  0},

{{"", "", ""}, '&', // push items
 {c_white, c_white, c_white}, {true, true, true}, {false, false, false}, 0},

{{"", "", ""}, '&', // shock vents
 {c_white, c_white, c_white}, {true, true, true}, {false, false, false}, 0},

{{"", "", ""}, '&', // acid vents
 {c_white, c_white, c_white}, {true, true, true}, {false, false, false}, 0}
};

struct field {
 field_id type;
 signed char density;
 int age;
 field() { type = fd_null; density = 1; age = 0; };
 field(field_id t, unsigned char d, unsigned int a) {
  type = t;
  density = d;
  age = a;
 }

 bool is_null()
 {
  return (type == fd_null || type == fd_blood || type == fd_bile ||
          type == fd_slime);
 }

 bool is_dangerous()
 {
  return fieldlist[type].dangerous[density - 1];
 }

 std::string name()
 {
  return fieldlist[type].name[density - 1];
 }

};

struct spawn_point {
 int posx, posy;
 int count;
 mon_id type;
 int faction_id;
 int mission_id;
 bool friendly;
 std::string name;
 spawn_point(mon_id T = mon_null, int C = 0, int X = -1, int Y = -1,
             int FAC = -1, int MIS = -1, bool F = false,
             std::string N = "NONE") :
             posx (X), posy (Y), count (C), type (T), faction_id (FAC),
             mission_id (MIS), friendly (F), name (N) {}
};

struct submap {
 ter_id			ter[SEEX][SEEY]; // Terrain on each square
 std::vector<item>	itm[SEEX][SEEY]; // Items on each square
 trap_id		trp[SEEX][SEEY]; // Trap on each square
 field			fld[SEEX][SEEY]; // Field on each square
 int			rad[SEEX][SEEY]; // Irradiation of each square
 graffiti graf[SEEX][SEEY]; // Graffiti on each square
 int active_item_count;
 int field_count;
 int turn_last_touched;
 std::vector<spawn_point> spawns;
 std::vector<vehicle*> vehicles;
 computer comp;
 basecamp camp;  // only allowing one basecamp per submap
};

std::ostream & operator<<(std::ostream &, const submap *);
std::ostream & operator<<(std::ostream &, const submap &);

#endif
