#include "dialogue.h"
#include "i18n.h"

extern std::string talk_trial_text[NUM_TALK_TRIALS];
std::string talk_trial_text[NUM_TALK_TRIALS] = {
"", N_("LIE"), N_("PERSUADE"), N_("INTIMIDATE")
};

extern std::string talk_needs[num_needs][5];
std::string talk_needs[num_needs][5] = {
{"", "", "", "", ""},
{N_("Hey<punc> You got any <ammo>?"), N_("I'll need some <ammo> soon, got any?"),
 N_("I really need some <ammo><punc>"), N_("I need <ammo> for my <mywp>, got any?"),
 N_("I need some <ammo> <very> bad<punc>")},
{N_("Got anything I can use as a weapon?"),
 N_("<ill_die> without a good weapon<punc>"),
 N_("I'm sick of fighting with my <swear> <mywp>, got something better?"),
 N_("Hey <name_g>, care to sell me a weapon?"),
 N_("My <mywp> just won't cut it, I need a real weapon...")},
{N_("Hey <name_g>, I could really use a gun."),
 N_("Hey, you got a spare gun?  It'd be better than my <swear> <mywp><punc>"),
 N_("<ill_die> if I don't find a gun soon!"),
 N_("<name_g><punc> Feel like selling me a gun?"),
 N_("I need a gun, any kind will do!")},
{N_("I could use some food, here."), N_("I need some food, <very> bad!"),
 N_("Man, am I <happy> to see you!  Got any food to trade?"),
 N_("<ill_die> unless I get some food in me<punc> <okay>?"),
 N_("Please tell me you have some food to trade!")},
{N_("Got anything to drink?"), N_("I need some water or something."),
 N_("<name_g>, I need some water... got any?"),
 N_("<ill_die> without something to drink."), N_("You got anything to drink?")}
/*
{"<ill_die> unless I get healed<punc>", "You gotta heal me up, <name_g><punc>",
 "Help me<punc> <ill_die> if you don't heal me<punc>",
 "Please... I need medical help<punc>", "
*/
};

extern std::string talk_okay[10];
std::string talk_okay[10] = {
N_("okay"), N_("get it"), N_("you dig"), N_("dig"), N_("got it"), N_("you see"), N_("see, <name_g>"),
N_("alright"), N_("that clear")};

extern std::string talk_no[10];
std::string talk_no[10] = {
N_("no"), N_("fuck no"), N_("hell no"), N_("no way"), N_("not a chance"),
N_("I don't think so"), N_("no way in hell"), N_("nuh uh"), N_("nope"), N_("fat chance")};

extern std::string talk_bad_names[10];
std::string talk_bad_names[10] = {
N_("punk"),   N_("bitch"),  N_("dickhead"), N_("asshole"),  N_("fucker"),
N_("sucker"), N_("fuckwad"),  N_("cocksucker"), N_("motherfucker"), N_("shithead")};

extern std::string talk_good_names[10];
std::string talk_good_names[10] = {
N_("stranger"), N_("friend"), N_("pilgrim"),  N_("traveler"), N_("pal"),
N_("fella"),  N_("you"),    N_("dude"),   N_("buddy"),  N_("man")};

extern std::string talk_swear[10];
std::string talk_swear[10] = { // e.g. N_("drop the <swear> weapon")
N_("fucking"), N_("goddamn"), N_("motherfucking"), N_("freaking"), N_("damn"), N_("<swear> <swear>"),
N_("fucking"), N_("fuckin'"), N_("god damn"), N_("mafuckin'")};

extern std::string talk_swear_interjection[10];
std::string talk_swear_interjection[10] = {
N_("fuck"), N_("damn"), N_("damnit"), N_("shit"), N_("cocksucker"), N_("crap"),
N_("motherfucker"), N_("<swear><punc> <swear!>"), N_("<very> <swear!>"), N_("son of a bitch")};

extern std::string talk_fuck_you[10];
std::string talk_fuck_you[10] = {
N_("fuck you"), N_("fuck off"), N_("go fuck yourself"), N_("<fuck_you>, <name_b>"),
N_("<fuck_you>, <swear> <name_b>"), N_("<name_b>"), N_("<swear> <name_b>"),
N_("fuck you"), N_("fuck off"), N_("go fuck yourself")};

extern std::string talk_very[10];
std::string talk_very[10] = { // Synonyms for N_("very") -- applied to adjectives
N_("really"), N_("fucking"), N_("super"), N_("wicked"), N_("very"), N_("mega"), N_("uber"), N_("ultra"),
N_("so <very>"), N_("<very> <very>")};

extern std::string talk_really[10];
std::string talk_really[10] = { // Synonyms for N_("really") -- applied to verbs
N_("really"), N_("fucking"), N_("absolutely"), N_("definitely"), N_("for real"), N_("honestly"),
N_("<really> <really>"), N_("most <really>"), N_("urgently"), N_("REALLY")};

extern std::string talk_happy[10];
std::string talk_happy[10] = {
N_("glad"), N_("happy"), N_("overjoyed"), N_("ecstatic"), N_("thrilled"), N_("stoked"),
N_("<very> <happy>"), N_("tickled pink"), N_("delighted"), N_("pumped")};

extern std::string talk_sad[10];
std::string talk_sad[10] = {
N_("sad"), N_("bummed"), N_("depressed"), N_("pissed"), N_("unhappy"), N_("<very> <sad>"), N_("dejected"),
N_("down"), N_("blue"), N_("glum")};

extern std::string talk_greeting_gen[10];
std::string talk_greeting_gen[10] = {
N_("Hey <name_g>."), N_("Greetings <name_g>."), N_("Hi <name_g><punc> You okay?"),
N_("<name_g><punc>  Let's talk."), N_("Well hey there."),
N_("<name_g><punc>  Hello."), N_("What's up, <name_g>?"), N_("You okay, <name_g>?"),
N_("Hello, <name_g>."), N_("Hi <name_g>")};

extern std::string talk_ill_die[10];
std::string talk_ill_die[10] = {
N_("I'm not gonna last much longer"), N_("I'll be dead soon"), N_("I'll be a goner"),
N_("I'm dead, <name_g>,"), N_("I'm dead meat"), N_("I'm in <very> serious trouble"),
N_("I'm <very> doomed"), N_("I'm done for"), N_("I won't last much longer"),
N_("my days are <really> numbered")};

extern std::string talk_ill_kill_you[10];
std::string talk_ill_kill_you[10] = {
N_("I'll kill you"), N_("you're dead"), N_("I'll <swear> kill you"), N_("you're dead meat"),
N_("<ill_kill_you>, <name_b>"), N_("you're a dead <man>"), N_("you'll taste my <mywp>"),
N_("you're <swear> dead"), N_("<name_b>, <ill_kill_you>")};

extern std::string talk_drop_weapon[10];
std::string talk_drop_weapon[10] = {
N_("Drop your <swear> weapon!"),
N_("Okay <name_b>, drop your weapon!"),
N_("Put your <swear> weapon down!"),
N_("Drop the <yrwp>, <name_b>!"),
N_("Drop the <swear> <yrwp>!"),
N_("Drop your <yrwp>!"),
N_("Put down the <yrwp>!"),
N_("Drop your <swear> weapon, <name_b>!"),
N_("Put down your <yrwp>!"),
N_("Alright, drop the <yrwp>!")
};

extern std::string talk_hands_up[10];
std::string talk_hands_up[10] = {
N_("Put your <swear> hands up!"),
N_("Put your hands up, <name_b>!"),
N_("Reach for the sky!"),
N_("Hands up!"),
N_("Hands in the air!"),
N_("Hands up, <name_b>!"),
N_("Hands where I can see them!"),
N_("Okay <name_b>, hands up!"),
N_("Okay <name_b><punc> hands up!"),
N_("Hands in the air, <name_b>!")
};

extern std::string talk_no_faction[10];
std::string talk_no_faction[10] = {
N_("I'm unaffiliated."),
N_("I don't run with a crew."),
N_("I'm a solo artist, <okay>?"),
N_("I don't kowtow to any group, <okay>?"),
N_("I'm a freelancer."),
N_("I work alone, <name_g>."),
N_("I'm a free agent, more money that way."),
N_("I prefer to work uninhibited by that kind of connection."),
N_("I haven't found one that's good enough for me."),
N_("I don't belong to a faction, <name_g>.")
};

extern std::string talk_come_here[10];
std::string talk_come_here[10] = {
N_("Wait up, let's talk!"),
N_("Hey, I <really> want to talk to you!"),
N_("Come on, talk to me!"),
N_("Hey <name_g>, let's talk!"),
N_("<name_g>, we <really> need to talk!"),
N_("Hey, we should talk, <okay>?"),
N_("<name_g>!  Wait up!"),
N_("Wait up, <okay>?"),
N_("Let's talk, <name_g>!"),
N_("Look, <name_g><punc> let's talk!")
};

extern std::string talk_keep_up[10];
std::string talk_keep_up[10] = {
N_("Catch up!"),
N_("Get over here!"),
N_("Catch up, <name_g>!"),
N_("Keep up!"),
N_("Come on, <catch_up>!"),
N_("Keep it moving!"),
N_("Stay with me!"),
N_("Keep close!"),
N_("Stay close!"),
N_("Let's keep going!")
};

extern std::string talk_wait[10];
std::string talk_wait[10] = {
N_("Hey, where are you?"),
N_("Wait up, <name_g>!"),
N_("<name_g>, wait for me!"),
N_("Hey, wait up, <okay>?"),
N_("You <really> need to wait for me!"),
N_("You <swear> need to wait!"),
N_("<name_g>, where are you?"),
N_("Hey <name_g><punc> Wait for me!"),
N_("Where are you?!"),
N_("Hey, I'm over here!")
};

extern std::string talk_let_me_pass[10];
std::string talk_let_me_pass[10] = {
N_("Excuse me, let me pass."),
N_("Hey <name_g>, can I get through?"),
N_("Let me get past you, <name_g>."),
N_("Let me through, <okay>?"),
N_("Can I get past you, <name_g>?"),
N_("I need to get past you, <name_g>."),
N_("Move your <swear> ass, <name_b>!"),
N_("Out of my way, <name_b>!"),
N_("Move it, <name_g>!"),
N_("You need to move, <name_g>, <okay>?")
};

// Used to tell player to move to avoid friendly fire
extern std::string talk_move[10];
std::string talk_move[10] = {
N_("Move"),
N_("Move your ass"),
N_("Get out of the way"),
N_("You need to move"),
N_("Hey <name_g>, move"),
N_("<swear> move it"),
N_("Move your <swear> ass"),
N_("Get out of my way, <name_b>,"),
N_("Move to the side"),
N_("Get out of my line of fire")
};

extern std::string talk_done_mugging[10];
std::string talk_done_mugging[10] = {
N_("Thanks for the cash, <name_b>!"),
N_("So long, <name_b>!"),
N_("Thanks a lot, <name_g>!"),
N_("Catch you later, <name_g>!"),
N_("See you later, <name_b>!"),
N_("See you in hell, <name_b>!"),
N_("Hasta luego, <name_g>!"),
N_("I'm outta here! <done_mugging>"),
N_("Bye bye, <name_b>!"),
N_("Thanks, <name_g>!")
};

extern std::string talk_leaving[10];
std::string talk_leaving[10] = {
N_("So long, <name_b>!"),
N_("Hasta luego, <name_g>!"),
N_("I'm outta here!"),
N_("Bye bye, <name_b>!"),
N_("So long, <name_b>!"),
N_("Hasta luego, <name_g>!"),
N_("I'm outta here!"),
N_("Bye bye, <name_b>!"),
N_("I'm outta here!"),
N_("Bye bye, <name_b>!")
};

extern std::string talk_catch_up[10];
std::string talk_catch_up[10] = {
N_("You're too far away, <name_b>!"),
N_("Hurry up, <name_g>!"),
N_("I'm outta here soon!"),
N_("Come on molasses!"),
N_("What's taking so long?"),
N_("Get with the program laggard!"),
N_("Did the zombies get you?"),
N_("Wait up <name_b>!"),
N_("Did you evolve from a snail?"),
N_("How 'bout picking up the pace!")
};
