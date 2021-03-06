#include "game.h"
#include "keypress.h"
#include "options.h"
#include "i18n.h"

#ifndef LINE_XOXO
	#define LINE_XOXO 4194424
	#define LINE_OXOX 4194417
	#define LINE_XXOO 4194413
	#define LINE_OXXO 4194412
	#define LINE_OOXX 4194411
	#define LINE_XOOX 4194410
	#define LINE_XXXO 4194420
	#define LINE_XXOX 4194422
	#define LINE_XOXX 4194421
	#define LINE_OXXX 4194423
	#define LINE_XXXX 4194414
#endif

void game::help()
{
 WINDOW* w_help_border = newwin(25, 80, (TERMY > 25) ? (TERMY-25)/2 : 0, (TERMX > 80) ? (TERMX-80)/2 : 0);
 WINDOW* w_help = newwin(23, 78, 1 + (int)((TERMY > 25) ? (TERMY-25)/2 : 0), 1 + (int)((TERMX > 80) ? (TERMX-80)/2 : 0));

 char ch;

 do {
  wborder(w_help_border, LINE_XOXO, LINE_XOXO, LINE_OXOX, LINE_OXOX,
                        LINE_OXXO, LINE_OOXX, LINE_XXOO, LINE_XOOX);
  mvwprintz(w_help_border, 0, 38, c_ltred, _(" HELP "));
  wrefresh(w_help_border);
  werase(w_help);
  mvwprintz(w_help, 1, 0, c_white, _("\
Please press one of the following for help on that topic:\n\
Press q or ESC to return to the game.\n\
\n\
a: Introduction                      i: Bionics\n\
b: Movement                          j: Crafting\n\
c: Viewing                           k: Traps\n\
d: Hunger, Thirst, and Sleep         l: Items overview\n\
e: Pain and Stimulants               m: Combat\n\
f: Addiction                         n: Unarmed Styles\n\
g: Morale and XP                     o: Survival tips\n\
h: Radioactivity and Mutation\n\
\n\
1: List of all commands (you can change key commands here)\n\
2: List of all options  (you can change options here)\n\
3: List of item types and data\n\
4: Description of map symbols\n\
5: Description of gun types\n\
6: Frequently Asked Questions (Some spoilers!)\n\
\n\
q: Return to game"));

  wrefresh(w_help);
  refresh();
  ch = getch();
  switch (ch) {
  case 'a':
  case 'A':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Cataclysm is a roguelike with a monster apocalypse setting. You have survived\n\
the original onslaught, and are ready to set out in search of safety.\n\
\n\
Cataclysm differs from most roguelikes in several ways. Rather than exploring\n\
an underground dungeon, with a limited area on each level, you are exploring\n\
a truly infinite world, stretching in all four cardinal directions.\n\
As in most roguelikes, you will have to find food; you also need to keep\n\
yourself hydrated, and sleep periodically.\n\
\n\
While Cataclysm has more challenges than many roguelikes, the near-future\n\
setting makes some tasks easier. Firearms, medications, and a wide variety of\n\
tools are all available to help you survive."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'b':
  case 'B':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Movement is performed using the numpad, or vikeys. Each step will take 100\n\
                    movement points (or more, depending on the terrain); you\n\
y  k  u   7  8  9   will then replenish a variable amount of movement points,\n\
 \\ | /     \\ | /    depending on many factors (press '@' to see the exact\n\
  \\|/       \\|/     amount). To attempt to hit a monster with your weapon,\n\
h--.--l   4--5--6   simply move into it. You may find doors, ('+'); these may\n\
  /|\\       /|\\     be opened with 'o' or closed with 'c'. Some doors are\n\
 / | \\     / | \\    locked. Locked doors, windows, and some other obstacles\n\
b  j  n   1  2  3   can be destroyed by smashing them ('s', then choose a\n\
                    direction). Smashing down obstacles is much easier with a\n\
good weapon or a strong character.\n\
\n\
There may be times when you want to move more quickly by holding down a\n\
movement key. However, fast movement in this fashion may lead to the player\n\
getting into a dangerous situation or even killed before they have a chance\n\
to react. Pressing '!' will toggle \"Run Mode.\" While this is on, any\n\
movement will be ignored if new monsters enter the player's view."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'c':
  case 'C':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
The player can often see more than can be displayed on the screen at a time.\n\
Pressing ';' or 'x' enters look around mode, which allows you to scoll around\n\
using the movement keys and view irems on the map. Pressing 'V' provides a\n\
list of nearby visible items, though items shut away in crates, cubpoards,\n\
refrigerators and the like will not be displayed. Pressing Shift+vikeys\n\
will scroll the view persistently, allowing you to keep an eye on things\n\
as you move around."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'd':
  case 'D':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
As time passes, you will begin to feel hunger and thirst. A status warning\n\
at the bottom of the screen will appear. As hunger and thirst reach critical\n\
levels, you will begin to suffer movement penalties. Thirst is more dangerous\n\
than hunger. Finding food in a city is usually easy; outside of a city, you\n\
may have to hunt an animal, then stand over its corpse and 'B'utcher it into\n\
small chunks of meat. Likewise, outside of a city you may have to drink water\n\
from a river or other natural source; stand in shallow water and press 'g' or\n\
',' to pick it up. You'll need a watertight container. Be forewarned that\n\
some sources of water aren't trustworthy and may produce diseased water. To\n\
be sure it's healthy, run all water you collect through a water filter before\n\
drinking.\n\
\n\
Every 14 to 20 hours, you'll find yourself growing sleepy. If you do not\n\
sleep by pressing '$', you'll start suffering stat and movement penalties.\n\
You may not always fall asleep right away. Sleeping indoors, especially on a\n\
bed, will help; or you can always use sleeping pills. While sleeping, you'll\n\
slowly replenish lost hit points. You'll also be vulnerable to attack, so\n\
try to find a safe place, or set traps for unwary intruders."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'e':
  case 'E':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
When you take damage from almost any source, you'll start to feel pain. Pain\n\
slows you down and reduces your stats, and finding a way to manage pain is an\n\
early imperative. The most common is drugs; aspirin, codeine, tramadol,\n\
oxycodone, and more are all great options. Be aware that while under the\n\
influence of a lot of painkillers, the physiological effects may slow you or\n\
reduce your stats.\n\
\n\
Note that most painkillers take a little while to kick in. If you take some\n\
oxycodone, and don't notice the effects right away, don't start taking more;\n\
you may overdose and die!\n\
\n\
Pain will also disappear with time, so if drugs aren't available and you're\n\
in a lot of pain, it may be wise to find a safe spot and simply rest for an\n\
extended period of time.\n\
\n\
Another common class of drugs is stimulants. Stimulants provide you with a\n\
temporary rush of energy, increasing your movement speed and many stats, most\n\
notably intelligence, making them useful study aids. There are two drawbacks\n\
to stimulants; they make it more difficult to sleep, and, more importantly,\n\
most are highly addictive. Stimulants range from the caffeine rush of cola\n\
to the more intense high of Adderall and methamphetamine."));
  wrefresh(w_help);
  refresh();
  getch();
  break;

  case 'f':
  case 'F':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Many drugs have a potential for addiction. Each time you consume such a drug\n\
there is a chance that you will grow dependent on it. Consuming more of that\n\
drug will increase your dependance. Effects vary greatly between drugs, but\n\
all addictions have only one cure; going cold turkey. The process may last\n\
days, and will leave you very weak, so try to do it in a safe area.\n\
\n\
If you are suffering from drug withdrawal, taking more of the drug will cause\n\
the effects to cease immediately, but may deepen your dependance."));
  wrefresh(w_help);
  refresh();
  getch();
  break;

  case 'g':
  case 'G':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Your character has a morale level, which affects you in many ways. The\n\
depressing post-apocalypse world is tough to deal with, and your mood will\n\
naturally decrease very slowly.\n\
\n\
There are lots of options for increasing morale; reading an entertaining\n\
book, eating delicious food, and taking recreational drugs are but a few\n\
options. Most morale-boosting activities can only take you to a certain\n\
level before they grow boring.\n\
\n\
There are also lots of ways for your morale to decrease, beyond its natural\n\
decay. Eating disgusting food, reading a boring technical book, or going\n\
through drug withdrawal are some prominent examples.\n\
\n\
Low morale will make you sluggish and unmotivated. It will also reduce your\n\
stats, particularly intelligence. If your morale drops very low, you may\n\
even commit suicide. Very high morale fills you with gusto and energy, and\n\
you will find yourself moving faster. At extremely high levels, you will\n\
receive stat bonuses.\n\
\n\
Press any key for more..."));
   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Morale is also responsible for filling your XP pool. This XP pool is used\n\
for improving your skills; as you use your skills, points are taken from the\n\
XP pool and placed into the skill used. If your XP pool is empty, your\n\
skills cannot be improved except through the use of books.\n\
\n\
Your XP pool will not fill unless your morale is at least 0. A morale level\n\
between 0 and 100 gives the percentage chance for your XP to increase by 1\n\
each turn. Above 100, you get 1 XP point each turn for every 100 morale."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'h':
  case 'H':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Though it is relatively rare, certain areas of the world may be contamiated\n\
with radiation. It will gradually accumulate in your body, weakening you\n\
more and more. While in radiation-free areas, your radiation level will\n\
slowly decrease. Taking iodine tablets will help speed the process.\n\
\n\
If you become very irradiated, you may develop mutations. Most of the time,\n\
these mutations will be negative; however, many are beneficial, and others\n\
have both positive and negative effects. Your mutations may change your play\n\
style considerably. It is possible to find substances that will remove\n\
mutations, though these are extremely rare."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'i':
  case 'I':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Bionics are biomechanical upgrades to your body. While many are simply\n\
'built-in' versions of items you would otherwise have to carry, some bionics\n\
have unique effects that are otherwise unobtainable.\n\
\n\
Most bionics require a source of power, and you will need an internal battery\n\
to store energy for them. Your current amount of energy is displayed below\n\
your health. Replenishing energy can be done in a variety of ways, but all\n\
require the installation of a special bionic just for fuel consumption.\n\
\n\
Bionics come in ready-to-install canisters. Installation of a bionic is best\n\
left to a trained professional. However, you may attempt to perform a self-\n\
installation. Performing such a task requires high levels of intelligence,\n\
first aid, mechanics, and/or electronics, and failure may cripple you!\n\
Many bionics canisters are difficult to find, but may be purchased from\n\
certain wandering vagabonds for a very high price."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'j':
  case 'J':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Many important items can be very hard to find, or will cost a great deal of\n\
money to trade for. Fortunately, it is possible to craft a wide variety of\n\
goods with the proper tools, materials, and training.\n\
\n\
Some recipes require a set of tools. These are not used up when crafting, so\n\
you can keep your tool set. All recipes require one or more ingredients.\n\
These ARE used up in crafting.\n\
\n\
To craft items, press '&'. There are five categories; Weapons, Food,\n\
Electronics, Armor, and Miscellaneous. While a few items require no skill to\n\
create, the majority require you to have some knowledge:\n\
\n\
->Mechanic skill is used for weapons, traps, and a few tools.\n\
->Cooking skill, at low levels, is used for making tasty recipes; at higher\n\
levels, you have an understanding of chemistry and can make chemical weapons\n\
and beneficial elixirs.\n\
->Electronics skill lets you make a wide variety of tools with intricate uses.\n\
->Tailoring skill is used to create basic clothing, and later tough armor.\n\
\n\
In addition to the primary crafting skills, other skills may be necessary to\n\
create certain items. Traps skill, Firearms skill, and First Aid skill are\n\
all required for certain items."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'k':
  case 'K':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
While sleeping in dangerous territory, it may be wise to set traps to ward\n\
off unwanted intrusions. There are a few traps to be found in the world,\n\
most notably bubblewrap (which will make a loud noise if stepped on, helping\n\
to wake you up) and bear traps (which make noise AND damage and trap anything\n\
that steps on them). Others need to be crafted; this requires the Traps skill\n\
and possibly Mechanics.\n\
\n\
To set a trap, simply use the item ('a') and choose a direction; the trap\n\
will be placed on an adjacent tile. Some traps may require additional tools,\n\
like a shovel, to be set. Once set, a trap will remain in place until\n\
stepped on or disarmed.\n\
\n\
To disarm a trap, examine ('e') the space it is on. Your success depends\n\
upon your Traps skill and Dexterity. If you succeed, the trap is removed\n\
and replaced by some or all of its constituent parts; however, if you fail,\n\
there is a chance that you will set off the trap, suffering the consequences.\n\
\n\
Many traps are fully or partially hidden. Your ability to detect traps is\n\
entirely dependent upon your Perception. Should you stumble into a trap, you\n\
may have a chance to avoid it, depending on your Dodge skill."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'l':
  case 'L':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
There are a wide variety of items available for your use. You may find them\n\
lying on the ground; if so, simply press ',' or 'g' to pick up items on the\n\
same square. Some items are found inside a container, drawn as a { with a\n\
blue background. Pressing 'e', then a direction, will allow you to examine\n\
these containers and loot their contents.\n\
\n\
Pressing 'I' opens a comparison menu, where you can see two items\n\
side-by-side with their attributes highlighted to indicate which is superior.\n\
You can also access the item comparison menu by pressing 'C' when the 'V'iew\n\
nearby items menu is open and an item is selected.\n\
\n\
All items may be used as a melee weapon, though some are better than others.\n\
You can check the melee attributes of an item you're carrying by hitting 'i'\n\
to enter your inventory, then pressing the letter of the item. There are 3\n\
melee values, bashing, cutting, and to-hit bonus (or penalty).\n\
Bashing damage is universally effective, but is capped by low strength.\n\
Cutting damage is a guaranteed increase in damage, but it may be reduced by\n\
a monster's natural armor.\n\
\n\
Press any key for more..."));
    wrefresh(w_help);
    refresh();
    getch();
    werase(w_help);
    mvwprintz(w_help, 0, 0, c_white, _("\
To wield an item as a weapon, press 'w' then the proper letter. Pressing '-'\n\
in lieu of a letter will make you wield nothing. A wielded weapon will not\n\
contribute to your volume carried, so holding a large item in your hands may\n\
be a good option for travel. When unwielding your weapon, it will go back in\n\
your inventory, or will be dropped on the ground if there is no space.\n\
\n\
To wear a piece of clothing, press 'W' then the proper letter. Armor reduces\n\
damage and helps you resist things like smoke. To take off an item, press\n\
'T' then the proper letter."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'm':
  case 'M':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
After 30 minutes of warmup time, monsters will begin to appear. They are\n\
represented by letters on your screen; a list of monster names, and their\n\
positions relative to you, is displayed on the right side of the screen.\n\
\n\
To attack a monster with a melee weapon, simply move into them. The time it\n\
takes to attack depends on the size and weight of your weapon. Small, light\n\
weapons are the fastest; unarmed attacks increase in speed with your Unarmed\n\
Combat skill, and will eventually be VERY fast. A successful hit with a\n\
bashing weapon may stun the monster temporarily, while cutting weapons may get\n\
stuck, possibly pulling the weapon from your hands--but a monster with a weapon\n\
stuck in it will move much more slowly. A miss may make you stumble and lose\n\
movement points. If a monster hits you, your clothing may absorb some damage,\n\
but you will absorb the excess.\n\
\n\
Swarms of monsters may call for firearms. If you find one, wield it first,\n\
then reload by pressing 'r'. If you wish to change ammo, you must unload the\n\
weapon by pressing 'U', then reload again. To fire, press 'f', move the\n\
cursor to the relevant space, then hit '.' or 'f'. Some guns have automatic\n\
fire; to shoot a burst, press 'F'. This will severely reduce accuracy.\n\
\n\
Unlike most roguelikes, fleeing will often be your best option, especially\n\
when overwhelmed by a swarm of zombies. Try to avoid getting cornered inside\n\
a building. Ducking down into the subways or sewers is often an excellent\n\
escape tactic."));
  wrefresh(w_help);
  refresh();
  getch();
  break;

  case 'n':
  case 'N':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
For the unarmed fighter, a variety of fighting styles are available. You can\n\
start with your choice of a single, commonly-taught style by starting with\n\
the Martial Arts Training trait. Many, many more can be taught by wandering\n\
masters.\n\
\n\
To select a fighting style, press _ (underscore). If you are already unarmed\n\
this will make you start using the style. Otherwise, it will be locked in as\n\
your default unarmed style; to start using it, press w-.\n\
\n\
Most styles have a variety of special moves associated with them. Most have\n\
a skill requirement, and will be unavailable until you reach a level of\n\
unarmed skill. You can check the moves by examining your style via the\n\
inventory screen (i key).\n\
\n\
Many styles also have special effects unlocked under certain conditions.\n\
These are varied and unique to each style, and range from special combo moves\n\
to bonuses depending on the situation you are in. You can check these by\n\
examining your style."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case 'o':
  case 'O':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
The first thing to do is to check your home for useful items. Your initial\n\
storage is limited, and a backpack, trenchcoat, or other storage medium will\n\
let you carry a lot more. Finding a weapon is important; frying pans, butcher\n\
knives, and more are common in your home; hardware stores may carry others.\n\
Unless you plan on concentrating on melee combat, seek out gun stores as soon\n\
as possible and load up on more than one type.\n\
\n\
It's also important to carry a few medications; painkillers are a must-have,\n\
and drugs such as cigarettes will make life easier (but beware addiction).\n\
Leave cities as soon as you have a good stockpile of equipment. Their high\n\
concentration of zombies makes them a deathtrap--but a necessary resource for\n\
food and ammunition.\n\
\n\
Combat is much easier if you can fight just one monster at once. Use doorways\n\
as a choke point, or stand behind a window and strike as the zombies slowly\n\
climb through. Never be afraid to just run if you can outpace your enemies.\n\
Irregular terrain, like forests, may help you lose monsters.\n\
\n\
Firearms are the easiest way to kill an enemy, but the sound will attract\n\
unwanted attention. Save the guns for emergencies, and melee when you can.\n\
\n\
Press any key for more..."));
    wrefresh(w_help);
    refresh();
    getch();
    werase(w_help);
    mvwprintz(w_help, 0, 0, c_white, _("\
Try to keep your inventory as full as possible without being overloaded. You\n\
never know when you might need an item, most are good to sell, and you can\n\
easily drop unwanted items on the floor.\n\
\n\
Keep an eye on the weather. At night, sleeping might be difficult if you\n\
don't have a warm place to rest your head. Be sure to protect your\n\
extremities from frostbite and to keep your distance from large fires."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case '1': {
   werase(w_help);
   int offset = 1;
   char ch = ' ';
   bool changed_keymap = false;
   bool needs_refresh = true;
   do {
    if (needs_refresh) {
     werase(w_help);
     mvwprintz(w_help, 0, 50, c_white, _("Use the arrow keys"));
     mvwprintz(w_help, 1, 50, c_white, _("(or movement keys)"));
     mvwprintz(w_help, 2, 50, c_white, _("to scroll."));

     mvwprintz(w_help, 4, 50, c_white, _("Press ESC or q to return."));

     mvwprintz(w_help, 6, 50, c_white, _("Press - to remove all"));
     mvwprintz(w_help, 7, 50, c_white, _("keybindings from an action."));

     mvwprintz(w_help, 9, 50, c_white, _("Press + to add the"));
     mvwprintz(w_help, 10, 50, c_white, _("keybindingfor an action."));
     needs_refresh = false;
    }
// Clear the lines
    for (int i = 0; i < 23; i++)
     mvwprintz(w_help, i, 0, c_black, "                                        ");

    for (int i = 0; i < 23 && offset + i < NUM_ACTIONS; i++) {
     std::vector<char> keys = keys_bound_to( action_id(offset + i) );
     nc_color col = (keys.empty() ? c_ltred : c_white);
     mvwprintz(w_help, i, 3, col, "%s: ", action_name( action_id(offset + i) ).c_str());
     if (keys.empty())
      wprintz(w_help,c_red, _("Unbound!"));
     else {
      for (int j = 0; j < keys.size(); j++) {
       wprintz(w_help,c_yellow, "%c", keys[j]);
       if (j < keys.size() - 1)
        wprintz(w_help,c_white, _(" or "));
      }
     }
    }
    wrefresh(w_help);
    refresh();
    ch = input();
    int sx = 0, sy = 0;
    get_direction(this, sx, sy, ch);
    if (sy == -1 && offset > 1)
     offset--;
    if (sy == 1 && offset + 20 < NUM_ACTIONS)
     offset++;
    if (ch == '-' || ch == '+') {
     needs_refresh = true;
     for (int i = 0; i < 23 && i + offset < NUM_ACTIONS; i++) {
      mvwprintz(w_help, i, 0, c_ltblue, "%c", 'a' + i);
      mvwprintz(w_help, i, 1, c_white, ":");
     }
     wrefresh(w_help);
     refresh();
     char actch = getch();
     if (actch >= 'a' && actch <= 'a' + 24 &&
         actch - 'a' + offset < NUM_ACTIONS) {
      action_id act = action_id(actch - 'a' + offset);
      if (ch == '-' && query_yn(_("Clear keys for %s?"),action_name(act).c_str())){
       clear_bindings(act);
       changed_keymap = true;
      } else if (ch == '+') {
       char newbind = popup_getkey(_("New key for %s:"), action_name(act).c_str());
       if (keymap.find(newbind) == keymap.end()) { // It's not in use!  Good.
        keymap[ newbind ] = act;
        changed_keymap = true;
       } else
        popup(_("%c is used for %s."), newbind,
              action_name( keymap[newbind] ).c_str());
      }
     }
    }
   } while (ch != 'q' && ch != 'Q' && ch != KEY_ESCAPE);
   if (changed_keymap && query_yn(_("Save changes?")))
    save_keymap();
   werase(w_help);
  } break;

  case '2': {
   show_options();
   werase(w_help);
  } break;

  case '3':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
ITEM TYPES:\n\
~       Liquid\n\
%%%%       Food\n\
!       Medication\n\
    These are all consumed by using 'E'. They provide a certain amount of\n\
 nutrition, quench your thirst, may be a stimulant or a depressant, and may\n\
 provide morale. There may also be more subtle effects.\n\
\n\
/       Large weapon\n\
;       Small weapon or tool\n\
,       Tiny item\n\
    These are all generic items, useful only to be wielded as a weapon.\n\
 However, some have special uses; they will show up under the TOOLS section\n\
 in your inventory. Press 'a' to use these.\n\
\n\
)       Container\n\
    These items may hold other items. Someare passable weapons. Many will be\n\
 listed with their contents, e.g. \"plastic bottle of water\". Those containing\n\
 comestibles may be eaten with 'E'; this may leave you with an empty container.\n\
Press any key to continue..."));
   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
ITEM TYPES:\n\
[       Clothing\n\
    This may be worn with the 'W' key or removed with the 'T' key. It may\n\
 cover one or more body parts; you can wear multiple articles of clothing on\n\
 any given body part, but this will encumber you severely. Each article of\n\
 clothing may provide storage space, warmth, an encumberment, and a resistance\n\
 to bashing and/or cutting attacks. Some may protect against environmental\n\
 effects.\n\
\n\
(       Firearm\n\
    This weapon may be loaded with ammunition with 'r', unloaded with 'U', and\n\
 fired with 'f'. Some have automatic fire, which may be used with 'F' at a\n\
 penalty to accuracy. The color refers to the type; handguns are gray, shotguns\n\
 are red, submachine guns are cyan, rifles are brown, assault rifles are blue,\n\
 and heavy machine guns are light red. Each has an accuracy rating, a bonus to\n\
 damage, a rate of fire, and a maximum load. Note that most firearms load\n\
 fully in one action, while shotguns must be loaded one shell at a time.\n\
\n\
=       Ammunition\n\
    Ammunition is worthless without a gun to load it into. Generally, there\n\
 are several variants for any particular calibre. Ammunition has a damage\n\
 rating, an accuracy, a range, and an armor-piercing quality.\n\
Press any key to continue..."));
   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
ITEM TYPES:\n\
\n\
*       Thrown weapon; simple projectile or grenade\n\
    These items are suited for throwing, and many are only useful when\n\
 thrown, such as grenades, molotov cocktails, or tear gas.\n\
\n\
?       Book or magazine\n\
    This can be read for training or entertainment by pressing 'R'. Most\n\
 require a basic level of intelligence; some require some base knowledge in\n\
 the relevant subject."));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case '4':
   werase(w_help);
   mvwprintz(w_help,  0, 0, c_ltgray,  _("MAP SYMBOLS:"));
   mvwprintz(w_help,  1, 0, c_brown,   _("\
.           Field - Empty grassland, occasional wild fruit."));
   mvwprintz(w_help,  2, 0, c_green,   _("\
F           Forest - May be dense or sparse. Slow moving; foragable food."));
   mvputch(3,  0, c_dkgray, LINE_XOXO);
   mvputch(3,  1, c_dkgray, LINE_OXOX);
   mvputch(3,  2, c_dkgray, LINE_XXOO);
   mvputch(3,  3, c_dkgray, LINE_OXXO);
   mvputch(3,  4, c_dkgray, LINE_OOXX);
   mvputch(3,  5, c_dkgray, LINE_XOOX);
   mvputch(3,  6, c_dkgray, LINE_XXXO);
   mvputch(3,  7, c_dkgray, LINE_XXOX);
   mvputch(3,  8, c_dkgray, LINE_XOXX);
   mvputch(3,  9, c_dkgray, LINE_OXXX);
   mvputch(3, 10, c_dkgray, LINE_XXXX);

   mvwprintz(w_help,  3, 12, c_dkgray,  _("\
Road - Safe from burrowing animals."));
   mvwprintz(w_help,  4, 0, c_dkgray,  _("\
H=          Highway - Like roads, but lined with guard rails."));
   mvwprintz(w_help,  5, 0, c_dkgray,  _("\
|-          Bridge - Helps you cross rivers."));
   mvwprintz(w_help,  6, 0, c_blue,    _("\
R           River - Most creatures can not swim across them, but you may."));
   mvwprintz(w_help,  7, 0, c_dkgray,  _("\
O           Parking lot - Empty lot, few items. Mostly useless."));
   mvwprintz(w_help,  8, 0, c_ltgreen, _("\
^>v<        House - Filled with a variety of items. Good place to sleep."));
   mvwprintz(w_help,  9, 0, c_ltblue,  _("\
^>v<        Gas station - Good place to collect gasoline. Risk of explosion."));
   mvwprintz(w_help, 10, 0, c_ltred,   _("\
^>v<        Pharmacy - The best source for vital medications."));
   mvwprintz(w_help, 11, 0, c_green,   _("\
^>v<        Grocery store - Good source of canned food and other supplies."));
   mvwprintz(w_help, 12, 0, c_cyan,    _("\
^>v<        Hardware store - Home to tools, melee weapons and crafting goods."));
   mvwprintz(w_help, 13, 0, c_ltcyan,  _("\
^>v<        Sporting Goods store - Several survival tools and melee weapons."));
   mvwprintz(w_help, 14, 0, c_magenta, _("\
^>v<        Liquor store - Alcohol is good for crafting molotov cocktails."));
   mvwprintz(w_help, 15, 0, c_red,     _("\
^>v<        Gun store - Firearms and ammunition are very valuable."));
   mvwprintz(w_help, 16, 0, c_blue,    _("\
^>v<        Clothing store - High-capacity clothing, some light armor."));
   mvwprintz(w_help, 17, 0, c_brown,   _("\
^>v<        Library - Home to books, both entertaining and informative."));
   mvwprintz(w_help, 18, 0, c_white, _("\
^>v< are always man-made buildings. The pointed side indicates the front door."));

   mvwprintz(w_help, 22, 0, c_ltgray, _("There are many others out there... search for them!"));
   wrefresh(w_help);
   refresh();
   getch();
   break;

  case '5':
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("Gun types:"));
   mvwprintz(w_help, 2, 0, c_ltgray, _("( Handguns"));
   mvwprintz(w_help, 3, 0, c_white, _("\
Handguns are small weapons held in one or both hands. They are much more\n\
difficult to aim and control than larger firearms, and this is reflected in\n\
their poor accuracy. However, their small size makes them appropriate for\n\
short-range combat, where largers guns fare poorly.\n\
They are also relatively quick to reload, and use a very wide selection of\n\
ammunition. Their small size and low weight make it possible to carry\n\
several loaded handguns, switching from one to the next once their ammo is\n\
spent."));
   mvwprintz(w_help, 12, 0, c_green, _("( Crossbows"));
   mvwprintz(w_help, 13, 0, c_white, _("\
The best feature of crossbows is their silence. The bolts they fire are only\n\
rarely destroyed; if you pick up the bolts after firing them, your ammunition\n\
will last much longer. Crossbows suffer from a short range and a very long\n\
reload time (modified by your strength); plus, most only hold a single round.\n\
For this reason, it is advisable to carry a few loaded crossbows.\n\
Crossbows can be very difficult to find; however, it is possible to craft one\n\
given enough Mechanics skill. Likewise, it is possible to make wooden bolts\n\
from any number of wooden objects, though these are much less effective than\n\
steel bolts.\n\
Crossbows use the handgun skill."));
   mvwprintz(w_help, 24, 0, c_white, _("Press any key to continue..."));

   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("Gun types:"));
   mvwprintz(w_help, 2, 0, c_red, _("( Shotguns"));
   mvwprintz(w_help, 3, 0, c_white, _("\
Shotguns are one of the most powerful weapons in the game, capable of taking\n\
out almost any enemy with a single hit. Birdshot and 00 shot spread, making\n\
it very easy to hit nearby monsters. However, they are very ineffective\n\
against armor, and some armored monsters might shrug off 00 shot completely.\n\
Shotgun slugs are the answer to this problem; they also offer much better\n\
range than shot.\n\
The biggest drawback to shotguns is their noisiness. They are very loud,\n\
and impossible to silence. A shot that kills one zombie might attract three\n\
more! Because of this, shotguns are best reserved for emergencies."));
   mvwprintz(w_help, 13, 0, c_cyan, _("( Submachine Guns"));
   mvwprintz(w_help, 14, 0, c_white, _("\
Submachine guns are small weapons (some are barely larger than a handgun),\n\
designed for relatively close combat and the ability to spray large amounts\n\
of bullets. However, they are more effective when firing single shots, so\n\
use discretion. They mainly use the 9mm and .45 ammunition; however, other\n\
SMGs exist. They reload moderately quickly, and are suitable for close or\n\
medium-long range combat."));
   mvwprintz(w_help, 22, 0, c_white, _("Press any key to continue..."));

   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("Gun types:"));
   mvwprintz(w_help, 2, 0, c_brown, _("( Hunting Rifles"));
   mvwprintz(w_help, 3, 0, c_white, _("\
Hunting rifles are popular for their superior range and accuracy. What's\n\
more, their scopes or sights make shots fired at targets more than 10 tiles\n\
away as accurate as those with a shorter range. However, they are very poor\n\
at hitting targets 4 squares or less from the player.\n\
Unlike assault rifles, hunting rifles have no automatic fire. They are also\n\
slow to reload and fire, so when facing a large group of nearby enemies, they\n\
are not the best pick."));
   mvwprintz(w_help, 11, 0, c_blue, _("( Assault Rifles"));
   mvwprintz(w_help, 12, 0, c_white, _("\
Assault rifles are similar to hunting rifles in many ways; they are also\n\
suited for long range combat, with similar bonuses and penalties. Unlike\n\
hunting rifles, assault rifles are capable of automatic fire. Assault rifles\n\
are less accurate than hunting rifles, and this is worsened under automatic\n\
fire, so save it for when you're highly skilled.\n\
Assault rifles are an excellent choice for medium or long range combat, or\n\
even close-range bursts again a large number of enemies. They are difficult\n\
to use, and are best saved for skilled riflemen."));
   mvwprintz(w_help, 24, 0, c_white, _("Press any key to continue..."));

   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("Gun types:"));
   mvwprintz(w_help, 2, 0, c_ltred, _("( Machine Guns"));
   mvwprintz(w_help, 3, 0, c_white, _("\
Machine guns are one of the most powerful firearms available. They are even\n\
larger than assault rifles, and make poor melee weapons; however, they are\n\
capable of holding 100 or more rounds of highly-damaging ammunition. They\n\
are not built for accuracy, and firing single rounds is not very effective.\n\
However, they also possess a very high rate of fire and somewhat low recoil,\n\
making them very good at clearing out large numbers of enemies."));
   mvwprintz(w_help, 10, 0, c_magenta, _("( Energy Weapons"));
   mvwprintz(w_help, 11, 0, c_white, _("\
Energy weapons is an umbrella term used to describe a variety of rifles and\n\
handguns which fire lasers, plasma, or energy atttacks. They started to\n\
appear in military use just prior to the start of the apocalypse, and as such\n\
are very difficult to find.\n\
Energy weapons have no recoil at all; they are nearly silent, have a long\n\
range, and are fairly damaging. The biggest drawback to energy weapons is\n\
scarcity of ammunition; it is wise to reserve the precious ammo for when you\n\
really need it."));
   mvwprintz(w_help, 24, 0, c_white, _("Press any key to continue..."));

   wrefresh(w_help);
   refresh();
   getch();
   break;

  case '6':
   mvwprintz(w_help, 0, 0, c_white, _("\
Q: What is Run Mode, and why does it prevent me from moving?\n\
A: Run Mode is a way to guarantee that you won't die by holding a movement\n\
   key down. When a monster comes into view, your movement will be ignored\n\
   until Run Mode is turned off with the ! key. This ensures that the\n\
   sudden appearence of a monster won't catch you off guard.\n\
\n\
Q: It seems like everything I eat makes me sick! What's wrong?\n\
A: Lots of the food found in towns is perishable, and will only last a few\n\
   days after the start of a new game (July 12). Fruit, milk, and others are\n\
   the first to go. After the first couple of days, you should switch to\n\
   canned food, jerky, and hunting.\n\
\n\
Q: Why doesn't reading a book seem to give me any training?\n\
A: Your skills will not be displayed in the @ screen until they reach level\n\
   one. Generally it will take several reads of the same book to gain a\n\
   single level in a skill.\n\
\n\
Q: How can I board up windows and doors?\n\
A: You'll need a hammer, nails, and two by fours. Use the hammer and choose\n\
   the direction in which the terrain you wish to barricade lies.\n\
\n\
Q: How can I prevent monsters from attacking while I sleep?\n\
A: Find a safe place to sleep, in a building far from the front door. Set\n\
   traps if you have them, or build a fire."));

   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Q: Why do I always sink when I try to swim?\n\
A: Your swimming ability is reduced greatly by the weight you are carrying,\n\
   and is also adversely affected by the clothing you wear. Until you reach\n\
   a high level in the swimming skill, you'll need to drop your equipment and\n\
   remove your clothing to swim, making it a last-ditch escape plan.\n\
\n\
Q: How can I cure a fungal infection?\n\
A: At present time, there is only one cure, royal jelly. You can find royal\n\
   jelly in the bee hives which dot forests.\n\
\n\
Q: How do I get into science labs?\n\
A: You can enter the front door if you have an ID card by 'e'xamining the\n\
   keypad. If you are skilled in computers and have an electrohack, it is\n\
   possible to hack the keypad. An EMP blast has a chance to force the doors\n\
   open, but it's more likely to break them. You can also sneak in through\n\
   the sewers sometimes, or try to smash through the walls with explosions.\n\
\n\
Q: Why does my crafting fail so often?\n\
A: Check the difficulty of the recipe, and the primary skill used; your skill\n\
   level should be around one and a half times the difficulty to be confident\n\
   that it will succeed."));

   wrefresh(w_help);
   refresh();
   getch();
   werase(w_help);
   mvwprintz(w_help, 0, 0, c_white, _("\
Q: Shotguns bring in more zombies than they kill!  What's the point?\n\
A: Shotguns are intended for emergency use. If you are cornered, use your\n\
   shotgun to escape, then just run from the zombies it attracts.\n\
\n\
Q: The game just told me to quit, and other weird stuff is happening.\n\
A: You have the Schizophrenic trait, which might make the game seem buggy.\n\
\n\
Q: I have a question that's not addressed here. How can I get an answer?\n\
A: Email your question to TheDarklingWolf@Gmail.com. I'll answer it for you,\n\
   and possibly include it on this list."));

   wrefresh(w_help);
   refresh();
   getch();
   break;

  }
 } while (ch != 'q' && ch != KEY_ESCAPE);

 werase(w_help);
}
