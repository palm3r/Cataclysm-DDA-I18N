#ifndef _PLDATA_H_
#define _PLDATA_H_

#include <sstream>
#include "i18n.h"

enum character_type {
 PLTYPE_CUSTOM,
 PLTYPE_RANDOM,
 PLTYPE_TEMPLATE,
 PLTYPE_MAX
};

const std::string pltype_name[PLTYPE_MAX] = {
N_("Custom Character"), N_("Random Character"), N_("Template Character")};

const std::string pltype_desc[PLTYPE_MAX] = { N_("\
A custom character you design yourself.  A pool of points is used for\n\
statistics, traits, and skills."),
N_("\
A character with stats, traits, and skills chosen randomly."),
N_("\
A character loaded from a template file."),
};

enum dis_type {
 DI_NULL,
// Weather
 DI_GLARE, DI_WET,
// Temperature, the order is important (dependant on bodypart.h)
 DI_COLD,
 DI_COLD_TORSO, DI_COLD_HEAD, DI_COLD_EYES, DI_COLD_MOUTH, 
 DI_COLD_ARMS, DI_COLD_HANDS, DI_COLD_LEGS, DI_COLD_FEET,
 DI_FROSTBITE,
 DI_FROSTBITE_TORSO, DI_FROSTBITE_HEAD, DI_FROSTBITE_EYES, DI_FROSTBITE_MOUTH,
 DI_FROSTBITE_ARMS, DI_FROSTBITE_HANDS, DI_FROSTBITE_LEGS, DI_FROSTBITE_FEET,
 DI_HOT,
 DI_HOT_TORSO, DI_HOT_HEAD, DI_HOT_EYES, DI_HOT_MOUTH, 
 DI_HOT_ARMS, DI_HOT_HANDS, DI_HOT_LEGS, DI_HOT_FEET,
 DI_BLISTERS,
 DI_BLISTERS_TORSO, DI_BLISTERS_HEAD, DI_BLISTERS_EYES, DI_BLISTERS_MOUTH, 
 DI_BLISTERS_ARMS, DI_BLISTERS_HANDS, DI_BLISTERS_LEGS, DI_BLISTERS_FEET,
// Diseases
 DI_INFECTION,
 DI_COMMON_COLD, DI_FLU, DI_RECOVER,
// Fields
 DI_SMOKE, DI_ONFIRE, DI_TEARGAS,
// Monsters
 DI_BOOMERED, DI_SAP, DI_SPORES, DI_FUNGUS, DI_SLIMED,
 DI_DEAF, DI_BLIND,
 DI_LYING_DOWN, DI_SLEEP,
 DI_POISON, DI_BLEED, DI_BADPOISON, DI_FOODPOISON, DI_SHAKES,
 DI_DERMATIK, DI_FORMICATION,
 DI_WEBBED,
 DI_RAT, DI_BITE,
// Food & Drugs
 DI_PKILL1, DI_PKILL2, DI_PKILL3, DI_PKILL_L, DI_DRUNK, DI_CIG, DI_HIGH,
  DI_HALLU, DI_VISUALS, DI_IODINE, DI_TOOK_XANAX, DI_TOOK_PROZAC,
  DI_TOOK_FLUMED, DI_ADRENALINE, DI_ASTHMA, DI_GRACK, DI_METH,
// Traps
 DI_BEARTRAP, DI_LIGHTSNARE, DI_HEAVYSNARE, DI_IN_PIT, DI_STUNNED, DI_DOWNED,
// Martial Arts
 DI_ATTACK_BOOST, DI_DAMAGE_BOOST, DI_DODGE_BOOST, DI_ARMOR_BOOST,
  DI_SPEED_BOOST, DI_VIPER_COMBO,
// Other
 DI_AMIGARA, DI_STEMCELL_TREATMENT, DI_TELEGLOW, DI_ATTENTION, DI_EVIL, DI_INFECTED,
// Inflicted by an NPC
 DI_ASKED_TO_FOLLOW, DI_ASKED_TO_LEAD, DI_ASKED_FOR_ITEM,
// NPC-only
 DI_CATCH_UP
};

enum add_type {
 ADD_NULL,
 ADD_CAFFEINE, ADD_ALCOHOL, ADD_SLEEP, ADD_PKILLER, ADD_SPEED, ADD_CIG,
 ADD_COKE, ADD_CRACK,
};

struct disease
{
 dis_type type;
 int intensity;
 int duration;
 disease() { type = DI_NULL; duration = 0; intensity = 0; }
 disease(dis_type t, int d, int i = 0) { type = t; duration = d; intensity = i;}
};

struct addiction
{
 add_type type;
 int intensity;
 int sated;
 addiction() { type = ADD_NULL; intensity = 0; sated = 600; }
 addiction(add_type t) { type = t; intensity = 1; sated = 600; }
 addiction(add_type t, int i) { type = t; intensity = i; sated = 600; }
};

enum activity_type {
 ACT_NULL = 0,
 ACT_RELOAD, ACT_READ, ACT_WAIT, ACT_CRAFT, ACT_DISASSEMBLE, ACT_BUTCHER, ACT_FORAGE, ACT_BUILD,
 ACT_VEHICLE, ACT_REFILL_VEHICLE,
 ACT_TRAIN,
 NUM_ACTIVITIES
};

struct player_activity
{
 activity_type type;
 int moves_left;
 int index;
 std::vector<int> values;
 point placement;

 player_activity() { type = ACT_NULL; moves_left = 0; index = -1;
                     placement = point(-1, -1); }

 player_activity(activity_type t, int turns, int Index)
 {
  type = t;
  moves_left = turns;
  index = Index;
  placement = point(-1, -1);
 }

 player_activity(const player_activity &copy)
 {
  type = copy.type;
  moves_left = copy.moves_left;
  index = copy.index;
  placement = copy.placement;
  values.clear();
  for (int i = 0; i < copy.values.size(); i++)
   values.push_back(copy.values[i]);
 }

 std::string save_info()
 {
  std::stringstream ret;
  ret << type << " " << moves_left << " " << index << " " << placement.x <<
         " " << placement.y << " " << values.size();
  for (int i = 0; i < values.size(); i++)
   ret << " " << values[i];

  return ret.str();
 }

 void load_info(std::stringstream &dump)
 {
  int tmp, tmptype;
  dump >> tmptype >> moves_left >> index >> placement.x >> placement.y >> tmp;
  type = activity_type(tmptype);
  for (int i = 0; i < tmp; i++) {
   int tmp2;
   dump >> tmp2;
   values.push_back(tmp2);
  }
 }
};

enum pl_flag {
 PF_NULL = 0,
 PF_FLEET,	// -15% terrain movement cost
 PF_PARKOUR,	// Terrain movement cost of 3 or 4 are both 2
 PF_QUICK,	// +10% movement points
 PF_OPTIMISTIC,	// Morale boost
 PF_FASTHEALER,	// Heals faster
 PF_LIGHTEATER,	// Less hungry
 PF_PAINRESIST,	// Effects of pain are reduced
 PF_NIGHTVISION,// Increased sight during the night
 PF_POISRESIST,	// Resists poison, etc
 PF_FASTREADER,	// Reads books faster
 PF_TOUGH,	// Bonus to HP
 PF_THICKSKIN,	// Built-in armor of 1
 PF_PACKMULE,	// Bonus to carried volume
 PF_FASTLEARNER,// Better chance of skills leveling up
 PF_DEFT,	// Less movement penalty for melee miss
 PF_DRUNKEN,	// Having a drunk status improves melee combat
 PF_GOURMAND,	// Faster eating, higher level of max satiated
 PF_ANIMALEMPATH,// Animals attack less
 PF_TERRIFYING,	// All creatures run away more
 PF_DISRESISTANT,// Less likely to succumb to low health; TODO: Implement this
 PF_ADRENALINE,	// Big bonuses when low on HP
 PF_SELFAWARE, // Let's you see exact HP totals
 PF_INCONSPICUOUS,// Less spawns due to timeouts
 PF_MASOCHIST,	// Morale boost from pain
 PF_LIGHTSTEP,	// Less noise from movement
 PF_ANDROID,	// Start with two bionics (occasionally one)
 PF_ROBUST,	// Mutations tend to be good (usually they tend to be bad)
 PF_CANNIBAL, // No penalty for eating human meat
 PF_MARTIAL_ARTS, // Start with a martial art

 PF_SPLIT,	// Null trait, splits between bad & good

 PF_MYOPIC,	// Smaller sight radius UNLESS wearing glasses
 PF_HEAVYSLEEPER, // Sleeps in, won't wake up to sounds as easily
 PF_ASTHMA,	// Occasionally needs medicine or suffers effects
 PF_BADBACK,	// Carries less
 PF_ILLITERATE,	// Can not read books
 PF_BADHEARING,	// Max distance for heard sounds is halved
 PF_INSOMNIA,	// Sleep may not happen
 PF_VEGETARIAN,	// Morale penalty for eating meat
 PF_GLASSJAW,	// Head HP is 15% lower
 PF_FORGETFUL,	// Skills decrement faster
 PF_LIGHTWEIGHT,// Longer DI_DRUNK and DI_HIGH
 PF_ADDICTIVE,	// Better chance of addiction / longer addictive effects
 PF_TRIGGERHAPPY,// Possible chance of unintentional burst fire
 PF_SMELLY,	// Default scent is higher
 PF_CHEMIMBALANCE,// Random tweaks to some values
 PF_SCHIZOPHRENIC,// Random bad effects, variety
 PF_JITTERY,	// Get DI_SHAKES under some circumstances
 PF_HOARDER,	// Morale penalty when volume is less than max
 PF_SAVANT,	// All skills except our best are trained more slowly
 PF_MOODSWINGS,	// Big random shifts in morale
 PF_WEAKSTOMACH,// More likely to throw up in all circumstances
 PF_WOOLALLERGY,// Can't wear wool
 PF_TRUTHTELLER, // Worse at telling lies
 PF_UGLY, // +1 grotesqueness

 PF_MAX,
// Below this point is mutations and other mid-game perks.
// They are NOT available during character creation.
 PF_SKIN_ROUGH,//
 PF_NIGHTVISION2,//
 PF_NIGHTVISION3,//
 PF_INFRARED,//
 PF_FASTHEALER2,//
 PF_REGEN,//
 PF_FANGS,//
 PF_MEMBRANE,//
 PF_GILLS,//
 PF_SCALES,//
 PF_THICK_SCALES,//
 PF_SLEEK_SCALES,//
 PF_LIGHT_BONES,//
 PF_FEATHERS,//
 PF_LIGHTFUR,// TODO: Warmth effects
 PF_FUR,// TODO: Warmth effects
 PF_CHITIN,//
 PF_CHITIN2,//
 PF_CHITIN3,//
 PF_SPINES,//
 PF_QUILLS,//
 PF_PLANTSKIN,//
 PF_BARK,//
 PF_THORNS,
 PF_LEAVES,//
 PF_NAILS,
 PF_CLAWS,
 PF_TALONS,//
 PF_RADIOGENIC,//
 PF_MARLOSS,//
 PF_PHEROMONE_INSECT,//
 PF_PHEROMONE_MAMMAL,//
 PF_DISIMMUNE,
 PF_POISONOUS,//
 PF_SLIME_HANDS,
 PF_COMPOUND_EYES,//
 PF_PADDED_FEET,//
 PF_HOOVES,//
 PF_SAPROVORE,//
 PF_RUMINANT,//
 PF_HORNS,//
 PF_HORNS_CURLED,//
 PF_HORNS_POINTED,//
 PF_ANTENNAE,//
 PF_FLEET2,//
 PF_TAIL_STUB,//
 PF_TAIL_FIN,//
 PF_TAIL_LONG,//
 PF_TAIL_FLUFFY,//
 PF_TAIL_STING,//
 PF_TAIL_CLUB,//
 PF_PAINREC1,//
 PF_PAINREC2,//
 PF_PAINREC3,//
 PF_WINGS_BIRD,//
 PF_WINGS_INSECT,//
 PF_MOUTH_TENTACLES,//
 PF_MANDIBLES,//
 PF_CANINE_EARS,
 PF_WEB_WALKER,
 PF_WEB_WEAVER,
 PF_WHISKERS,
 PF_STR_UP,
 PF_STR_UP_2,
 PF_STR_UP_3,
 PF_STR_UP_4,
 PF_DEX_UP,
 PF_DEX_UP_2,
 PF_DEX_UP_3,
 PF_DEX_UP_4,
 PF_INT_UP,
 PF_INT_UP_2,
 PF_INT_UP_3,
 PF_INT_UP_4,
 PF_PER_UP,
 PF_PER_UP_2,
 PF_PER_UP_3,
 PF_PER_UP_4,

 PF_HEADBUMPS,//
 PF_ANTLERS,//
 PF_SLIT_NOSTRILS,//
 PF_FORKED_TONGUE,//
 PF_EYEBULGE,//
 PF_MOUTH_FLAPS,//
 PF_WINGS_STUB,//
 PF_WINGS_BAT,//
 PF_PALE,//
 PF_SPOTS,//
 PF_SMELLY2,//TODO: NPC reaction
 PF_DEFORMED,
 PF_DEFORMED2,
 PF_DEFORMED3,
 PF_HOLLOW_BONES,//
 PF_NAUSEA,//
 PF_VOMITOUS,//
 PF_HUNGER,//
 PF_THIRST,//
 PF_ROT1,//
 PF_ROT2,//
 PF_ROT3,//
 PF_ALBINO,//
 PF_SORES,//
 PF_TROGLO,//
 PF_TROGLO2,//
 PF_TROGLO3,//
 PF_WEBBED,//
 PF_BEAK,//
 PF_UNSTABLE,//
 PF_RADIOACTIVE1,//
 PF_RADIOACTIVE2,//
 PF_RADIOACTIVE3,//
 PF_SLIMY,//
 PF_HERBIVORE,//
 PF_CARNIVORE,//
 PF_PONDEROUS1,	// 10% movement penalty
 PF_PONDEROUS2, // 20%
 PF_PONDEROUS3, // 30%
 PF_SUNLIGHT_DEPENDENT,//
 PF_COLDBLOOD,//
 PF_COLDBLOOD2,//
 PF_COLDBLOOD3,//
 PF_GROWL,//
 PF_SNARL,//
 PF_SHOUT1,//
 PF_SHOUT2,//
 PF_SHOUT3,//
 PF_ARM_TENTACLES,
 PF_ARM_TENTACLES_4,
 PF_ARM_TENTACLES_8,
 PF_SHELL,
 PF_LEG_TENTACLES,

 PF_MAX2
};

struct trait {
 std::string name;
 int points;		// How many points it costs in character creation
 int visiblity;		// How visible it is--see below, at PF_MAX
 int ugliness;		// How ugly it is--see below, at PF_MAX
 std::string description;
};

const trait traits[] = {
{"NULL trait!", 0, 0, 0, "\
This is a bug.  Weird."},
{N_("Fleet-Footed"), 3, 0, 0, N_("\
You can run more quickly than most, resulting in a 15%% speed bonus on sure\n\
footing.")},
{N_("Parkour Expert"), 2, 0, 0, N_("\
You're skilled at clearing obstacles; terrain like railings or counters are\n\
as easy for you to move on as solid ground.")},
{N_("Quick"), 3, 0, 0, N_("\
You're just generally quick!  You get a 10%% bonus to action points.")},
{N_("Optimist"), 2, 0, 0, N_("\
Nothing gets you down!  Your morale will generally be higher than average.")},
{N_("Fast Healer"), 2, 0, 0, N_("\
You heal a little faster than most; sleeping will heal more lost HP.")},
{N_("Light Eater"), 3, 0, 0, N_("\
Your metabolism is a little slower, and you require less food than most.")},
{N_("Pain Resistant"), 2, 0, 0, N_("\
You have a high tolerance for pain.")},
{N_("Night Vision"), 1, 0, 0, N_("\
You possess natural night vision, and can see two squares instead of one in\n\
pitch blackness.")},
{N_("Poison Resistant"), 1, 0, 0, N_("\
Your system is rather tolerant of poisons and toxins, and most will affect\n\
you less.")},
{N_("Fast Reader"), 1, 0, 0, N_("\
You're a quick reader, and can get through books a lot faster than most.")},
{N_("Tough"), 3, 0, 0, N_("\
It takes a lot to bring you down!  You get a 20%% bonus to all hit points.")},
{N_("Thick-Skinned"), 2, 0, 0, N_("\
Your skin is tough.  Cutting damage is slightly reduced for you.")},
{N_("Packmule"), 3, 0, 0, N_("\
You can manage to find space for anything!  You can carry 40%% more volume.")},
{N_("Fast Learner"), 3, 0, 0, N_("\
Your skill comprehension is 50%% higher, allowing you to learn skills much\n\
faster than others.  Note that this only applies to real-world experience,\n\
not to skill gain from other sources like books.")},
{N_("Deft"), 2, 0, 0, N_("\
While you're not any better at melee combat, you are better at recovering\n\
from a miss, and will be able to attempt another strike faster.")},
{N_("Drunken Master"), 2, 0, 0, N_("\
The martial art technique of Zui Quan, or Drunken Fist, comes naturally to\n\
you.  While under the influence of alcohol, your melee skill will rise\n\
considerably, especially unarmed combat.")},
{N_("Gourmand"), 2, 0, 0, N_("\
You eat faster, and can eat and drink more, than anyone else!  You also enjoy\n\
food more; delicious food is better for your morale, and you don't mind some\n\
unsavory meals.")},
{N_("Animal Empathy"), 1, 0, 0, N_("\
Peaceful animals will not run away from you, and even aggressive animals are\n\
less likely to attack.  This only applies to natural animals such as woodland\n\
creatures.")},
{N_("Terrifying"), 2, 0, 0, N_("\
There's something about you that creatures find frightening, and they are\n\
more likely to try to flee.")},
{N_("Disease Resistant"), 1, 0, 0, N_("\
It's very unlikely that you will catch ambient diseases like a cold or the\n\
flu.")},
{N_("High Adrenaline"), 3, 0, 0, N_("\
If you are in a very dangerous situation, you may experience a temporary rush\n\
which increases your speed and strength significantly.")},
{N_("Self-aware"), 1, 0, 0, N_("\
You get to see your exact amount of HP remaining, instead of only having a\n\
vague idea of whether you're in good condition or not.")},
{N_("Inconspicuous"), 2, 0, 0, N_("\
While sleeping or staying still, it is less likely that monsters will wander\n\
close to you.")},
{N_("Masochist"), 2, 0, 0, N_("\
Although you still suffer the negative effects of pain, it also brings a\n\
unique pleasure to you.")},
{N_("Light Step"), 1, 0, 0, N_("\
You make less noise while walking.  You're also less likely to set off traps.")},
{N_("Android"), 4, 0, 0, N_("\
At some point in the past you had a bionic upgrade installed in your body.\n\
You start the game with a power system, and one random bionic enhancement.")},
{N_("Robust Genetics"), 2, 0, 0, N_("\
You have a very strong genetic base.  If you mutate, the odds that the\n\
mutation will be beneficial are greatly increased.")},
{N_("Cannibal"), 3, 0, 0, N_("\
For your whole life you've been forbidden from indulging in your peculiar\n\
tastes. Now the world's ended, and you'll be damned if anyone is going to\n\
tell you you can't eat people.")},
{N_("Martial Arts Training"), 3, 0, 0, N_("\
You have received some martial arts training at a local dojo.  You will start\n\
with your choice of karate, judo, aikido, tai chi, or taekwondo.")},

{"NULL", 0, 0, 0, " -------------------------------------------------- "},

{N_("Near-Sighted"), -2, 0, 0, N_("\
Without your glasses, your seeing radius is severely reduced!  However, while\n\
wearing glasses this trait has no effect, and you are guaranteed to start\n\
with a pair.")},
{N_("Heavy Sleeper"), -1, 0, 0, N_("\
You're quite the heavy sleeper.  Noises are unlikely to wake you up.")},
{N_("Asthmatic"), -4, 0, 0, N_("\
You will occasionally need to use an inhaler, or else suffer severe physical\n\
limitations.  However, you are guaranteed to start with an inhaler.")},
{N_("Bad Back"), -3, 0, 0, N_("\
You simply can not carry as much as people with a similar strength could.\n\
Your maximum weight carried is reduced by 35%%.")},
{N_("Illiterate"), -5, 0, 0, N_("\
You never learned to read!  Books and computers are off-limits to you.")},
{N_("Poor Hearing"), -2, 0, 0, N_("\
Your hearing is poor, and you may not hear quiet or far-off noises.")},
{N_("Insomniac"), -2, 0, 0, N_("\
You have a hard time falling asleep, even under the best circumstances!")},
{N_("Meat Intolerance"), -3, 0, 0, N_("\
You have problems with eating meat, it's possible for you to eat it but\n\
you will suffer morale penalties due to nausea.")},
{N_("Glass Jaw"), -3, 0, 0, N_("\
Your head can't take much abuse.  Its maximum HP is 15%% lower than usual.")},
{N_("Forgetful"), -3, 0, 0, N_("\
You have a hard time remembering things.  Your skills will erode slightly\n\
faster than usual.")},
{N_("Lightweight"), -1, 0, 0, N_("\
Alcohol and drugs go straight to your head.  You suffer the negative effects\n\
of these for longer.")},
{N_("Addictive Personality"), -3, 0, 0, N_("\
It's easier for you to become addicted to substances, and harder to rid\n\
yourself of these addictions.")},
{N_("Trigger Happy"), -2, 0, 0, N_("\
On rare occasion, you will go full-auto when you intended to fire a single\n\
shot.  This has no effect when firing handguns or other semi-automatic\n\
firearms.")},
{N_("Smelly"), -1, 0, 0, N_("\
Your scent is particularly strong.  It's not offensive to humans, but animals\n\
that track your scent will do so more easily.")},
{N_("Chemical Imbalance"), -2, 0, 0, N_("\
You suffer from a minor chemical imbalance, whether mental or physical. Minor\n\
changes to your internal chemistry will manifest themselves on occasion,\n\
such as hunger, sleepiness, narcotic effects, etc.")},
{N_("Schizophrenic"), -5, 0, 0, N_("\
You will periodically suffer from delusions, ranging from minor effects to\n\
full visual hallucinations.  Some of these effects may be controlled through\n\
the use of Thorazine.")},
{N_("Jittery"), -3, 0, 0, N_("\
During moments of great stress or under the effects of stimulants, you may\n\
find your hands shaking uncontrollably, severely reducing your dexterity.")},
{N_("Hoarder"), -4, 0, 0, N_("\
You don't feel right unless you're carrying as much as you can.  You suffer\n\
morale penalties for carrying less than maximum volume (weight is ignored).\n\
Xanax can help control this anxiety.")},
{N_("Savant"), -4, 0, 0, N_("\
You tend to specialize in one skill and be poor at all others.  You advance\n\
at half speed in all skills except your best one. Note that combining this\n\
with Fast Learner will come out to a slower rate of learning for all skills.")},
{N_("Mood Swings"), -1, 0, 0, N_("\
Your morale will shift up and down at random, often dramatically.")},
{N_("Weak Stomach"), -1, 0, 0, N_("\
You are more likely to throw up from food poisoning, alcohol, etc.")},
{N_("Wool Allergy"), -1, 0, 0, N_("\
You are badly allergic to wool, and can not wear any clothing made of the\n\
substance.")},
{N_("Truth Teller"), -2, 0, 0, N_("\
When you try to tell a lie, you blush, stammer, and get all shifty-eyed.\n\
Telling lies and otherwise bluffing will be much more difficult for you.")},
{N_("Ugly"), -1, 0, 2, N_("\
You're not much to look at.  NPCs who care about such things will react\n\
poorly to you.")},

{"Bug - PF_MAX", 0, 0, 0, "\
This shouldn't be here!  You have the trait PF_MAX toggled.  Weird."},

/* From here down are mutations.
 * In addition to a points value, mutations have a visibility value and an
 *  ugliness value.
 * Positive visibility means that the mutation is prominent.  This will visibly
 *  identify the player as a mutant, resulting in discrimination from mutant-
 *  haters and trust with mutants/mutant-lovers.
 * Poistive ugliness means that the mutation is grotesque.  This will result in
 *  a negative reaction from NPCs, even those who are themselves mutated, unless
 *  the NPC is a mutant-lover.
 */

{N_("Rough Skin"), 0, 2, 1, N_("\
Your skin is slightly rough.  This has no gameplay effect.")},
{N_("High Night Vision"), 3, 0, 0, N_("\
You can see incredibly well in the dark!")},
{N_("Full Night Vision"), 5, 0, 0, N_("\
You can see in pitch blackness as if you were wearing night-vision goggles.")},
{N_("Infrared Vision"), 5, 0, 0, N_("\
Your eyes have mutated to pick up radiation in the infrared spectrum.")},
{N_("Very Fast Healer"), 5, 0, 0, N_("\
Your flesh regenerates slowly, and you will regain HP even when not sleeping.")},
{N_("Regeneration"), 10, 0, 0, N_("\
Your flesh regenerates from wounds incredibly quickly.")},
{N_("Fangs"), 2, 2, 2, N_("\
Your teeth have grown into two-inch-long fangs, allowing you to make an extra\n\
attack when conditions favor it.")},
{N_("Nictitating Membrane"), 1, 1, 2, N_("\
You have a second set of clear eyelids which lower while underwater, allowing\n\
you to see as though you were wearing goggles.")},
{N_("Gills"), 3, 5, 3, N_("\
You've grown a set of gills in your neck, allowing you to breathe underwater.")},
{N_("Scales"), 6, 10, 3, N_("\
A set of flexible green scales have grown to cover your body, acting as a\n\
natural armor.")},
{N_("Thick Scales"), 6, 10, 4, N_("\
A set of heavy green scales have grown to cover your body, acting as a\n\
natural armor.  It is very difficult to penetrate, but also limits your\n\
flexibility, resulting in a -2 penalty to Dexterity.")},
{N_("Sleek Scales"), 6, 10, 4, N_("\
A set of very flexible and slick scales have grown to cover your body.  These\n\
act as a weak set of armor, improve your ability to swim, and make you\n\
difficult to grab.")},
{N_("Light Bones"), 2, 0, 0, N_("\
Your bones are very light.  This enables you to run and attack 10%% faster,\n\
but also reduces your carrying weight by 20%% and makes bashing attacks hurt\n\
a little more.")},
{N_("Feathers"), 2, 10, 3, N_("\
Iridescent feathers have grown to cover your entire body, providing a\n\
marginal protection against attacks and minor protection from cold. They\n\
also provide a natural waterproofing.")},
{N_("Lightly Furred"), 1, 6, 2, N_("\
Light fur has grown to coveryour entire body, providing slight protection\n\
from cold.")},
{N_("Furry"), 2, 10, 3, N_("\
Thick black fur has grown to cover your entire body, providing a marginal\n\
protection against attacks, and considerable protection from cold.")},
{N_("Chitinous Skin"), 2, 3, 2, N_("\
Your epidermis has turned into a thin, flexible layer of chitin.  It provides\n\
minor protection from cutting wounds.")},
{N_("Chitinous Armor"), 2, 6, 3, N_("\
You've grown a chitin exoskeleton, much like that of an insect.  It provides\n\
considerable physical protection, but reduces your dexterity by 1.")},
{N_("Chitinous Plate"), 2, 8, 5, N_("\
You've grown a chitin exoskeleton made of thick, stiff plates, like that of\n\
a beetle.  It provides excellent physical protection, but reduces your\n\
dexterity by 1 and encumbers all body parts but your eyes and mouth.")},
{N_("Spines"), 1, 0, 0, N_("\
Your skin is covered with fine spines.  Whenever an unarmed opponent strikes\n\
a part of your body that is not covered by clothing, they will receive\n\
moderate damage.")},
{N_("Quills"), 3, 0, 0, N_("\
Your body is covered with large quills.  Whenever an unarmed opponent strikes\n\
a part of your body that is not covered by clothing, they will receive\n\
significant damage.")},
{N_("Phelloderm"), 3, 3, 2, N_("\
Your skin is light green and has a slightly woody quality to it.  This\n\
provides a weak armor, and helps you retain moisture, resulting in less\n\
thirst.")},
{N_("Bark"), 5, 10, 3, N_("\
Your skin is coated in a light bark, like that of a tree.  This provides\n\
resistance to bashing and cutting damage and minor protection from fire.")},
{N_("Thorns"), 6, 8, 4, N_("\
Your skin is covered in small, woody thorns.  Whenever an unarmed opponent\n\
strikes a part of your body that is not covered by clothing, they will\n\
receive minor damage.  Your punches may also deal extra damage.")},
{N_("Leaves"), 6, 8, 3, N_("\
All the hair on your body has turned to long, grass-like leaves.  Apart from\n\
being physically striking, these provide you with a minor amount of nutrition\n\
while in sunlight.")},
{N_("Long Fingernails"), 1, 1, 0, N_("\
Your fingernails are long and sharp.  If you aren't wearing gloves, your\n\
unarmed attacks deal a minor amount of cutting damage.")},
{N_("Claws"), 2, 3, 2, N_("\
You have claws on the ends of your fingers.  If you aren't wearing gloves,\n\
your unarmed attacks deal a minor amount of cutting damage.")},
{N_("Large Talons"), 2, 4, 3, N_("\
Your index fingers have grown into huge talons.  After a bit of practice, you\n\
find that this does not affect your dexterity, but allows for a deadly\n\
unarmed attack.  They also prevent you from wearing gloves.")},
{N_("Radiogenic"), 3, 0, 0, N_("\
Your system has adapted to radiation.  While irradiated, you will actually\n\
heal slowly, converting the radiation into hit points.")},
{N_("Marloss Carrier"), 4, 0, 0, N_("\
Ever since you ate that Marloss berry, you can't get its scent out of your\n\
nose, and you have a strong desire to eat more.")},
{N_("Insect Pheromones"), 8, 0, 0, N_("\
Your body produces low-level pheromones, identifying you as a friend to many\n\
species of insects.  Insects will attack you much less.")},
{N_("Mammal Pheromones"), 8, 0, 0, N_("\
Your body produces low-level pheromones which puts mammals at ease.  They\n\
will be less likely to attack or flee from you.")},
{N_("Disease Immune"), 6, 0, 0, N_("\
Your body is simply immune to diseases.  You will never catch an ambient\n\
disease.")},
{N_("Poisonous"), 8, 0, 0, N_("\
Your body produces a potent venom.  Any special attacks from mutatations\n\
have a chance to poison your target.")},
{N_("Slime Hands"), 4, 5, 4, N_("\
The skin on your hands is a mucous membrane and produces a thick, acrid\n\
slime.  Attacks using your hand will cause minor acid damage.")},
{N_("Compound Eyes"), 2, 9, 5, N_("\
Your eyes are compound, like those of an insect.  This increases your\n\
perception by 2 so long as you aren't wearing eyewear.")},
{N_("Padded Feet"), 1, 1, 0, N_("\
The bottoms of your feet are strongly padded.  You receive no movement\n\
penalty for not wearing shoes, and even receive a 10%% bonus when running\n\
barefoot.")},
{N_("Hooves"), -4, 2, 2, N_("\
Your feet have fused into hooves.  This allows kicking attacks to do much\n\
more damage, provides natural armor, and removes the need to wear shoes;\n\
however, you can not wear shoes of any kind.")},
{N_("Saprovore"), 4, 0, 0, N_("\
Your digestive system is specialized to allow you to consume decaying\n\
material.  You can eat rotten food, albeit for less nutrition than\n\
usual.")},
{N_("Ruminant"), 5, 0, 0, N_("\
Your digestive system is capable of digesting cellulose and other rough\n\
plant material.  You can eat underbrush by standing over it and pressing\n\
E.")},
{N_("Horns"), 2, 3, 1, N_("\
You have a pair of small horns on your head.  They allow you to make a weak\n\
piercing headbutt attack.")},
{N_("Curled Horns"), 1, 8, 2, N_("\
You have a pair of large curled horns, like those of a ram.  They allow you\n\
to make a strong bashing headbutt attack, but prevent you from wearing any\n\
headwear.")},
{N_("Pointed Horns"), 2, 8, 2, N_("\
You have a pair of long, pointed horns, like those of an antelope.  They\n\
allow you to make a strong piercing headbutt attack, but prevent you from\n\
wearing any headwear the is not made of fabric.")},
{N_("Antennae"), 1, 9, 4, N_("\
You have a pair of antennae.  They allow you to detect the presence of\n\
monsters up to a few tiles away, even if you can't see or hear them, but\n\
prevent you from wearing headwear that is not made of fabric.")},
{N_("Road-Runner"), 4, 0, 0, N_("\
Your legs are extremely limber and fast-moving.  You run 30%% faster on\n\
flat surfaces.")},
{N_("Stubby Tail"), 0, 1, 2, N_("\
You have a short, stubby tail, like a rabbit's.  It serves no purpose.")},
{N_("Tail Fin"), 1, 4, 2, N_("\
You have a fin-like tail.  It allows you to swim more quickly.")},
{N_("Long Tail"), 2, 6, 2, N_("\
You have a long, graceful tail, like that of a big cat.  It improves your\n\
balance, making your ability to dodge higher.")},
{N_("Fluffy Tail"), 2, 7, 0, N_("\
You have a long, fluffy-furred tail.  It greatly improves your balance,\n\
making your ability to dodge much higher.")},
{N_("Spiked Tail"), 2, 6, 3, N_("\
You have a long tail that ends in a vicious stinger, like that of a\n\
scorpion.  It does not improve your balance at all, but allows for a\n\
powerful piercing attack.")},
{N_("Club Tail"), 2, 7, 2, N_("\
You have a long tail that ends in a heavy, bony club.  It does not improve\n\
your balance at all, but alows for a powerful bashing attack.")},
{N_("Pain Recovery"), 3, 0, 0, N_("\
You recover from pain slightly faster than normal.")},
{N_("Quick Pain Recovery"), 5, 0, 0, N_("\
You recover from pain faster than normal.")},
{N_("Very Quick Pain Reovery"), 8, 0, 0, N_("\
You recover from pain much faster than normal.")},
{N_("Bird Wings"), 2, 4, 2, N_("\
You have a pair of large, feathered wings.  Your body is too heavy to be able\n\
to fly, but you can use them to slow your descent during a fall, and will not\n\
take falling damage under any circumstances.")},
{N_("Insect Wings"), 3, 4, 4, N_("\
You have a pair of large, translucent wings.  You buzz them as you run,\n\
enabling you to run faster.")},
{N_("Mouth Tentacles"), 1, 8, 5, N_("\
A set of tentacles surrounds your mouth.  They allow you to eat twice as\n\
fast.")},
{N_("Mandibles"), 2, 8, 6, N_("\
A set of insect-like mandibles have grown around your mouth.  They allow you\n\
to eat faster and provide a slicing unarmed attack, but prevent you from\n\
wearing mouthwear.")},
{N_("Canine Ears"), 2, 4, 1, N_("\
Your ears have extended into long, pointed ones, like those of a canine.\n\
They enhance your hearing, allowing you to hear at greater distances.")},
{N_("Web Walker"), 3, 0, 0, N_("\
Your body excretes very fine amounts of a chemcial which prevents you from\n\
sticking to webs.  Walking through webs does not affect you at all.")},
{N_("Web Weaver"), 3, 0, 0, N_("\
Your body produces webs.  As you move, there is a chance that you will\n\
leave webs in your wake.")},
{N_("Whiskers"), 1, 3, 1, N_("\
You have a set of prominent rodent-like whiskers around your mouth.  These\n\
make you more aware of vibrations in the air, and improve your ability to\n\
dodge very slightly.")},
{N_("Strong"), 1, 0, 0, N_("\
Your muscles are a little stronger.  Strength + 1")},
{N_("Very Strong"), 2, 0, 0, N_("\
Your muscles are stronger.  Strength + 2")},
{N_("Extremely Strong"), 4, 1, 0, N_("\
Your muscles are much stronger.  Strength + 4")},
{N_("Insanely Strong"), 7, 2, 2, N_("\
Your muscles are noticably bulging.  Strength + 7")},
{N_("Dextrous"), 1, 0, 0, N_("\
You are a little nimbler.  Dexterity + 1")},
{N_("Very Dextrous"), 2, 0, 0, N_("\
You are nimbler.  Dexterity + 2")},
{N_("Extremely Dextrous"), 3, 0, 0, N_("\
You are nimble and quick.  Dexterity + 4")},
{N_("Insanely Dextrous"), 4, 0, 0, N_("\
You are much nimbler than before.  Dexterity + 7")},
{N_("Smart"), 1, 0, 0, N_("\
You are a little smarter.  Intelligence + 1")},
{N_("Very Smart"), 2, 0, 0, N_("\
You are smarter.  Intelligence + 2")},
{N_("Extremely Smart"), 3, 1, 1, N_("\
You are much smarter, and your skull bulges slightly.  Intelligence + 4")},
{N_("Insanely Smart"), 4, 3, 3, N_("\
Your skull bulges noticably with your impressive brain.  Intelligence + 7")},
{N_("Perceptive"), 1, 0, 0, N_("\
Your senses are a little keener.  Perception + 1")},
{N_("Very Perceptive"), 2, 0, 0, N_("\
Your senses are keener.  Perception + 2")},
{N_("Extremely Perceptive"), 3, 0, 0, N_("\
Your senses are much keener.  Perception + 4")},
{N_("Insanely Perceptive"), 4, 0, 0, N_("\
You can sense things you never imagined.  Perception + 7")},

{N_("Head Bumps"), 0, 3, 3, N_("\
You have a pair of bumps on your skull.")},
{N_("Antlers"), -2, 10, 3, N_("\
You have a huge rack of antlers, like those of a moose.  They prevent you\n\
from hearing headwear that is not made of fabric, but provide a weak\n\
headbutt attack.")},
{N_("Slit Nostrils"), -2, 7, 4, N_("\
You have a flattened nose and thin slits for nostrils, giving you a lizard-\n\
like appearance.  This makes breathing slightly difficult and increases\n\
mouth encumbrance by 1.")},
{N_("Forked Tongue"), 0, 1, 3, N_("\
Your tongue is forked, like that of a reptile.  This has no effect.")},
{N_("Bulging Eyes"), 0, 8, 4, N_("\
Your eyes bulge out several inches from your skull.  This does not affect\n\
your vision in any way.")},
{N_("Mouth Flaps"), -1, 7, 6, N_("\
Skin tabs and odd flaps of skin surround your mouth.  They don't affect your\n\
eating, but are unpleasant to look at.")},
{N_("Wing Stubs"), 0, 2, 2, N_("\
You have a pair of stubby little wings projecting from your shoulderblades.\n\
They can be wiggled at will, but are useless.")},
{N_("Bat Wings"), -1, 9, 4, N_("\
You have a pair of large, leathery wings.  You can move them a little, but\n\
they are useless, and in fact put you off balance, reducing your ability to\n\
dodge slightly.")},
{N_("Pale Skin"), 0, 3, 1, N_("\
Your skin is rather pale.")},
{N_("Spots"), 0, 6, 2, N_("\
Your skin is covered in a pattern of red spots.")},
{N_("Very Smelly"), -4, 4, 5, N_("\
You smell awful.  Monsters that track scent will find you very easily, and\n\
humans will react poorly.")},
{N_("Deformed"), -2, 4, 4, N_("\
You're minorly deformed.  Some people will react badly to your appearance.")},
{N_("Badly Deformed"), -4, 7, 7, N_("\
You're hideously deformed.  Some people will have a strong negative reaction\n\
to your appearance.")},
{N_("Grotesque"), -7, 10, 10, N_("\
Your visage is disgusting and liable to induce vomiting.  People will not\n\
want to interact with you unless they have a very good reason to.")},
{N_("Hollow Bones"), -6, 0, 0, N_("\
You have Avian Bone Syndrome--your bones are nearly hollow.  Your body is\n\
very light as a result, enabling you to run and attack 20%% faster, but\n\
also frail; you can carry 40%% less, and bashing attacks injure you more.")},
{N_("Nausea"), -3, 0, 0, N_("\
You feel nauseous almost constantly, and are more liable to throw up from\n\
food poisoning, alcohol, etc.")},
{N_("Vomitous"), -8, 0, 0, N_("\
You have a major digestive disorder, which causes you to vomit frequently.")},
{N_("Fast Metabolism"), -2, 0, 0, N_("\
You require more food than most people.")},
{N_("High Thirst"), -3, 0, 0, N_("\
Your body dries out easily; you need to drink a lot more water.")},
{N_("Weakening"), -6, 0, 0, N_("\
You feel as though you are slowly weakening, but it's so slight a feeling\n\
that it does not affect you at all.")},
{N_("Deterioration"), -8, 0, 0, N_("\
Your body is very slowly wasting away.")},
{N_("Disintegration"), -10, 0, 0, N_("\
Your body is slowly wasting away!")},
{N_("Albino"), -2, 0, 0, N_("\
Your skin lacks pigment, and is nearly transparent.  You suffer serious burns\n\
in direct sunlight.")},
{N_("Sores"), -2, 5, 6, N_("\
Your body is covered in painful sores.  The pain is worse when they are\n\
covered in clothing.")},
{N_("Light Sensitive"), -2, 0, 0, N_("\
Sunlight makes you uncomfortable.  If you are outdoors and the weather is\n\
Sunny, you suffer -1 to all stats.")},
{N_("Very Light Sensitive"), -3, 0, 0, N_("\
Sunlight makes you very uncomfortable.  If you are outdoors during the day,\n\
you suffer -1 to all stats; -2 if the weather is Sunny.")},
{N_("Troglobite"), -5, 0, 0, N_("\
Sunlight makes you extremely uncomfortable, resulting in large penalties to\n\
all stats.")},
{N_("Webbed Hands"), -1, 3, 2, N_("\
Your hands and feet are heavily webbed, reducing your dexterity by 1 and\n\
preventing you from wearing gloves.  However, you can swim much faster.")},
{N_("Beak"), -1, 8, 4, N_("\
You have a beak for a mouth.  You can occasionally use it to peck at your\n\
enemies, but it is impossible for you to wear mouthgear.")},
{N_("Genetically Unstable"), -4, 0, 0, N_("\
Your DNA has been damaged in a way that causes you to continually develop\n\
more mutations.")},
{N_("Minor Radioactivity"), -4, 0, 0, N_("\
Your body has become radioactive!  You continuously emit low levels of\n\
radiation, some of which will be absorbed by you, and some of which will\n\
contaminate the world around you.")},
{N_("Radioactivity"), -4, 0, 0, N_("\
Your body has become radioactive!  You continuously emit moderate levels of\n\
radiation, some of which will be absorbed by you, and some of which will\n\
contaminate the world around you.")},
{N_("Severe Radioactivity"), -4, 0, 0, N_("\
Your body has become radioactive!  You continuously emit heavy levels of\n\
radiation, some of which will be absorbed by you, and some of which will\n\
contaminate the world around you.")},
{N_("Slimy"), -1, 7, 6, N_("\
Your body is coated with a fine slime, which oozes off of you, leaving a\n\
trail.")},
{N_("Herbivore"), -3, 0, 0, N_("\
Your body's ability to digest meat is severely hampered.  Eating meat has a\n\
good chance of making you vomit it back up; even if you manage to keep it\n\
down, its nutritional value is greatly reduced.")},
{N_("Carnivore"), -3, 0, 0, N_("\
Your body's ability to digest fruits, vegetables and grains is severely\n\
hampered.  You cannot eat anything besides meat.")},
{N_("Ponderous"), -3, 0, 0, N_("\
Your muscles are generally slow to move.  You run 10%% slower.")},
{N_("Very Ponderous"), -5, 0, 0, N_("\
Your muscles are quite slow to move.  You run 20%% slower.")},
{N_("Extremely Ponderous"), -8, 0, 0, N_("\
Your muscles are very slow to move.  You run 30%% slower.")},
{N_("Sunlight dependent"), -5, 0, 0, N_("\
You feel very sluggish when not in direct sunlight.  You suffer a 5%% drop in\n\
speed when in shade, and a 10%% drop in speed when in the dark.")},
{N_("Heat dependent"), -2, 0, 0, N_("\
Your muscle response is dependent on ambient temperatures.  You lose 1%% of\n\
your speed for every 5 degrees below 65 F.")},
{N_("Very Heat dependent"), -3, 0, 0, N_("\
Your muscle response is highly dependent on ambient temperatures.  You lose\n\
1%% of your speed for every 3 degrees below 65 F.")},
{N_("Cold Blooded"), -5, 0, 0, N_("\
You are cold-blooded and rely on heat to keep moving.  Your lose 1%% of your\n\
speed for every 2 degrees below 65 F.")},
{N_("Growling Voice"), -1, 0, 0, N_("\
You have a growling, rough voice.  Persuading NPCs will be more difficult,\n\
but threatening them will be easier.")},
{N_("Snarling Voice"), -2, 0, 0, N_("\
You have a threatening snarl in your voice.  Persuading NPCs will be near\n\
impossible, but threatening them will be much easier.")},
{N_("Shouter"), -2, 0, 0, N_("\
You occasionally shout uncontrollably.")},
{N_("Screamer"), -3, 0, 0, N_("\
You sometimes scream uncontrollably.")},
{N_("Howler"), -5, 0, 0, N_("\
You frequently let out a piercing howl.")},
{N_("Tentacle Arms"), -5, 7, 4, N_("\
Your arms have transformed into tentacles.  Though they are flexible and\n\
increase your dexterity by 1, the lack of fingers results in a permanent\n\
hand encumbrance of 3, and prevents the wearing of gloves.")},
{N_("4 Tentacles"), -3, 8, 5, N_("\
Your arms have transformed into four tentacles, resulting in a bonus of 1 to\n\
dexterity, permanent hand encumbrance of 3, and preventing you from wearing\n\
gloves.  You can make up to 3 extra attacks with them.")},
{N_("8 Tentacles"), -2, 9, 6, N_("\
Your arms have transformed into eight tentacles, resulting in a bonus of 1 to\n\
dexterity, permanent hand encumbrance of 3, and preventing you from wearing\n\
gloves.  You can make up to 7 extra attacks with them.")},
{N_("Shell"), -6, 8, 3, N_("\
You have grown a thick shell over your torso, providing excellent armor.  You\n\
find you can use the empty space as 16 storage space, but cannot wear\n\
anything on your torso.")},
{N_("Leg Tentacles"), -3, 8, 4, N_("\
Your legs have transformed into six tentacles.  This decreases your speed on\n\
land by 20%, but makes your movement silent.  However, they also increase\n\
your swimming speed.")}
};

enum hp_part {
 hp_head = 0,
 hp_torso,
 hp_arm_l,
 hp_arm_r,
 hp_leg_l,
 hp_leg_r,
 num_hp_parts
};
#endif
