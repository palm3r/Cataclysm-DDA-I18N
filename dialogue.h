#ifndef _DIALOGUE_H_
#define _DIALOGUE_H_

#include "player.h"
#include "output.h"
#include "npc.h"
#include <vector>
#include <string>
#include "mission.h"

struct dialogue {
 player *alpha;
 npc *beta;
 WINDOW *win;
 bool done;
 std::vector<std::string> history;
 std::vector<talk_topic> topic_stack;

 int opt(std::string challenge, ...);
 talk_topic opt(talk_topic topic, game *g);

 dialogue()
 {
  alpha = NULL;
  beta = NULL;
  win = NULL;
  done = false;
 }
};

struct talk_function
{
 void nothing			(game *g, npc *p) {};
 void assign_mission		(game *g, npc *p);
 void mission_success		(game *g, npc *p);
 void mission_failure		(game *g, npc *p);
 void clear_mission		(game *g, npc *p);
 void mission_reward		(game *g, npc *p);
 void mission_favor		(game *g, npc *p);
 void give_equipment		(game *g, npc *p);
 void start_trade		(game *g, npc *p);
 void assign_base(game *g, npc *p);
 void follow			(game *g, npc *p); // p follows u
 void deny_follow		(game *g, npc *p); // p gets DI_ASKED_TO_FOLLOW
 void deny_lead			(game *g, npc *p); // p gets DI_ASKED_TO_LEAD
 void deny_equipment		(game *g, npc *p); // p gets DI_ASKED_FOR_ITEM
 void enslave			(game *g, npc *p) {}; // p becomes slave of u
 void hostile			(game *g, npc *p); // p turns hostile to u
 void flee			(game *g, npc *p);
 void leave			(game *g, npc *p); // p becomes indifferant

 void start_mugging		(game *g, npc *p);
 void player_leaving		(game *g, npc *p);

 void drop_weapon		(game *g, npc *p);
 void player_weapon_away	(game *g, npc *p);
 void player_weapon_drop	(game *g, npc *p);

 void lead_to_safety		(game *g, npc *p);
 void start_training		(game *g, npc *p);

 void toggle_use_guns		(game *g, npc *p);
 void toggle_use_silent	(game *g, npc *p);
 void toggle_use_grenades	(game *g, npc *p);
 void set_engagement_none	(game *g, npc *p);
 void set_engagement_close	(game *g, npc *p);
 void set_engagement_weak	(game *g, npc *p);
 void set_engagement_hit	(game *g, npc *p);
 void set_engagement_all	(game *g, npc *p);
};

enum talk_trial
{
 TALK_TRIAL_NONE, // No challenge here!
 TALK_TRIAL_LIE, // Straight up lying
 TALK_TRIAL_PERSUADE, // Convince them
 TALK_TRIAL_INTIMIDATE, // Physical intimidation
 NUM_TALK_TRIALS
};

extern std::string talk_trial_text[NUM_TALK_TRIALS];

struct talk_response
{
 std::string text;
 talk_trial trial;
 int difficulty;
 int mission_index;
 mission_id miss;	// If it generates a new mission
 int tempvalue;		// Used for various stuff
 npc_opinion opinion_success;
 npc_opinion opinion_failure;
 void (talk_function::*effect_success)(game *, npc *);
 void (talk_function::*effect_failure)(game *, npc *);
 talk_topic success;
 talk_topic failure;

 talk_response()
 {
  text = "";
  trial = TALK_TRIAL_NONE;
  difficulty = 0;
  mission_index = -1;
  miss = MISSION_NULL;
  tempvalue = -1;
  effect_success = &talk_function::nothing;
  effect_failure = &talk_function::nothing;
  opinion_success = npc_opinion();
  opinion_failure = npc_opinion();
  success = TALK_NONE;
  failure = TALK_NONE;
 }

 talk_response(const talk_response &rhs)
 {
  text = rhs.text;
  trial = rhs.trial;
  difficulty = rhs.difficulty;
  mission_index = rhs.mission_index;
  miss = rhs.miss;
  tempvalue = rhs.tempvalue;
  effect_success = rhs.effect_success;
  effect_failure = rhs.effect_failure;
  opinion_success = rhs.opinion_success;
  opinion_failure = rhs.opinion_failure;
  success = rhs.success;
  failure = rhs.failure;
 }
};

struct talk_response_list
{
 std::vector<talk_response> none(game *g, npc *p);
 std::vector<talk_response> shelter(game *g, npc *p);
 std::vector<talk_response> shopkeep(game *g, npc *p);
};

/* There is a array of tag_data, "tags", at the bottom of this file.
 * It maps tags to the array of string replacements;
 * e.g. "<name_g>" => talk_good_names
 * Other tags, like "<yrwp>", are mapped to dynamic things
 *  (like the player's weapon), and are defined in parse_tags() (npctalk.cpp)
 */
struct tag_data
{
 std::string tag;
 const std::string (*replacement)[10];
};

extern std::string talk_needs[num_needs][5];
extern std::string talk_okay[10];
extern std::string talk_no[10];
extern std::string talk_bad_names[10];
extern std::string talk_good_names[10];
extern std::string talk_swear[10];
extern std::string talk_swear_interjection[10];
extern std::string talk_fuck_you[10];
extern std::string talk_very[10];
extern std::string talk_really[10];
extern std::string talk_happy[10];
extern std::string talk_sad[10];
extern std::string talk_greeting_gen[10];
extern std::string talk_ill_die[10];
extern std::string talk_ill_kill_you[10];
extern std::string talk_drop_weapon[10];
extern std::string talk_hands_up[10];
extern std::string talk_no_faction[10];
extern std::string talk_come_here[10];
extern std::string talk_keep_up[10];
extern std::string talk_wait[10];
extern std::string talk_let_me_pass[10];
extern std::string talk_move[10];
extern std::string talk_done_mugging[10];
extern std::string talk_leaving[10];
extern std::string talk_catch_up[10];

#define NUM_STATIC_TAGS 26

const tag_data talk_tags[NUM_STATIC_TAGS] = {
{"<okay>",		&talk_okay},
{"<no>",		&talk_no},
{"<name_b>",		&talk_bad_names},
{"<name_g>",		&talk_good_names},
{"<swear>",		&talk_swear},
{"<swear!>",		&talk_swear_interjection},
{"<fuck_you>",		&talk_fuck_you},
{"<very>",		&talk_very},
{"<really>",		&talk_really},
{"<happy>",		&talk_happy},
{"<sad>",		&talk_sad},
{"<greet>",		&talk_greeting_gen},
{"<ill_die>",		&talk_ill_die},
{"<ill_kill_you>",	&talk_ill_kill_you},
{"<drop_it>",		&talk_drop_weapon},
{"<hands_up>",		&talk_hands_up},
{"<no_faction>",	&talk_no_faction},
{"<come_here>",		&talk_come_here},
{"<keep_up>",		&talk_keep_up},
{"<lets_talk>",		&talk_come_here},
{"<wait>",		&talk_wait},
{"<let_me_pass>",	&talk_let_me_pass},
{"<move>",		&talk_move},
{"<done_mugging>",	&talk_done_mugging},
{"<catch_up>",		&talk_catch_up},
{"<im_leaving_you>",	&talk_leaving}
};

#endif
