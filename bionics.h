#ifndef _BIONICS_H_
#define _BIONICS_H_
#include <string>
#include "i18n.h"

/* Thought: Perhaps a HUD bionic that changes the display of the game?
 * Showing more information or something. */

enum bionic_id {
bio_null,
// Power sources
bio_batteries, bio_metabolics, bio_solar, bio_furnace, bio_ethanol,
// Automatic / Always-On
bio_memory, bio_ears,
bio_eye_enhancer, bio_membrane, bio_targeting,
bio_gills, bio_purifier,
bio_climate, bio_storage, bio_recycler, bio_digestion,	// TODO: Ynnn
bio_tools, bio_shock, bio_heat_absorb,
bio_carbon, bio_armor_head, bio_armor_torso, bio_armor_arms, bio_armor_legs,
// Player Activated
bio_flashlight, bio_night_vision, bio_infrared,
bio_face_mask,	// TODO
bio_ads, bio_ods, bio_scent_mask,bio_scent_vision, bio_cloak, bio_painkiller,
 bio_nanobots, bio_heatsink, bio_resonator, bio_time_freeze, bio_teleport,
 bio_blood_anal, bio_blood_filter, bio_alarm,
bio_evap, bio_lighter, bio_claws, bio_blaster, bio_laser, bio_emp,
 bio_hydraulics, bio_water_extractor, bio_magnet, bio_fingerhack, bio_lockpick,
bio_ground_sonar,
max_bio_start,
// EVERYTHING below this point is not available to brand-new players
// TODO: all these suckers
bio_banish, bio_gate_out, bio_gate_in, bio_nightfall, bio_drilldown,
bio_heatwave, bio_lightning, bio_tremor, bio_flashflood,
max_bio_good,
// Everything below THIS point is bad bionics, meant to be punishments
bio_dis_shock, bio_dis_acid, bio_drain, bio_noise, bio_power_weakness,
 bio_stiff,
max_bio
};

struct bionic_data {
 std::string name;
 bool power_source;
 bool activated;	// If true, then the below function only happens when
			// activated; otherwise, it happens every turn
 int power_cost;
 int charge_time;	// How long, when activated, between drawing power_cost
			// If 0, it draws power once
 std::string description;
};

struct bionic {
 bionic_id id;
 char invlet;
 bool powered;
 int charge;
 bionic() {
  id = bio_batteries;
  invlet = 'a';
  powered = false;
  charge = 0;
 }
 bionic(bionic_id pid, char pinvlet) {
  id = pid;
  invlet = pinvlet;
  powered = false;
  charge = 0;
 };
};

const bionic_data bionics[] = {
{"NULL bionics", false, false, 0, 0, "\
If you're seeing this, it's a bug."},
// NAME          ,PW_SRC, ACT ,COST, TIME,
{N_("Battery System"), true, false, 0, 0, N_("\
You have a battery draining attachment, and thus can make use of the energy\n\
contained in normal, everyday batteries.  Use 'E' to consume batteries.")},
{N_("Metabolic Interchange"), true, false, 0, 0, N_("\
Your digestive system and power supply are interconnected.  Any drain on\n\
energy instead increases your hunger.")},
{N_("Solar Panels"), true, false, 0, 0, N_("\
You have a few solar panels installed.  While in direct sunlight, your power\n\
level will slowly recharge.")},
{N_("Internal Furnace"), true, false, 0, 0, N_("\
You can burn nearly any organic material as fuel (use 'E'), recharging your\n\
power level.  Some materials will burn better than others.")},
{N_("Ethanol Burner"), true, false, 0, 0, N_("\
You burn alcohol as fuel in an extremely efficient reaction.  However, you\n\
will still suffer the inebriating effects of the substance.")},

{N_("Enhanced Memory Banks"), false, false, 1, 0, N_("\
Your memory has been enhanced with small quantum storage drives.  Any time\n\
you start to forget a skill, you have a chance at retaining all knowledge, at\n\
the cost of a small amount of power.")},
{N_("Enhanced Hearing"), false, false, 0, 0, N_("\
Your hearing has been drastically improved, allowing you to hear ten times\n\
better than the average person.  Additionally, high-intensity sounds will be\n\
automatically dampened before they can damage your hearing.")},
{N_("Diamond Cornea"), false, false, 0, 0, N_("\
Your vision is greatly enhanced, giving you a +2 bonus to perception.")},
{N_("Nictating Membrane"), false, false, 0, 0, N_("\
Your eyes have a thin membrane that closes over your eyes while underwater,\n\
negating any vision penalties.")},
{N_("Targeting System"), false, false, 0, 0, N_("\
Your eyes are equipped with range finders, and their movement is synced with\n\
that of your arms, to a degree.  Shots you fire will be much more accurate,\n\
particularly at long range.")},
{N_("Membrane Oxygenator"), false, false, 1, 0, N_("\
An oxygen interchange system automatically switches on while underwater,\n\
slowly draining your energy reserves but providing oxygen.")},
{N_("Air Filtration System"), false, false, 1, 0, N_("\
Implanted in your trachea is an advanced filtration system.  If toxins find\n\
their way into your windpipe, the filter will attempt to remove them.")},
{N_("Internal Climate Control"), false, true, 1, 30, N_("\
Throughout your body lies a network of thermal piping which eases the effects\n\
of high and low ambient temperatures.")},
{N_("Internal Storage"), false, false, 0, 0, N_("\
Space inside your chest cavity has been converted into a storage area.  You\n\
may carry an extra 8 units of volume.")},
{N_("Recycler Unit"), false, false, 0, 0, N_("\
Your digestive system has been outfitted with a series of filters and\n\
processors, allowing you to reclaim waste liquid and, to a lesser degree,\n\
nutrients.  The net effect is a greatly reduced need to eat and drink.")},
{N_("Expanded Digestive System"), false, false, 0, 0, N_("\
You have been outfitted with three synthetic stomachs and industrial-grade\n\
intestines.  Not only can you extract much more nutrition from food, but you\n\
are highly resistant to foodborne illness, and can sometimes eat rotten food.")},
{N_("Integrated Toolset"), false, false, 0, 0, N_("\
Implanted in your hands and fingers is a complete tool set - screwdriver,\n\
hammer, wrench, and heating elements.  You can use this in place of many\n\
tools when crafting.")},
{N_("Electroshock Unit"), false, false, 1, 0, N_("\
While fighting unarmed, or with a weapon that conducts electricity, there is\n\
a chance that a successful hit will shock your opponent, inflicting extra\n\
damage and disabling them temporarily at the cost of some energy.")},
{N_("Heat Drain"), false, false, 1, 0, N_("\
While fighting unarmed against a warm-blooded opponent, there is a chance\n\
that a successful hit will drain body heat, inflicting a small amount of\n\
extra damage, and increasing your power reserves slightly.")},
{N_("Subdermal Carbon Filament"), false, false, 0, 0, N_("\
Lying just beneath your skin is a thin armor made of carbon nanotubes. This\n\
reduces bashing damage by 2 and cutting damage by 4, but also reduces your\n\
dexterity by 2.")},
{N_("Alloy Plating - Head"), false, false, 0, 0, N_("\
The flesh on your head has been replaced by a strong armor, protecting both\n\
your head and jaw regions, but increasing encumberance by 2 and decreasing\n\
perception by 1.")},
{N_("Alloy Plating - Torso"), false, false, 0, 0, N_("\
The flesh on your torso has been replaced by a strong armor, protecting you\n\
greatly, but increasing your encumberance by 2.")},
{N_("Alloy Plating - Arms"), false, false, 0, 0, N_("\
The flesh on your arms has been replaced by a strong armor, protecting you\n\
greatly, but decreasing your dexterity by 1.")},
{N_("Alloy Plating - Legs"), false, false, 0, 0, N_("\
The flesh on your legs has been replaced by a strong armor, protecting you\n\
greatly, but decreasing your speed by 15.")},

{N_("Cranial Flashlight"), false, true, 1, 30, N_("\
Mounted between your eyes is a small but powerful LED flashlight.")},
{N_("Implanted Night Vision"), false, true, 1, 20, N_("\
Your eyes have been modified to amplify existing light, allowing you to see\n\
in the dark.")},
{N_("Infrared Vision"), false, true, 1, 4, N_("\
Your range of vision extends into the infrared, allowing you to see warm-\n\
blooded creatures in the dark, and even through walls.")},
{N_("Facial Distortion"), false, true, 1, 10, N_("\
Your face is actually made of a compound which may be molded by electrical\n\
impulses, making you impossible to recognize.  While not powered, however,\n\
the compound reverts to its default shape.")},
{N_("Active Defense System"), false, true, 1, 7, N_("\
A thin forcefield surrounds your body, continually draining power.  Anything\n\
attempting to penetrate this field has a chance of being deflected at the\n\
cost of more energy.  Melee attacks will be stopped more often than bullets.")},
{N_("Offensive Defense System"), false, true, 1, 6, N_("\
A thin forcefield surrounds your body, continually draining power.  This\n\
field does not deflect penetration, but rather delivers a very strong shock,\n\
damaging unarmed attackers and those with a conductive weapon.")},
{N_("Olfactory Mask"), false, true, 1, 8, N_("\
While this system is powered, your body will produce very little odor, making\n\
it nearly impossible for creatures to track you by scent.")},
{N_("Scent Vision"), false, true, 1, 30, N_("\
While this system is powered, you're able to visually sense your own scent,\n\
making it possible for you to recognize your surroundings even if you can't\n\
see it.")},
{N_("Cloaking System"), false, true, 2, 1, N_("\
This high-power system uses a set of cameras and LEDs to make you blend into\n\
your background, rendering you fully invisible to normal vision.  However,\n\
you may be detected by infrared, sonar, etc.")},
{N_("Sensory Dulling"), false, true, 2, 0, N_("\
Your nervous system is wired to allow you to inhibit the signals of pain,\n\
allowing you to dull your senses at will.  However, the use of this system\n\
may cause delayed reaction time and drowsiness.")},
{N_("Repair Nanobots"), false, true, 5, 0, N_("\
Inside your body is a fleet of tiny dormant robots.  Once charged from your\n\
energy banks, they will flit about your body, repairing any damage.")},
{N_("Thermal Dissapation"), false, true, 1, 6, N_("\
Powerful heatsinks supermaterials are woven into your flesh.  While powered,\n\
this system will prevent heat damage up to 2000 degrees fahrenheit.  Note\n\
that this does not affect your internal temperature.")},
{N_("Sonic Resonator"), false, true, 4, 0, N_("\
Your entire body may resonate at very high power, creating a short-range\n\
shockwave.  While it will not to much damage to flexible creatures, stiff\n\
items such as walls, doors, and even robots will be severely damaged.")},
{N_("Time Dilation"), false, true, 3, 0, N_("\
At an immense cost of power, you may increase your body speed and reactions\n\
dramatically, essentially freezing time.  You are still delicate, however,\n\
and violent or rapid movements may damage you due to friction.")},
{N_("Teleportation Unit"), false, true, 10, 0, N_("\
This highly experimental unit folds space over short distances, instantly\n\
transporting your body up to 25 feet at the cost of much power.  Note that\n\
prolonged or frequent use may have dangerous side effects.")},
{N_("Blood Analysis"), false, true, 1, 0, N_("\
Small sensors have been implanted in your heart, allowing you to analyse your\n\
blood.  This will detect many illnesses, drugs, and other conditions.")},
{N_("Blood Filter"), false, true, 3, 0, N_("\
A filtration system in your heart allows you to actively filter out chemical\n\
impurities, primarily drugs.  It will have limited impact on viruses.  Note\n\
that it is not a targeted filter; ALL drugs in your system will be affected.")},
{N_("Alarm System"), false, true, 1, 400, N_("\
A motion-detecting alarm system will notice almost all movement within a\n\
fifteen-foot radius, and will silently alert you.  This is very useful during\n\
sleep, or if you suspect a cloaked pursuer.")},
{N_("Aero-Evaporator"), false, true, 8, 0, N_("\
This unit draws moisture from the surrounding air, which then is poured from\n\
a fingertip in the form of water.  It may fail in very dry environments.")},
{N_("Mini-Flamethrower"), false, true, 3, 0, N_("\
The index fingers of both hands have powerful fire starters which extend from\n\
the tip.")},
{N_("Adamantium Claws"), false, true, 3, 0, N_("\
Your fingers can withdraw into your hands, allowing a set of vicious claws to\n\
extend.  These do considerable cutting damage, but prevent you from holding\n\
anything else.")},
{N_("Fusion Blaster Arm"), false, true, 2, 0, N_("\
Your left arm has been replaced by a heavy-duty fusion blaster!  You may use\n\
your energy banks to fire a damaging heat ray; however, you are unable to use\n\
or carry two-handed items, and may only fire handguns.")},
{N_("Finger-Mounted Laser"), false, true, 2, 0, N_("\
One of your fingers has a small high-powered laser embedded in it.  This long\n\
range weapon is not incredibly damaging, but is very accurate, and has the\n\
potential to start fires.")},
{N_("Directional EMP"), false, true, 4, 0, N_("\
Mounted in the palms of your hand are small parabolic EMP field generators.\n\
You may use power to fire a short-ranged blast which will disable electronics\n\
and robots.")},
{N_("Hydraulic Muscles"), false, true, 1, 3, N_("\
While activated, the muscles in your arms will be greatly enchanced,\n\
increasing your strength by 20.")},
{N_("Water Extraction Unit"), false, true, 2, 0, N_("\
Nanotubs embedded in the palm of your hand will pump any available fluid out\n\
of a dead body, cleanse it of impurities and convert it into drinkable water.\n\
You must, however, have a container to store the water in.")},
{N_("Electromagnetic Unit"), false, true, 2, 0, N_("\
Embedded in your hand is a powerful electromagnet, allowing you to pull items\n\
made of iron over short distances.")},
{N_("Fingerhack"), false, true, 1, 0, N_("\
One of your fingers has an electrohack embedded in it; an all-purpose hacking\n\
unit used to override control panels and the like (but not computers).  Skill\n\
in computers is important, and a failed use may damage your circuits.")},
{N_("Fingerpick"), false, true, 1, 0, N_("\
One of your fingers has an electronic lockpick embedded in it.  This auto-\n\
matic system will quickly unlock all but the most advanced key locks without\n\
any skill required on the part of the user.")},
{N_("Terranian Sonar"), false, true, 1, 5, N_("\
Your feet are equipped with precision sonar equipment, allowing you to detect\n\
the movements of creatures below the ground.")},

{N_("max_bio_start - BUG"), false, false, 0, 0, N_("\
This is a placeholder bionic meant to demarkate those which a new character\n\
can start with.  If you are reading this, you have found a bug!")},

{N_("Banishment"), false, true, 40, 0, N_("\
You can briefly open a one-way gate to the nether realm, banishing a single\n\
target there permanently.  This is not without its dangers, however, as the\n\
inhabitants of the nether world may take notice.")},
{N_("Gate Out"), false, true, 55, 0, N_("\
You can temporarily open a two-way gate to the nether realm, accessible only\n\
by you.  This will remove you from immediate danger, but may attract the\n\
attention of the nether world's inhabitants...")},
{N_("Gate In"), false, true, 35, 0, N_("\
You can temporarily open a one-way gate from the nether realm.  This will\n\
attract the attention of its horrifying inhabitants, who may begin to pour\n\
into reality.")},
{N_("Artificial Night"), false, true, 5, 1, N_("\
Photon absorbtion panels will attract and obliterate photons within a 100'\n\
radius, casting an area around you into pitch darkness.")},
{N_("Borehole Drill"), false, true, 30, 0, N_("\
Your legs can transform into a powerful drill which will bury you 50 feet\n\
into the earth.  Be careful to only drill down when you know you will be able\n\
to get out, or you'll simply dig your own tomb.")},
{N_("Heatwave"), false, true, 45, 0, N_("\
At the cost of immense power, you can cause dramatic spikes in the ambient\n\
temperature around you.  These spikes are very short-lived, but last long\n\
enough to ignite wood, paper, gunpowder, and other substances.")},
{N_("Chain Lightning"), false, true, 48, 0, N_("\
Powerful capacitors unleash an electrical storm at your command, sending a\n\
chain of highly-damaging lightning through the air.  It has the power to\n\
injure several opponents before grounding itself.")},
{N_("Tremor Pads"), false, true, 40, 0, N_("\
Using tremor pads in your feet, you can cause a miniature earthquake.  The\n\
shockwave will damage enemies (particularly those digging underground), tear\n\
down walls, and churn the earth.")},
{N_("Flashflood"), false, true, 35, 0, N_("\
By drawing the moisture from the air, and synthesizing water from in-air\n\
elements, you can create a massive puddle around you.  The effects are more\n\
powerful when used near a body of water.")},

{N_("max_bio_good - BUG"), false, false, 0, 0, N_("\
This is a placeholder bionic.  If you are reading this, you have found a bug!")},

{N_("Electrical Discharge"), false, false, 0, 0, N_("\
A malfunctioning bionic which occasionally discharges electricity through\n\
your body, causing pain and brief paralysis but no damage.")},
{N_("Acidic Discharge"), false, false, 0, 0, N_("\
A malfunctioning bionic which occasionally discharges acid into your muscles,\n\
causing sharp pain and minor damage.")},
{N_("Electrical Drain"), false, false, 0, 0, N_("\
A malfunctioning bionic.  It doesn't perform any useful function, but will\n\
occasionally draw power from your batteries.")},
{N_("Noisemaker"), false, false, 0, 0, N_("\
A malfunctioning bionic.  It will occasionally emit a loud burst of noise.")},
{N_("Power Overload"), false, false, 0, 0, N_("\
Damaged power circuits cause short-circuiting inside your muscles when your\n\
batteries are above 75%%%% capacity, causing greatly reduced strength.  This\n\
has no effect if you have no internal batteries.")},
{N_("Wire-induced Stiffness"), false, false, 0, 0, N_("\
Improperly installed wires cause a physical stiffness in most of your body,\n\
causing increased encumberance.")}

};

#endif
