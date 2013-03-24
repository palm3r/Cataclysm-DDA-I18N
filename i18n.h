#ifndef I18N_H
#define I18N_H

#include <libintl.h>
#define _(msg) gettext((msg))
#define N_(msg) (msg)
#define P_(msg1, msg2, n) ngettext((msg1), (msg2), (n))

void i18n_init();

#endif//I18N_H

