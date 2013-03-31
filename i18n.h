#ifndef I18N_H
#define I18N_H

#define _INTL_REDIRECT_MACROS
#include <libintl.h>
#include <string>
#include <vector>
#include <algorithm>

/*
#define _(msg) gettext((msg))
#define N_(msg) (msg)
#define P_(msg1, msg2, n) ngettext((msg1), (msg2), (n))
/*/
#define _(msg) Z_(__FILE__, __LINE__, (msg))
#define N_(msg) (msg)
#define P_(msg1, msg2, n) ZP_(__FILE__, __LINE__, (msg1), (msg2), (n))
//*/

const char* Z_(const char* file, int line, const char* str);
const char* ZP_(const char* file, int line, const char* str1, const char* str2, int plural);

namespace i18n
{
  void init();
  std::string format(const std::string& format, ...);
  std::string &replace(std::string &str, const std::string &pattern, const std::string &replacement);
  std::string &trim(std::string &source, const std::string &pattern = " \t\r\n");
  std::string wordwrap(const std::string &str, size_t width);
  std::vector<std::string> splitc(const std::string &str, char delim = '\n');
  std::vector<std::string> splitw(const std::string &str, size_t width);
}

#endif//I18N_H

