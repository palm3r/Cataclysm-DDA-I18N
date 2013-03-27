#include "facdata.h"
#include "i18n.h"

extern std::string faction_adj_pos[15];
std::string faction_adj_pos[15] = {
N_("Shining"), N_("Sacred"), N_("Golden"), N_("Holy"), N_("Righteous"), N_("Devoted"), N_("Virtuous"),
N_("Splendid"), N_("Divine"), N_("Radiant"), N_("Noble"), N_("Venerable"), N_("Immaculate"),
N_("Heroic"), N_("Bright")};

extern std::string faction_adj_neu[15];
std::string faction_adj_neu[15] = {
N_("Original"), N_("Crystal"), N_("Metal"), N_("Mighty"), N_("Powerful"), N_("Solid"), N_("Stone"),
N_("Firey"), N_("Colossal"), N_("Famous"), N_("Supreme"), N_("Invincible"), N_("Unlimited"),
N_("Great"), N_("Electric")};

extern std::string faction_adj_bad[15];
std::string faction_adj_bad[15] = {
N_("Poisonous"), N_("Deadly"), N_("Foul"), N_("Nefarious"), N_("Wicked"), N_("Vile"), N_("Ruinous"),
N_("Horror"), N_("Devastating"), N_("Vicious"), N_("Sinister"), N_("Baleful"), N_("Pestilent"),
N_("Pernicious"), N_("Dread")};

extern std::string faction_noun_strong[15];
std::string faction_noun_strong[15] = {
N_("Fists"), N_("Slayers"), N_("Furies"), N_("Dervishes"), N_("Tigers"), N_("Destroyers"),
N_("Berserkers"), N_("Samurai"), N_("Valkyries"), N_("Army"), N_("Killers"), N_("Paladins"),
N_("Knights"), N_("Warriors"), N_("Huntsmen")};

extern std::string faction_noun_sneak[15];
std::string faction_noun_sneak[15] = {
N_("Snakes"), N_("Rats"), N_("Assassins"), N_("Ninja"), N_("Agents"), N_("Shadows"), N_("Guerillas"),
N_("Eliminators"), N_("Snipers"), N_("Smoke"), N_("Arachnids"), N_("Creepers"), N_("Shade"),
N_("Stalkers"), N_("Eels")};

extern std::string faction_noun_crime[15];
std::string faction_noun_crime[15] = {
N_("Bandits"), N_("Punks"), N_("Family"), N_("Mafia"), N_("Mob"), N_("Gang"), N_("Vandals"), N_("Sharks"),
N_("Muggers"), N_("Cutthroats"), N_("Guild"), N_("Faction"), N_("Thugs"), N_("Racket"), N_("Crooks")};

extern std::string faction_noun_cult[15];
std::string faction_noun_cult[15] = {
N_("Brotherhood"), N_("Church"), N_("Ones"), N_("Crucible"), N_("Sect"), N_("Creed"), N_("Doctrine"),
N_("Priests"), N_("Tenet"), N_("Monks"), N_("Clerics"), N_("Pastors"), N_("Gnostics"), N_("Elders"),
N_("Inquisitors")};

extern std::string faction_noun_none[15];
std::string faction_noun_none[15] = {
N_("Settlers"), N_("People"), N_("Men"), N_("Faction"), N_("Tribe"), N_("Clan"), N_("Society"), N_("Folk"),
N_("Nation"), N_("Republic"), N_("Colony"), N_("State"), N_("Kingdom"), N_("Party"), N_("Company")};

extern faction_value_datum facgoal_data[NUM_FACGOALS];
faction_value_datum facgoal_data[NUM_FACGOALS] = {
// "Their ultimate goal is <name>"
//Name        Good  Str Sneak Crime Cult
{"Null",       0,  0,  0,  0,  0},
{N_("basic survival"),     0,  0,  0,  0,  0},
{N_("financial wealth"),     0, -1,  0,  2, -1},
{N_("dominance of the region"), -1,  1, -1,  1, -1},
{N_("the extermination of monsters"),1,  3, -1, -1, -1},
{N_("contact with unseen powers"),  -1,  0,  1,  0,  4},
{N_("bringing the apocalypse"), -5,  1,  2,  0,  7},
{N_("general chaos and anarchy"), -3,  2, -3,  2, -1},
{N_("the cultivation of knowledge"), 2, -3,  2, -1,  0},
{N_("harmony with nature"),    2, -2,  0, -1,  2},
{N_("rebuilding civilization"),  2,  1, -2, -2, -4},
{N_("spreading the fungus"),  -2,  1,  1,  0,  4}
};
// TOTAL:     -5   3  -2   0   7

extern faction_value_datum facjob_data[NUM_FACJOBS];
faction_value_datum facjob_data[NUM_FACJOBS] = {
// "They earn money via <name>"
//Name        Good  Str Sneak Crime Cult
{"Null",       0,  0,  0,  0,  0},
{N_("protection rackets"),    -3,  2, -1,  4,  0},
{N_("the sale of information"), -1, -1,  4,  1,  0},
{N_("their bustling trade centers"), 1, -1, -2, -4, -4},
{N_("trade caravans"),     2, -1, -1, -3, -2},
{N_("scavenging supplies"),    0, -1,  0, -1, -1},
{N_("mercenary work"),     0,  3, -1,  1, -1},
{N_("assassinations"),    -1,  2,  2,  1,  1},
{N_("raiding settlements"),   -4,  4, -3,  3, -2},
{N_("the theft of property"), -3, -1,  4,  4,  1},
{N_("gambling parlors"),    -1, -2, -1,  1, -1},
{N_("medical aid"),      4, -3, -2, -3,  0},
{N_("farming & selling food"),   3, -4, -2, -4,  1},
{N_("drug dealing"),    -2,  0, -1,  2,  0},
{N_("selling manufactured goods"),   1,  0, -1, -2,  0}
};
// TOTAL:     -5  -3  -5   0  -6

extern faction_value_datum facval_data[NUM_FACVALS];
faction_value_datum facval_data[NUM_FACVALS] = {
// "They are known for <name>"
//Name        Good  Str Sneak Crime Cult
{"Null",       0,  0,  0,  0,  0},
{N_("their charitable nature"),  5, -1, -1, -2, -2},
{N_("their isolationism"),     0, -2,  1,  0,  2},
{N_("exploring extensively"),  1,  0,  0, -1, -1},
{N_("collecting rare artifacts"),  0,  1,  1,  0,  3},
{N_("their knowledge of bionics"),   1,  2,  0,  0,  0},
{N_("their libraries"),    1, -3,  0, -2,  1},
{N_("their elite training"),   0,  4,  2,  0,  2},
{N_("their robotics factories"),   0,  3, -1,  0, -2},
{N_("treachery"),     -3,  0,  1,  3,  0},
{N_("the avoidance of drugs"),   1,  0,  0, -1,  1},
{N_("their adherance to the law"),   2, -1, -1, -4, -1},
{N_("their cruelty"),   -3,  1, -1,  4,  1}
};
// TOTALS:       5   4   1  -3   4
/* Note: It's nice to keep the totals around 0 for Good, and about even for the
 * other four.  It's okay if Good is slightly negative (after all, in a post-
 * apocalyptic world people might be a LITTLE less virtuous), and to keep
 * strength valued a bit higher than the others.
 */

