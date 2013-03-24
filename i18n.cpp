#include "i18n.h"
#include "cfgxx.h"
#include <sstream>

#include "artifactdata.h"
#include "bionics.h"
#include "dialogue.h"
#include "facdata.h"
#include "omdata.h"
#include "pldata.h"
#include "tutorial.h"
#include "veh_type.h"
#include "weather_data.h"
#include "inventory_ui.h"

#define FOR_BEGIN(array, index) \
  for (int (index) = 0; (index) < (sizeof((array)) / sizeof((array[0]))); (index)++) {

#define FOR_END() \
  }

#define TRANSLATE(str) \
  (str) = gettext((str).c_str())

void i18n_init()
{
  using namespace std;
  cfgxx::config config("data/i18n.ini");

  //
  // CHOOSE LOCALE AND TEXT DOMAIN
  //

  string locale(config.get<string>("lang"));
  if (!locale.empty())
  {
    ostringstream ss;
    ss << "LANG=" << locale;
    putenv((char*)ss.str().c_str());
  }
  setlocale(LC_ALL, "");
  bindtextdomain(PROJECT_NAME, LOCALEDIR);
  textdomain(PROJECT_NAME);

  //
  // TRANSLATE STRINGS ON HEADER FILES
  //

  // artifact data (shape)
  FOR_BEGIN(artifact_shape_data, i)
    artifact_shape_datum &shape =
      const_cast<artifact_shape_datum &>(artifact_shape_data[i]);
    TRANSLATE(shape.name);
    TRANSLATE(shape.desc);
  FOR_END()
  
  // artifact data (property)
  FOR_BEGIN(artifact_property_data, i)
    artifact_property_datum &property =
      const_cast<artifact_property_datum &>(artifact_property_data[i]);
    TRANSLATE(property.name);
    TRANSLATE(property.desc);
  FOR_END()

  // artifact data (form)
  FOR_BEGIN(artifact_tool_form_data, i)
    artifact_tool_form_datum &form =
      const_cast<artifact_tool_form_datum &>(artifact_tool_form_data[i]);
    TRANSLATE(form.name);
  FOR_END()

  // artifact data (weapon)
  FOR_BEGIN(artifact_weapon_data, i)
    artifact_weapon_datum &weapon =
      const_cast<artifact_weapon_datum &>(
        artifact_weapon_data[i]);
    TRANSLATE(weapon.adjective);
  FOR_END()

  // artifact data (armor)
  FOR_BEGIN(artifact_armor_form_data, i)
    artifact_armor_form_datum &armor =
      const_cast<artifact_armor_form_datum &>(artifact_armor_form_data[i]);
    TRANSLATE(armor.name);
  FOR_END()

  // artifact data (mod)
  FOR_BEGIN(artifact_armor_mod_data, i)
    artifact_armor_form_datum &mod =
      const_cast<artifact_armor_form_datum &>(artifact_armor_mod_data[i]);
    TRANSLATE(mod.name);
  FOR_END()

  // artifact data (adjective)
  FOR_BEGIN(artifact_adj, i)
    string &adjective = const_cast<string &>(artifact_adj[i]);
    TRANSLATE(adjective);
  FOR_END()

  // artifact data (noun)
  FOR_BEGIN(artifact_noun, i)
    string &noun = const_cast<string &>(artifact_noun[i]);
    TRANSLATE(noun);
  FOR_END()

  // bionics
  FOR_BEGIN(bionics, i)
    bionic_data &bd = const_cast<bionic_data &>(bionics[i]);
    TRANSLATE(bd.name);
    TRANSLATE(bd.description);
  FOR_END()

  // dialogues (trial)
  FOR_BEGIN(talk_trial_text, i)
    string &str = const_cast<string &>(talk_trial_text[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (needs)
  FOR_BEGIN(talk_needs, i)
    string *pstr = const_cast<string *>(talk_needs[i]);
    for (int j = 0; j < 5; j++) {
      if (!pstr[j].empty()) {
        TRANSLATE(pstr[j]);
      }
    }
  FOR_END()

  // dialogues (okay)
  FOR_BEGIN(talk_okay, i)
    string &str = const_cast<string &>(talk_okay[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (no)
  FOR_BEGIN(talk_no, i)
    string &str = const_cast<string &>(talk_no[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (bad names)
  FOR_BEGIN(talk_bad_names, i)
    string &str = const_cast<string &>(talk_bad_names[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (good names)
  FOR_BEGIN(talk_good_names, i)
    string &str = const_cast<string &>(talk_good_names[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (swear)
  FOR_BEGIN(talk_swear, i)
    string &str = const_cast<string &>(talk_swear[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (interjection)
  FOR_BEGIN(talk_swear_interjection, i)
    string &str = const_cast<string &>(talk_swear_interjection[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (fuck you)
  FOR_BEGIN(talk_fuck_you, i)
    string &str = const_cast<string &>(talk_fuck_you[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (very)
  FOR_BEGIN(talk_very, i)
    string &str = const_cast<string &>(talk_very[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (really)
  FOR_BEGIN(talk_really, i)
    string &str = const_cast<string &>(talk_really[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (happy)
  FOR_BEGIN(talk_happy, i)
    string &str = const_cast<string &>(talk_happy[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (sad)
  FOR_BEGIN(talk_sad, i)
    string &str = const_cast<string &>(talk_sad[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (greeting)
  FOR_BEGIN(talk_greeting_gen, i)
    string &str = const_cast<string &>(talk_greeting_gen[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (ill die)
  FOR_BEGIN(talk_ill_die, i)
    string &str = const_cast<string &>(talk_ill_die[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (kill you)
  FOR_BEGIN(talk_ill_kill_you, i)
    string &str = const_cast<string &>(talk_ill_kill_you[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (drop weapon)
  FOR_BEGIN(talk_drop_weapon, i)
    string &str = const_cast<string &>(talk_drop_weapon[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (hands up)
  FOR_BEGIN(talk_hands_up, i)
    string &str = const_cast<string &>(talk_hands_up[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (no faction)
  FOR_BEGIN(talk_no_faction, i)
    string &str = const_cast<string &>(talk_no_faction[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (come here)
  FOR_BEGIN(talk_come_here, i)
    string &str = const_cast<string &>(talk_come_here[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (keep up)
  FOR_BEGIN(talk_keep_up, i)
    string &str = const_cast<string &>(talk_keep_up[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (wait)
  FOR_BEGIN(talk_wait, i)
    string &str = const_cast<string &>(talk_wait[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (let me pass)
  FOR_BEGIN(talk_let_me_pass, i)
    string &str = const_cast<string &>(talk_let_me_pass[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (move)
  FOR_BEGIN(talk_move, i)
    string &str = const_cast<string &>(talk_move[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (done mugging)
  FOR_BEGIN(talk_done_mugging, i)
    string &str = const_cast<string &>(talk_done_mugging[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (leaving)
  FOR_BEGIN(talk_leaving, i)
    string &str = const_cast<string &>(talk_leaving[i]);
    TRANSLATE(str);
  FOR_END()

  // dialogues (catch up)
  FOR_BEGIN(talk_catch_up, i)
    string &str = const_cast<string &>(talk_catch_up[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (adjective positive)
  FOR_BEGIN(faction_adj_pos, i)
    string& str = const_cast<string&>(faction_adj_pos[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (adjective neutral)
  FOR_BEGIN(faction_adj_neu, i)
    string& str = const_cast<string&>(faction_adj_neu[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (adjective bad)
  FOR_BEGIN(faction_adj_bad, i)
    string& str = const_cast<string&>(faction_adj_bad[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (noun strong)
  FOR_BEGIN(faction_noun_strong, i)
    string& str = const_cast<string&>(faction_noun_strong[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (noun sneak)
  FOR_BEGIN(faction_noun_sneak, i)
    string& str = const_cast<string&>(faction_noun_sneak[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (noun crime)
  FOR_BEGIN(faction_noun_crime, i)
    string& str = const_cast<string&>(faction_noun_crime[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (noun cult)
  FOR_BEGIN(faction_noun_cult, i)
    string& str = const_cast<string&>(faction_noun_cult[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (noun none)
  FOR_BEGIN(faction_noun_none, i)
    string& str = const_cast<string&>(faction_noun_none[i]);
    TRANSLATE(str);
  FOR_END()

  // faction (goal)
  FOR_BEGIN(facgoal_data, i)
    faction_value_datum& fac = const_cast<faction_value_datum&>(facgoal_data[i]);
    TRANSLATE(fac.name);
  FOR_END()

  // faction (job)
  FOR_BEGIN(facjob_data, i)
    faction_value_datum& fac = const_cast<faction_value_datum&>(facjob_data[i]);
    TRANSLATE(fac.name);
  FOR_END()

  // faction (val?)
  FOR_BEGIN(facval_data, i)
    faction_value_datum& fac = const_cast<faction_value_datum&>(facval_data[i]);
    TRANSLATE(fac.name);
  FOR_END()

  // oterlist
  FOR_BEGIN(oterlist, i)
    oter_t &o = const_cast<oter_t &>(oterlist[i]);
    TRANSLATE(o.name);
  FOR_END()

  // pltype_name
  FOR_BEGIN(pltype_name, i)
    string &name = const_cast<string &>(pltype_name[i]);
    TRANSLATE(name);
  FOR_END()

  // pltype_desc
  FOR_BEGIN(pltype_desc, i)
    string &desc = const_cast<string &>(pltype_desc[i]);
    TRANSLATE(desc);
  FOR_END()

  // traits
  FOR_BEGIN(traits, i)
    trait &t = const_cast<trait &>(traits[i]);
    TRANSLATE(t.name);
    TRANSLATE(t.description);
  FOR_END()

  // tutorial texts
  FOR_BEGIN(tut_text, i)
    string &tutorial = const_cast<string &>(tut_text[i]);
    TRANSLATE(tutorial);
  FOR_END()

  // vehicle parts
  FOR_BEGIN(vpart_list, i)
    vpart_info &part = const_cast<vpart_info &>(vpart_list[i]);
    TRANSLATE(part.name);
  FOR_END()

  // weather data
  FOR_BEGIN(weather_data, i)
    weather_datum &weather = const_cast<weather_datum &>(weather_data[i]);
    TRANSLATE(weather.name);
  FOR_END()

  // inventory_ui.h
  FOR_BEGIN(CATEGORIES, i)
    string cat = const_cast<string &>(CATEGORIES[i]);
    TRANSLATE(cat);
  FOR_END()
}

