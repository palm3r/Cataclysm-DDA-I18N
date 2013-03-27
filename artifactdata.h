#ifndef _ARTIFACTDATA_H_
#define _ARTIFACTDATA_H_

#include <vector>
#include "artifact.h"
#include "itype.h"

const int passive_effect_cost[NUM_AEPS] = {
0,	// AEP_NULL

3,	// AEP_STR_UP
3,	// AEP_DEX_UP
3,	// AEP_PER_UP
3,	// AEP_INT_UP
5,	// AEP_ALL_UP
4,	// AEP_SPEED_UP
2,	// AEP_IODINE
4,	// AEP_SNAKES
7,	// AEP_INVISIBLE
5,	// AEP_CLAIRVOYANCE
2,	// AEP_STEALTH
2,	// AEP_EXTINGUISH
1,	// AEP_GLOW
1,	// AEP_PSYSHIELD
3,	// AEP_RESIST_ELECTRICITY
3,	// AEP_CARRY_MORE
5,	// AEP_SAP_LIFE

0,	// AEP_SPLIT

-2,	// AEP_HUNGER
-2,	// AEP_THIRST
-1,	// AEP_SMOKE
-5,	// AEP_EVIL
-3,	// AEP_SCHIZO
-5,	// AEP_RADIOACTIVE
-3,	// AEP_MUTAGENIC
-5,	// AEP_ATTENTION
-2,	// AEP_STR_DOWN
-2,	// AEP_DEX_DOWN
-2,	// AEP_PER_DOWN
-2,	// AEP_INT_DOWN
-5,	// AEP_ALL_DOWN
-4,	// AEP_SPEED_DOWN
-5,	// AEP_FORCE_TELEPORT
-3,	// AEP_MOVEMENT_NOISE
-2,	// AEP_BAD_WEATHER
-1	// AEP_SICK
};

const int active_effect_cost[NUM_AEAS] = {
 0, // AEA_NULL

 2, // AEA_STORM
 4, // AEA_FIREBALL
 5, // AEA_ADRENALINE
 4, // AEA_MAP
 0, // AEA_BLOOD
 0, // AEA_FATIGUE
 4, // AEA_ACIDBALL
 5, // AEA_PULSE
 4, // AEA_HEAL
 3, // AEA_CONFUSED
 3, // AEA_ENTRANCE
 3, // AEA_BUGS
 5, // AEA_TELEPORT
 1, // AEA_LIGHT
 4, // AEA_GROWTH
 6, // AEA_HURTALL

 0, // AEA_SPLIT

-3, // AEA_RADIATION
-2, // AEA_PAIN
-3, // AEA_MUTATE
-2, // AEA_PARALYZE
-3, // AEA_FIRESTORM
-6, // AEA_ATTENTION
-4, // AEA_TELEGLOW
-2, // AEA_NOISE
-2, // AEA_SCREAM
-3, // AEA_DIM
-4, // AEA_FLASH
-2, // AEA_VOMIT
-5  // AEA_SHADOWS
};

struct artifact_shape_datum
{
 std::string name;
 std::string desc;
 int volume_min, volume_max;
 int weight_min, weight_max;
};

extern artifact_shape_datum artifact_shape_data[ARTSHAPE_MAX];

struct artifact_property_datum
{
 std::string name;
 std::string desc;
 art_effect_passive passive_good[4];
 art_effect_passive passive_bad[4];
 art_effect_active active_good[4];
 art_effect_active active_bad[4];
};

extern artifact_property_datum artifact_property_data[ARTPROP_MAX];

enum artifact_weapon_type
{
 ARTWEAP_NULL,
 ARTWEAP_BULK,  // A bulky item that works okay for bashing
 ARTWEAP_CLUB,  // An item designed to bash
 ARTWEAP_SPEAR, // A stab-only weapon
 ARTWEAP_SWORD, // A long slasher
 ARTWEAP_KNIFE, // Short, slash and stab
 NUM_ARTWEAPS
};

struct artifact_tool_form_datum
{
 std::string name;
 char sym;
 nc_color color;
 material m1;
 material m2;
 int volume_min, volume_max;
 int weight_min, weight_max;
 artifact_weapon_type base_weapon;
 artifact_weapon_type extra_weapons[3];

/*
 artifact_tool_form_datum
   (std::string Name, char Sym, nc_color Color, material M1, material M2,
    int Volmin, int Volmax, int Wgtmin, int Wgtmax, artifact_weapon_type Base,
    artifact_weapon_type extra[3])
   : name (Name), sym (Sym), color (Color), m1 (M1), m2 (M2),
     volume_min (Volmin), volume_max (Volmax), weight_min (Wgtmin),
     weight_max (Wgtmax), base_weapon (Base), extra_weapons (extra) { };
*/

};

enum artifact_tool_form
{
 ARTTOOLFORM_NULL,
 ARTTOOLFORM_HARP,
 ARTTOOLFORM_STAFF,
 ARTTOOLFORM_SWORD,
 ARTTOOLFORM_KNIFE,
 ARTTOOLFORM_CUBE,
 NUM_ARTTOOLFORMS
};

extern artifact_tool_form_datum artifact_tool_form_data[NUM_ARTTOOLFORMS];

struct artifact_weapon_datum
{
 std::string adjective;
 int volume, weight; // Only applicable if this is an *extra* weapon
 int bash_min, bash_max;
 int cut_min, cut_max;
 int to_hit_min, to_hit_max;
 unsigned flags : NUM_ITEM_FLAGS;
};

extern artifact_weapon_datum artifact_weapon_data[NUM_ARTWEAPS];

enum artifact_armor_mod
{
 ARMORMOD_NULL,
 ARMORMOD_LIGHT,
 ARMORMOD_BULKY,
 ARMORMOD_POCKETED,
 ARMORMOD_FURRED,
 ARMORMOD_PADDED,
 ARMORMOD_PLATED,
 NUM_ARMORMODS
};

struct artifact_armor_form_datum
{
 std::string name;
 nc_color color;
 material m1;
 material m2;
 int volume, weight;
 int encumb;
 int dmg_resist;
 int cut_resist;
 int env_resist;
 int warmth;
 int storage;
 int melee_bash, melee_cut, melee_hit;
 unsigned char covers;
 bool plural;
 artifact_armor_mod available_mods[5];

/*
// Constructor
 artifact_armor_form_datum
   (std::string Name, nc_color Color, material M1, material M2, int Volume,
    int Weight, int Encumb, int Dmg_res, int Cut_res, int Env_res,
    int Warmth, int Storage, int Bash, int Cut, int Hit, unsigned char Covers,
    bool Plural, artifact_armor_mod Mods[5])
   : name (Name), color (Color), m1 (M1), m2 (M2), volume (Volume),
     weight (Weight), encumb (Encumb), dmg_resist (Dmg_res),
     cut_resist (Cut_res), env_resist (Env_res), warmth (Warmth),
     storage (Storage), melee_bash (Bash), melee_cut (Cut), melee_hit (Hit),
     covers (Covers), plural (Plural), available_mods (Mods) { };

*/
};

enum artifact_armor_form
{
 ARTARMFORM_NULL,
 ARTARMFORM_ROBE,
 ARTARMFORM_COAT,
 ARTARMFORM_MASK,
 ARTARMFORM_HELM,
 ARTARMFORM_GLOVES,
 ARTARMFORM_BOOTS,
 ARTARMFORM_RING,
 NUM_ARTARMFORMS
};

extern artifact_armor_form_datum artifact_armor_form_data[NUM_ARTARMFORMS];

/* Armor mods alter the normal values of armor.
 * If the basic armor type has MNULL as its second material, and the mod has a
 * material attached, the second material will be changed.
 */
extern artifact_armor_form_datum artifact_armor_mod_data[NUM_ARMORMODS];

#define NUM_ART_ADJS 20
extern std::string artifact_adj[NUM_ART_ADJS];

#define NUM_ART_NOUNS 20
extern std::string artifact_noun[NUM_ART_NOUNS];

#endif
