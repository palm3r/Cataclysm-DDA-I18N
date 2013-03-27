#include "faction.h"
#include <string>

extern std::string faction_adj_pos[15];
extern std::string faction_adj_neu[15];
extern std::string faction_adj_bad[15];
extern std::string faction_noun_strong[15];
extern std::string faction_noun_sneak[15];
extern std::string faction_noun_crime[15];
extern std::string faction_noun_cult[15];
extern std::string faction_noun_none[15];

struct faction_value_datum {
 std::string name;
 int good;	// A measure of how "good" the value is (naming purposes &c)
 int strength;
 int sneak;
 int crime;
 int cult;
};

extern faction_value_datum facgoal_data[NUM_FACGOALS];
extern faction_value_datum facjob_data[NUM_FACJOBS];
extern faction_value_datum facval_data[NUM_FACVALS];
