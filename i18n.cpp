#include "i18n.h"
#include "cfgxx.h"

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
#include "mapdata.h"
#include "moraledata.h"
#include "skill.h"

#include <vector>
#include <sstream>
#include <cstdio>
#include <cstdarg>

#define FOR_BEGIN(array, index) \
  for (int (index) = 0; (index) < (sizeof((array)) / sizeof((array)[0])); (index)++) {

#define FOR_END() \
  }

#define TRANSLATE(array, index) \
  if (!array[(index)].empty()) { \
    const_cast<string&>(array[(index)]) = gettext(array[(index)].c_str()); \
  }

#define TRANSLATE_MEMBER(array, index, member) \
  if (!array[(index)].member.empty()) { \
    const_cast<string&>(array[(index)].member) = gettext(array[(index)].member.c_str()); \
  }

void i18n::init()
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
    putenv((char *)ss.str().c_str());
  }
  setlocale(LC_ALL, "");
  bindtextdomain(PROJECT_NAME, LOCALEDIR);
  textdomain(PROJECT_NAME);

  //
  // TRANSLATE STRINGS ON HEADER FILES
  //

  // artifact data (shape)
  FOR_BEGIN(artifact_shape_data, i)
    TRANSLATE_MEMBER(artifact_shape_data, i, name);
    TRANSLATE_MEMBER(artifact_shape_data, i, desc);
  FOR_END()

  // artifact data (property)
  FOR_BEGIN(artifact_property_data, i)
    TRANSLATE_MEMBER(artifact_property_data, i, name);
    TRANSLATE_MEMBER(artifact_property_data, i, desc);
  FOR_END()

  // artifact data (form)
  FOR_BEGIN(artifact_tool_form_data, i)
    TRANSLATE_MEMBER(artifact_tool_form_data, i, name);
  FOR_END()

  // artifact data (weapon)
  FOR_BEGIN(artifact_weapon_data, i)
    TRANSLATE_MEMBER(artifact_weapon_data, i, adjective);
  FOR_END()

  // artifact data (armor)
  FOR_BEGIN(artifact_armor_form_data, i)
    TRANSLATE_MEMBER(artifact_armor_form_data, i, name);
  FOR_END()

  // artifact data (mod)
  FOR_BEGIN(artifact_armor_mod_data, i)
    TRANSLATE_MEMBER(artifact_armor_mod_data, i, name);
  FOR_END()

  // artifact data (adjective)
  FOR_BEGIN(artifact_adj, i)
    TRANSLATE(artifact_adj, i);
  FOR_END()

  // artifact data (noun)
  FOR_BEGIN(artifact_noun, i)
    TRANSLATE(artifact_noun, i);
  FOR_END()

  // bionics
  FOR_BEGIN(bionics, i)
    TRANSLATE_MEMBER(bionics, i, name);
    TRANSLATE_MEMBER(bionics, i, description);
  FOR_END()

  // dialogues (trial)
  FOR_BEGIN(talk_trial_text, i)
    TRANSLATE(talk_trial_text, i);
  FOR_END()

  // dialogues (needs)
  FOR_BEGIN(talk_needs, i)
    FOR_BEGIN(talk_needs[i], j)
      TRANSLATE(talk_needs[i], j);
    FOR_END()
  FOR_END()

  // dialogues (okay)
  FOR_BEGIN(talk_okay, i)
    TRANSLATE(talk_okay, i);
  FOR_END()

  // dialogues (no)
  FOR_BEGIN(talk_no, i)
    TRANSLATE(talk_no, i);
  FOR_END()

  // dialogues (bad names)
  FOR_BEGIN(talk_bad_names, i)
    TRANSLATE(talk_bad_names, i);
  FOR_END()

  // dialogues (good names)
  FOR_BEGIN(talk_good_names, i)
    TRANSLATE(talk_good_names, i);
  FOR_END()

  // dialogues (swear)
  FOR_BEGIN(talk_swear, i)
    TRANSLATE(talk_swear, i);
  FOR_END()

  // dialogues (interjection)
  FOR_BEGIN(talk_swear_interjection, i)
    TRANSLATE(talk_swear_interjection, i);
  FOR_END()

  // dialogues (fuck you)
  FOR_BEGIN(talk_fuck_you, i)
    TRANSLATE(talk_fuck_you, i);
  FOR_END()

  // dialogues (very)
  FOR_BEGIN(talk_very, i)
    TRANSLATE(talk_very, i);
  FOR_END()

  // dialogues (really)
  FOR_BEGIN(talk_really, i)
    TRANSLATE(talk_really, i);
  FOR_END()

  // dialogues (happy)
  FOR_BEGIN(talk_happy, i)
    TRANSLATE(talk_happy, i);
  FOR_END()

  // dialogues (sad)
  FOR_BEGIN(talk_sad, i)
    TRANSLATE(talk_sad, i);
  FOR_END()

  // dialogues (greeting)
  FOR_BEGIN(talk_greeting_gen, i)
    TRANSLATE(talk_greeting_gen, i);
  FOR_END()

  // dialogues (ill die)
  FOR_BEGIN(talk_ill_die, i)
    TRANSLATE(talk_ill_die, i);
  FOR_END()

  // dialogues (kill you)
  FOR_BEGIN(talk_ill_kill_you, i)
    TRANSLATE(talk_ill_kill_you, i);
  FOR_END()

  // dialogues (drop weapon)
  FOR_BEGIN(talk_drop_weapon, i)
    TRANSLATE(talk_drop_weapon, i);
  FOR_END()

  // dialogues (hands up)
  FOR_BEGIN(talk_hands_up, i)
    TRANSLATE(talk_hands_up, i);
  FOR_END()

  // dialogues (no faction)
  FOR_BEGIN(talk_no_faction, i)
    TRANSLATE(talk_no_faction, i);
  FOR_END()

  // dialogues (come here)
  FOR_BEGIN(talk_come_here, i)
    TRANSLATE(talk_come_here, i);
  FOR_END()

  // dialogues (keep up)
  FOR_BEGIN(talk_keep_up, i)
    TRANSLATE(talk_keep_up, i);
  FOR_END()

  // dialogues (wait)
  FOR_BEGIN(talk_wait, i)
    TRANSLATE(talk_wait, i);
  FOR_END()

  // dialogues (let me pass)
  FOR_BEGIN(talk_let_me_pass, i)
    TRANSLATE(talk_let_me_pass, i);
  FOR_END()

  // dialogues (move)
  FOR_BEGIN(talk_move, i)
    TRANSLATE(talk_move, i);
  FOR_END()

  // dialogues (done mugging)
  FOR_BEGIN(talk_done_mugging, i)
    TRANSLATE(talk_done_mugging, i);
  FOR_END()

  // dialogues (leaving)
  FOR_BEGIN(talk_leaving, i)
    TRANSLATE(talk_leaving, i);
  FOR_END()

  // dialogues (catch up)
  FOR_BEGIN(talk_catch_up, i)
    TRANSLATE(talk_catch_up, i);
  FOR_END()

  // faction (adjective positive)
  FOR_BEGIN(faction_adj_pos, i)
    TRANSLATE(faction_adj_pos, i);
  FOR_END()

  // faction (adjective neutral)
  FOR_BEGIN(faction_adj_neu, i)
    TRANSLATE(faction_adj_neu, i);
  FOR_END()

  // faction (adjective bad)
  FOR_BEGIN(faction_adj_bad, i)
    TRANSLATE(faction_adj_bad, i);
  FOR_END()

  // faction (noun strong)
  FOR_BEGIN(faction_noun_strong, i)
    TRANSLATE(faction_noun_strong, i);
  FOR_END()

  // faction (noun sneak)
  FOR_BEGIN(faction_noun_sneak, i)
    TRANSLATE(faction_noun_sneak, i);
  FOR_END()

  // faction (noun crime)
  FOR_BEGIN(faction_noun_crime, i)
    TRANSLATE(faction_noun_crime, i);
  FOR_END()

  // faction (noun cult)
  FOR_BEGIN(faction_noun_cult, i)
    TRANSLATE(faction_noun_cult, i);
  FOR_END()

  // faction (noun none)
  FOR_BEGIN(faction_noun_none, i)
    TRANSLATE(faction_noun_none, i);
  FOR_END()

  // faction (goal)
  FOR_BEGIN(facgoal_data, i)
  TRANSLATE_MEMBER(facgoal_data, i, name);
  FOR_END()

  // faction (job)
  FOR_BEGIN(facjob_data, i)
  TRANSLATE_MEMBER(facjob_data, i, name);
  FOR_END()

  // faction (val?)
  FOR_BEGIN(facval_data, i)
  TRANSLATE_MEMBER(facval_data, i, name);
  FOR_END()

  // oterlist
  FOR_BEGIN(oterlist, i)
  TRANSLATE_MEMBER(oterlist, i, name);
  FOR_END()

  // pltype_name
  FOR_BEGIN(pltype_name, i)
    TRANSLATE(pltype_name, i);
  FOR_END()

  // pltype_desc
  FOR_BEGIN(pltype_desc, i)
    TRANSLATE(pltype_desc, i);
  FOR_END()

  // traits
  FOR_BEGIN(traits, i)
    TRANSLATE_MEMBER(traits, i, name);
    TRANSLATE_MEMBER(traits, i, description);
  FOR_END()

  // tutorial texts
  FOR_BEGIN(tut_text, i)
    TRANSLATE(tut_text, i);
  FOR_END()

  // vehicle parts
  FOR_BEGIN(vpart_list, i)
  TRANSLATE_MEMBER(vpart_list, i, name);
  FOR_END()

  // weather data
  FOR_BEGIN(weather_data, i)
  TRANSLATE_MEMBER(weather_data, i, name);
  FOR_END()

  // inventory_ui.h
  FOR_BEGIN(CATEGORIES, i)
    TRANSLATE(CATEGORIES, i);
  FOR_END()

  FOR_BEGIN(terlist, i)
    TRANSLATE_MEMBER(terlist, i, name);
  FOR_END()

  FOR_BEGIN(fieldlist, i)
    FOR_BEGIN(fieldlist[i].name, j)
      TRANSLATE(fieldlist[i].name, j);
    FOR_END()
  FOR_END()

  FOR_BEGIN(morale_data, i)
    TRANSLATE(morale_data, i);
  FOR_END()

  for (std::vector<Skill*>::iterator it = Skill::skills.begin(); it != Skill::skills.end(); it++) {
    (*it)->name(gettext((*it)->name().c_str()));
    (*it)->description(gettext((*it)->description().c_str()));
  }
}

std::string _format(const std::string &fmt, va_list ap)
{
  const int N = 1024;
  char buffer[N];
#if defined(_MSC_VER)
  vsnprintf_s(buffer, N, _TRUNCATE, fmt.c_str(), ap);
#else
  vsnprintf(buffer, N, fmt.c_str(), ap);
#endif
  return std::string(buffer);
}

std::string i18n::format(const std::string &fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  std::string str = _format(fmt, ap);
  va_end(ap);
  return str;
}

std::string &i18n::replace(std::string &str, const std::string &pattern, const std::string &replacement)
{
  std::string::size_type start = 0;
  std::string::size_type pos = std::string::npos;
  while ((pos = str.find(pattern, start)) != std::string::npos)
  {
    str.replace(pos, pattern.length(), replacement);
    start = pos + replacement.length();
  }
  return str;
}

std::string &i18n::trim(std::string &source, const std::string &pattern)
{
  source.erase(0, source.find_first_not_of(pattern));
  source.erase(source.find_last_not_of(pattern) + 1);
  return source;
}

std::string _wordwrap(const std::string &str, int width, bool space)
{
  std::setlocale(LC_ALL, "");
  std::ostringstream ss;
  for (size_t i = 0; i < str.length(); )
  {
    std::string buffer;
    int j = 0;
    while (i + j < str.length())
    {
      int len = mblen(str.data() + i + j, MB_CUR_MAX);
      if (width <= buffer.length())
        break;
      buffer += str.substr(i + j, len);
      j += len;
    }
    if (str.length() <= i + j)
    {
      i18n::replace(buffer, "\n", space ? " " : "");
      ss << buffer;
      i += j;
    }
    else
    {
      size_t sp = space ? buffer.rfind(' ') : std::string::npos;
      if (str[i + j] == ' ' || sp == std::string::npos)
      {
        i18n::replace(buffer, "\n", space ? " " : "");
        ss << buffer + '\n';
        i += j;
      }
      else
      {
        i18n::replace(buffer, "\n", space ? " " : "");
        ss << buffer.substr(0, sp) + '\n';
        i += sp + 1;
      }
    }
  }
  return ss.str();
}

std::string i18n::wordwrap(const std::string &str, int width)
{
  return _wordwrap(str, width, str.find(' ') != std::string::npos);
}
