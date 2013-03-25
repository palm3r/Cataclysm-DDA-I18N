#ifndef I18N_H
#define I18N_H

#include <string>
#include <libintl.h>

#define _(msg) gettext((msg))
#define N_(msg) (msg)
#define P_(msg1, msg2, n) ngettext((msg1), (msg2), (n))

void i18n_init();
std::string format(const std::string& format, ...);
std::string &replace(std::string &str, const std::string &pattern, const std::string &replacement);
std::string &trim(std::string &source, const std::string &pattern = " \t\r\n");

#endif//I18N_H

