#ifndef I18N_H
#define I18N_H

#define _INTL_REDIRECT_MACROS
#include <libintl.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

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
  //std::string format(const std::string& format, ...);

  std::string &replace(std::string &str, const std::string &pattern, const std::string &replacement);
  std::string &trim(std::string &source, const std::string &pattern = " \t\r\n");
  std::string wordwrap(const std::string &str, size_t width);
  std::vector<std::string> splitc(const std::string &str, char delim = '\n');
  std::vector<std::string> splitw(const std::string &str, size_t width);

#define format(fmt, ...) \
  Z_format(__FILE__, __LINE__, fmt, __VA_ARGS__)

  template <typename T1>
  std::string Z_format(const char* file, int line, const std::string& fmt, const T1& arg1)
  {
    using namespace std;
    std::ofstream log("i18n.log");
    (log << "format (" << file << ":" << line << ")" << endl).flush();
    (log << "fmt = \"" << fmt << "\"" << endl).flush();
    (log << "arg1 = \"" << arg1 << "\"" << endl).flush();

    const int N = 1024;
    char buffer[N] = { 0 };
  #if defined(_MSC_VER)
    snprintf_s(buffer, N, _TRUNCATE, fmt.c_str(), arg1);
  #else
    snprintf(buffer, N, fmt.c_str(), arg1);
  #endif

    std::string result(buffer);
    (log << "result = \"" << result << "\"" << endl).flush();
    return result;
  }

  template <typename T1, typename T2>
  std::string Z_format(const char* file, int line, const std::string& fmt, const T1& arg1, const T2& arg2)
  {
    using namespace std;
    std::ofstream log("i18n.log");
    (log << "format (" << file << ":" << line << ")" << endl).flush();
    (log << "fmt = \"" << fmt << "\"" << endl).flush();
    (log << "arg1 = \"" << arg1 << "\"" << endl).flush();

    const int N = 1024;
    char buffer[N] = { 0 };
  #if defined(_MSC_VER)
    snprintf_s(buffer, N, _TRUNCATE, fmt.c_str(), arg1, arg2);
  #else
    snprintf(buffer, N, fmt.c_str(), arg1, arg2);
  #endif

    std::string result(buffer);
    (log << "result = \"" << result << "\"" << endl).flush();
    return result;
  }

  template <typename T1, typename T2, typename T3>
  std::string Z_format(const char* file, int line, const std::string& fmt, const T1& arg1, const T2& arg2, const T3& arg3)
  {
    using namespace std;
    std::ofstream log("i18n.log");
    (log << "format (" << file << ":" << line << ")" << endl).flush();
    (log << "fmt = \"" << fmt << "\"" << endl).flush();
    (log << "arg1 = \"" << arg1 << "\"" << endl).flush();

    const int N = 1024;
    char buffer[N] = { 0 };
  #if defined(_MSC_VER)
    snprintf_s(buffer, N, _TRUNCATE, fmt.c_str(), arg1, arg2, arg3);
  #else
    snprintf(buffer, N, fmt.c_str(), arg1, arg2, arg3);
  #endif

    std::string result(buffer);
    (log << "result = \"" << result << "\"" << endl).flush();
    return result;
  }

  template <typename T1, typename T2, typename T3, typename T4>
  std::string Z_format(const char* file, int line, const std::string& fmt, const T1& arg1, const T2& arg2, const T3& arg3, const T4& arg4)
  {
    using namespace std;
    std::ofstream log("i18n.log");
    (log << "format (" << file << ":" << line << ")" << endl).flush();
    (log << "fmt = \"" << fmt << "\"" << endl).flush();
    (log << "arg1 = \"" << arg1 << "\"" << endl).flush();

    const int N = 1024;
    char buffer[N] = { 0 };
  #if defined(_MSC_VER)
    snprintf_s(buffer, N, _TRUNCATE, fmt.c_str(), arg1, arg2, arg3, arg4);
  #else
    snprintf(buffer, N, fmt.c_str(), arg1, arg2, arg3, arg4);
  #endif

    std::string result(buffer);
    (log << "result = \"" << result << "\"" << endl).flush();
    return result;
  }
}

#endif//I18N_H

