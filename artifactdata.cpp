#include "artifactdata.h"
#include "i18n.h"

extern artifact_shape_datum artifact_shape_data[ARTSHAPE_MAX];
artifact_shape_datum artifact_shape_data[ARTSHAPE_MAX] = {
{"BUG", "BUG", 0, 0, 0, 0},
{N_("sphere"), N_("smooth sphere"), 2, 4, 0, 10},
{N_("rod"), N_("tapered rod"), 1, 7, 1, 7},
{N_("teardrop"), N_("teardrop-shaped stone"), 2, 6, 0, 8},
{N_("lamp"), N_("hollow, transparent cube"), 4, 9, 0, 3},
{N_("snake"), N_("winding, flexible rod"), 0, 8, 0, 8},
{N_("disc"), N_("smooth disc"), 4, 6, 2, 4},
{N_("beads"), N_("string of beads"), 3, 7, 0, 6},
{N_("napkin"), N_("very thin sheet"), 0, 3, 0, 3},
{N_("urchin"), N_("spiked sphere"), 3, 5, 2, 6},
{N_("jelly"), N_("malleable blob"), 2, 8, 2, 4},
{N_("spiral"), N_("spiraling rod"), 5, 6, 2, 3},
{N_("pin"), N_("pointed rod"), 1, 5, 1, 9},
{N_("tube"), N_("hollow tube"), 2, 5, 3, 6},
{N_("pyramid"), N_("regular tetrahedron"), 3, 7, 2, 4},
{N_("crystal"), N_("translucent crystal"), 1, 6, 2, 7},
{N_("knot"), N_("twisted, knotted cord"), 2, 6, 1, 7},
{N_("crescent"), N_("crescent-shaped stone"), 2, 6, 2, 6}
};

extern artifact_property_datum artifact_property_data[ARTPROP_MAX];
artifact_property_datum artifact_property_data[ARTPROP_MAX] = {
{"BUG", "BUG",
 {AEP_NULL, AEP_NULL, AEP_NULL, AEP_NULL},
 {AEP_NULL, AEP_NULL, AEP_NULL, AEP_NULL},
 {AEA_NULL, AEA_NULL, AEA_NULL, AEA_NULL},
 {AEA_NULL, AEA_NULL, AEA_NULL, AEA_NULL}
},
{N_("wriggling"), N_("is constantly wriggling"),
 {AEP_SPEED_UP, AEP_SNAKES, AEP_NULL, AEP_NULL},
 {AEP_DEX_DOWN, AEP_FORCE_TELEPORT, AEP_SICK, AEP_NULL},
 {AEA_TELEPORT, AEA_ADRENALINE, AEA_NULL, AEA_NULL},
 {AEA_MUTATE, AEA_ATTENTION, AEA_VOMIT, AEA_NULL}
},
{N_("glowing"), N_("glows faintly"),
 {AEP_INT_UP, AEP_GLOW, AEP_CLAIRVOYANCE, AEP_NULL},
 {AEP_RADIOACTIVE, AEP_MUTAGENIC, AEP_ATTENTION, AEP_NULL},
 {AEA_LIGHT, AEA_LIGHT, AEA_LIGHT, AEA_NULL},
 {AEA_ATTENTION, AEA_TELEGLOW, AEA_FLASH, AEA_SHADOWS}
},
{N_("humming"), N_("hums very quietly"),
 {AEP_ALL_UP, AEP_PSYSHIELD, AEP_NULL, AEP_NULL},
 {AEP_SCHIZO, AEP_PER_DOWN, AEP_INT_DOWN, AEP_NULL},
 {AEA_PULSE, AEA_ENTRANCE, AEA_NULL, AEA_NULL},
 {AEA_NOISE, AEA_NOISE, AEA_SCREAM, AEA_NULL}
},
{N_("moving"), N_("shifts from side to side slowly"),
 {AEP_STR_UP, AEP_DEX_UP, AEP_SPEED_UP, AEP_NULL},
 {AEP_HUNGER, AEP_PER_DOWN, AEP_FORCE_TELEPORT, AEP_NULL},
 {AEA_TELEPORT, AEA_TELEPORT, AEA_MAP, AEA_NULL},
 {AEA_PARALYZE, AEA_VOMIT, AEA_VOMIT, AEA_NULL}
},
{N_("whispering"), N_("makes very faint whispering sounds"),
 {AEP_CLAIRVOYANCE, AEP_EXTINGUISH, AEP_STEALTH, AEP_NULL},
 {AEP_EVIL, AEP_SCHIZO, AEP_ATTENTION, AEP_NULL},
 {AEA_FATIGUE, AEA_ENTRANCE, AEA_ENTRANCE, AEA_NULL},
 {AEA_ATTENTION, AEA_SCREAM, AEA_SCREAM, AEA_SHADOWS}
},
{N_("breathing"),
 N_("shrinks and grows very slightly with a regular pulse, as if breathing"),
 {AEP_SAP_LIFE, AEP_ALL_UP, AEP_SPEED_UP, AEP_CARRY_MORE},
 {AEP_HUNGER, AEP_THIRST, AEP_SICK, AEP_BAD_WEATHER},
 {AEA_ADRENALINE, AEA_HEAL, AEA_ENTRANCE, AEA_GROWTH},
 {AEA_MUTATE, AEA_ATTENTION, AEA_SHADOWS, AEA_NULL}
},
{N_("dead"), N_("is icy cold to the touch"),
 {AEP_INVISIBLE, AEP_CLAIRVOYANCE, AEP_EXTINGUISH, AEP_SAP_LIFE},
 {AEP_HUNGER, AEP_EVIL, AEP_ALL_DOWN, AEP_SICK},
 {AEA_BLOOD, AEA_HURTALL, AEA_NULL, AEA_NULL},
 {AEA_PAIN, AEA_SHADOWS, AEA_DIM, AEA_VOMIT}
},
{N_("itchy"), N_("makes your skin itch slightly when it is close"),
 {AEP_DEX_UP, AEP_SPEED_UP, AEP_PSYSHIELD, AEP_NULL},
 {AEP_RADIOACTIVE, AEP_MUTAGENIC, AEP_SICK, AEP_NULL},
 {AEA_ADRENALINE, AEA_BLOOD, AEA_HEAL, AEA_BUGS},
 {AEA_RADIATION, AEA_PAIN, AEA_PAIN, AEA_VOMIT}
},
{N_("glittering"), N_("glitters faintly under direct light"),
 {AEP_INT_UP, AEP_EXTINGUISH, AEP_GLOW, AEP_NULL},
 {AEP_SMOKE, AEP_ATTENTION, AEP_NULL, AEP_NULL},
 {AEA_MAP, AEA_LIGHT, AEA_CONFUSED, AEA_ENTRANCE},
 {AEA_RADIATION, AEA_MUTATE, AEA_ATTENTION, AEA_FLASH}
},
{N_("electric"), N_("very weakly shocks you when touched"),
 {AEP_RESIST_ELECTRICITY, AEP_DEX_UP, AEP_SPEED_UP, AEP_PSYSHIELD},
 {AEP_THIRST, AEP_SMOKE, AEP_STR_DOWN, AEP_BAD_WEATHER},
 {AEA_STORM, AEA_ADRENALINE, AEA_LIGHT, AEA_NULL},
 {AEA_PAIN, AEA_PARALYZE, AEA_FLASH, AEA_FLASH}
},
{N_("slimy"), N_("feels slimy"),
 {AEP_SNAKES, AEP_STEALTH, AEP_EXTINGUISH, AEP_SAP_LIFE},
 {AEP_THIRST, AEP_DEX_DOWN, AEP_SPEED_DOWN, AEP_SICK},
 {AEA_BLOOD, AEA_ACIDBALL, AEA_GROWTH, AEA_ACIDBALL},
 {AEA_MUTATE, AEA_MUTATE, AEA_VOMIT, AEA_VOMIT}
},
{N_("engraved"), N_("is covered with odd etchings"),
 {AEP_CLAIRVOYANCE, AEP_INVISIBLE, AEP_PSYSHIELD, AEP_SAP_LIFE},
 {AEP_EVIL, AEP_ATTENTION, AEP_NULL, AEP_NULL},
 {AEA_FATIGUE, AEA_TELEPORT, AEA_HEAL, AEA_FATIGUE},
 {AEA_ATTENTION, AEA_ATTENTION, AEA_TELEGLOW, AEA_DIM}
},
{N_("crackling"), N_("occasionally makes a soft crackling sound"),
 {AEP_EXTINGUISH, AEP_RESIST_ELECTRICITY, AEP_NULL, AEP_NULL},
 {AEP_SMOKE, AEP_RADIOACTIVE, AEP_MOVEMENT_NOISE, AEP_NULL},
 {AEA_STORM, AEA_FIREBALL, AEA_PULSE, AEA_NULL},
 {AEA_PAIN, AEA_PARALYZE, AEA_NOISE, AEA_NOISE}
},
{N_("warm"), N_("is warm to the touch"),
 {AEP_STR_UP, AEP_EXTINGUISH, AEP_GLOW, AEP_NULL},
 {AEP_SMOKE, AEP_RADIOACTIVE, AEP_NULL, AEP_NULL},
 {AEA_FIREBALL, AEA_FIREBALL, AEA_FIREBALL, AEA_LIGHT},
 {AEA_FIRESTORM, AEA_FIRESTORM, AEA_TELEGLOW, AEA_NULL}
},
{N_("rattling"), N_("makes a rattling sound when moved"),
 {AEP_DEX_UP, AEP_SPEED_UP, AEP_SNAKES, AEP_CARRY_MORE},
 {AEP_ATTENTION, AEP_INT_DOWN, AEP_MOVEMENT_NOISE, AEP_MOVEMENT_NOISE},
 {AEA_BLOOD, AEA_PULSE, AEA_BUGS, AEA_NULL},
 {AEA_PAIN, AEA_ATTENTION, AEA_NOISE, AEA_NULL}
},
{N_("scaled"), N_("has a surface reminiscent of reptile scales"),
 {AEP_SNAKES, AEP_SNAKES, AEP_SNAKES, AEP_STEALTH},
 {AEP_THIRST, AEP_MUTAGENIC, AEP_SPEED_DOWN, AEP_NULL},
 {AEA_ADRENALINE, AEA_BUGS, AEA_GROWTH, AEA_NULL},
 {AEA_MUTATE, AEA_SCREAM, AEA_DIM, AEA_NULL}
},
{N_("fractal"),
N_("has a self-similar pattern which repeats until it is too small for you to see"),
 {AEP_ALL_UP, AEP_ALL_UP, AEP_CLAIRVOYANCE, AEP_PSYSHIELD},
 {AEP_SCHIZO, AEP_ATTENTION, AEP_FORCE_TELEPORT, AEP_BAD_WEATHER},
 {AEA_STORM, AEA_FATIGUE, AEA_TELEPORT, AEA_NULL},
 {AEA_RADIATION, AEA_MUTATE, AEA_TELEGLOW, AEA_TELEGLOW}
}
};

extern artifact_tool_form_datum artifact_tool_form_data[NUM_ARTTOOLFORMS];
artifact_tool_form_datum artifact_tool_form_data[NUM_ARTTOOLFORMS] = {
{"", '*', c_white, MNULL, MNULL, 0, 0, 0, 0, ARTWEAP_BULK,
 {ARTWEAP_NULL, ARTWEAP_NULL, ARTWEAP_NULL}},

{N_("Harp"), ';', c_yellow, WOOD, MNULL, 20, 30, 10, 18, ARTWEAP_BULK,
 {ARTWEAP_SPEAR, ARTWEAP_SWORD, ARTWEAP_KNIFE}},

{N_("Staff"), '/', c_brown, WOOD, MNULL, 6, 12, 4, 10, ARTWEAP_CLUB,
 {ARTWEAP_BULK, ARTWEAP_SPEAR, ARTWEAP_KNIFE}},

{N_("Sword"), '/', c_ltblue, STEEL, MNULL, 8, 14, 8, 28, ARTWEAP_SWORD,
 {ARTWEAP_BULK, ARTWEAP_NULL, ARTWEAP_NULL}},

{N_("Dagger"), ';', c_ltblue, STEEL, MNULL, 1, 4, 1, 6, ARTWEAP_KNIFE,
 {ARTWEAP_NULL, ARTWEAP_NULL, ARTWEAP_NULL}},

{N_("Cube"), '*', c_white, STEEL, MNULL, 1, 3, 1, 20, ARTWEAP_BULK,
 {ARTWEAP_SPEAR, ARTWEAP_NULL, ARTWEAP_NULL}}
};

extern artifact_weapon_datum artifact_weapon_data[NUM_ARTWEAPS];
artifact_weapon_datum artifact_weapon_data[NUM_ARTWEAPS] = {
{"", 0, 0, 0, 0, 0, 0, 0, 0, 0},
// Adjective  Vol,wgt   Bash    Cut   To-Hit
{N_("Heavy"),  0, 12,   10, 20,    0,  0,   -2,  0,
 0},
{N_("Knobbed"),  1,  2,   14, 30,    0,  0,   -1,  1,
 0},
{N_("Spiked"),   1,  1,    0,  0,   20, 40,   -1,  1,
 mfb(IF_SPEAR)},
{N_("Edged"),  2,  4,    0,  0,   20, 50,   -1,  2,
 0},
{N_("Bladed"),   1,  2,    0,  0,   12, 30,   -1,  1,
 mfb(IF_STAB)}
};

extern artifact_armor_form_datum artifact_armor_form_data[NUM_ARTARMFORMS];
artifact_armor_form_datum artifact_armor_form_data[NUM_ARTARMFORMS] = {
{"", c_white, MNULL, MNULL,        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
 0, false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},
// Name    color  Materials      Vol Wgt Enc Dmg Cut Env Wrm Sto Bsh Cut Hit
{N_("Robe"),   c_red, WOOL, MNULL,     6,  6,  1,  3,  1,  0,  2,  0, -8,  0, -3,
 mfb(bp_torso)|mfb(bp_legs), false,
 {ARMORMOD_LIGHT, ARMORMOD_BULKY, ARMORMOD_POCKETED, ARMORMOD_FURRED,
  ARMORMOD_PADDED}},

{N_("Coat"),   c_brown,LEATHER,MNULL, 14, 14,  2,  4, 12,  1,  4,  4, -6,  0, -3,
 mfb(bp_torso), false,
 {ARMORMOD_LIGHT, ARMORMOD_POCKETED, ARMORMOD_FURRED, ARMORMOD_PADDED,
  ARMORMOD_PLATED}},

{N_("Mask"),   c_white, WOOD, MNULL,   4,  1,  2,  2, 16,  1,  2,  0,  2,  0, -2,
 mfb(bp_eyes)|mfb(bp_mouth), false,
 {ARMORMOD_FURRED, ARMORMOD_FURRED, ARMORMOD_NULL, ARMORMOD_NULL,
  ARMORMOD_NULL}},

// Name    color  Materials      Vol Wgt Enc Dmg Cut Env Wrm Sto Bsh Cut Hit
{N_("Helm"),   c_dkgray,SILVER, MNULL, 6,  6,  2,  4, 18,  0,  1,  0,  8,  0, -2,
 mfb(bp_head), false,
 {ARMORMOD_BULKY, ARMORMOD_FURRED, ARMORMOD_PADDED, ARMORMOD_PLATED,
  ARMORMOD_NULL}},

{N_("Gloves"), c_ltblue,LEATHER,MNULL, 2,  1,  1,  6,  6,  1,  2,  0, -4,  0, -2,
 mfb(bp_hands), true,
 {ARMORMOD_BULKY, ARMORMOD_FURRED, ARMORMOD_PADDED, ARMORMOD_PLATED,
  ARMORMOD_NULL}},

// Name    color  Materials      Vol Wgt Enc Dmg Cut Env Wrm Sto Bsh Cut Hit
{N_("Boots"), c_blue, LEATHER, MNULL,  6,  2,  1,  6,  6,  1,  3,  0,  4,  0, -1,
 mfb(bp_feet), true,
 {ARMORMOD_LIGHT, ARMORMOD_BULKY, ARMORMOD_PADDED, ARMORMOD_PLATED,
  ARMORMOD_NULL}},

{N_("Ring"), c_ltgreen, SILVER, MNULL,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
 0, true,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}}

};

/* Armor mods alter the normal values of armor.
 * If the basic armor type has MNULL as its second material, and the mod has a
 * material attached, the second material will be changed.
 */
extern artifact_armor_form_datum artifact_armor_mod_data[NUM_ARMORMODS];
artifact_armor_form_datum artifact_armor_mod_data[NUM_ARMORMODS] = {

{"", c_white, MNULL, MNULL, 0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},
// Description; N_("It is ...") or N_("They are ...")
{N_("very thin and light."), c_white, MNULL, MNULL,
// Vol Wgt Enc Dmg Cut Env Wrm Sto
    -4, -8, -2, -1, -1, -1, -1,  0, 0, 0, 0, 0,  false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},

{N_("extremely bulky."), c_white, MNULL, MNULL,
     8, 10,  2,  1,  1,  0,  1,  0, 0, 0, 0, 0,  false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},

{N_("covered in pockets."), c_white, MNULL, MNULL,
     1,  1,  1,  0,  0,  0,  0, 16, 0, 0, 0, 0,  false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},

{N_("disgustingly furry."), c_white, WOOL, MNULL,
// Vol Wgt Enc Dmg Cut Env Wrm Sto
     4,  2,  1,  4,  0,  1,  3,  0, 0, 0, 0, 0,  false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},

{N_("leather-padded."), c_white, LEATHER, MNULL,
     4,  4,  1, 10,  4,  0,  1, -3, 0, 0, 0, 0,  false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},

{N_("plated in iron."), c_white, IRON, MNULL,
     4, 12,  3,  8, 14,  0,  1, -4, 0, 0, 0, 0, false,
 {ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL, ARMORMOD_NULL}},

};


extern std::string artifact_adj[NUM_ART_ADJS];
std::string artifact_adj[NUM_ART_ADJS] = {
N_("Forbidden"), N_("Unknown"), N_("Forgotten"), N_("Hideous"), N_("Eldritch"),
N_("Gelatinous"), N_("Ancient"), N_("Cursed"), N_("Bloody"), N_("Undying"),
N_("Shadowy"), N_("Silent"), N_("Cyclopean"), N_("Fungal"), N_("Unspeakable"),
N_("Grotesque"), N_("Frigid"), N_("Shattered"), N_("Sleeping"), N_("Repellent")
};

// Prepending + makes it proper, e.g. "The Forbidden Abyss"
extern std::string artifact_noun[NUM_ART_NOUNS];
std::string artifact_noun[NUM_ART_NOUNS] = {
N_("Technique"), N_("Dreams"), N_("Beasts"), N_("Evil"), N_("Miasma"),
N_("+Abyss"), N_("+City"), N_("Shadows"), N_("Shade"), N_("Illusion"),
N_("Justice"), N_("+Necropolis"), N_("Ichor"), N_("+Monolith"), N_("Aeons"),
N_("Graves"), N_("Horrors"), N_("Suffering"), N_("Death"), N_("Horror")
};
