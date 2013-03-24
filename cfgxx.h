#ifndef CFGXX_H
#define CFGXX_H

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>

namespace cfgxx
{
  template <typename T>
  static T config_value_cast(const std::string &str)
  {
    T value;
    std::istringstream ss(str);
    ss >> value;
    return value;
  }

  template <>
  std::string config_value_cast(const std::string &str)
  {
    return str;
  }

  template <>
  bool config_value_cast(const std::string &str)
  {
    std::string tmp;
    std::istringstream ss(str);
    ss >> tmp;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    return (tmp == "true") || (tmp == "yes") || (tmp == "on");
  }

  template <typename T>
  class config_value_iterator : public std::iterator<std::input_iterator_tag, T>
  {
  public:
    typedef std::vector<std::string> value_list;
    typedef value_list::size_type size_type;

    config_value_iterator() : index_(0) {}
    config_value_iterator(const value_list &values, size_type index = 0)
      : values_(values), index_(index) {}
    virtual ~config_value_iterator() {}

    T operator *() const { return config_value_cast<T>(values_[index_]); }

    config_value_iterator<T> &operator ++() { index_++; return *this; }
    config_value_iterator<T> &operator ++(int) { index_++; return *this; }

    bool operator ==(const config_value_iterator<T> &iter) const
      { bool result = values_ == iter.values_ && index_ == iter.index_; return result; }

    bool operator !=(const config_value_iterator<T> &iter) const { return !(*this == iter); } 
    size_type index() const { return index_; }

  protected:
    value_list values_;
    size_type index_;
  };

  /**
   * config class
   *
   * scalar = value (=> ["value"])
   * list1 = a, b, c (=> ["a", "b", "c"])
   * list2 = " quoted string ", unquoted_value (=> [" quoted string ", "unquoted_value"])
   * boolean_list = true, yes, on, hoge, false (=> [true, true, true, false, false])
   * integer_values = 0, 1, 2.5, "three" (=> [0, 1, 2, 0])
   *
   */
  class config
  {
  public:
    typedef std::vector<std::string> value_list;
    typedef std::map<std::string, value_list> value_map;

    config() {}
    config(const std::string &path) { import(path); }
    virtual ~config() {}

    void import(const std::string &path)
    {
      std::ifstream file(path.c_str());
      std::string line;

      while (std::getline(file, line))
      {
        std::string::size_type pos = line.find('=');

        if (pos == std::string::npos)
          continue;

        std::string key = line.substr(0, pos);
        trim(key);

        if (key.empty() || key[0] == '#')
          continue;

        std::string rest = line.substr(pos + 1);
        value_list values;
        std::string buffer;
        bool inquote = false;
        bool quoted = false;
        bool escaped = false;

        for (std::string::const_iterator it = rest.begin(); it != rest.end(); it++)
        {
          switch (*it) {
          case '\\':
            if (!escaped) {
              escaped = true;
              continue;
            }
            break;
          case '\"':
            if (!escaped && (inquote = !inquote))
              quoted = true;
            break;
          case ',':
            if (!inquote) {
              add_value(values, buffer, quoted);
              quoted = false;
              continue;
            }
            break;
          case ' ':
          case '\t':
            if (!inquote && buffer.empty())
              continue;
            break;
          default:
            break;
          }

          if (escaped)
            escaped = false;
          buffer += *it;
        }

        add_value(values, buffer, quoted);
        value_map::iterator it = values_.find(key);

        if (it != values_.end())
          values_.erase(it);
        values_.insert(std::make_pair(key, values));
      }
    }

    bool empty(const std::string &key) const
    {
      value_map::const_iterator it = values_.find(key);
      return it == values_.end();
    }

    value_list::size_type size(const std::string &key) const
    {
      value_map::const_iterator it = values_.find(key);
      return it != values_.end() ? it->second.size() : 0;
    }

    template <typename T>
    std::pair<config_value_iterator<T>, config_value_iterator<T> >
    range(const std::string &key) const
    {
      return std::make_pair(begin<T>(key), end<T>(key));
    }

    template <typename T>
    config_value_iterator<T> begin(const std::string &key) const
    {
      value_map::const_iterator it = values_.find(key);
      return it != values_.end()
        ? config_value_iterator<T>(it->second)
        : config_value_iterator<T>();
    }

    template <typename T>
    config_value_iterator<T> end(const std::string &key) const
    {
      value_map::const_iterator it = values_.find(key);
      return it != values_.end()
        ? config_value_iterator<T>(it->second, it->second.size())
        : config_value_iterator<T>();
    }

    template <typename T>
    T get_at(const std::string &key, value_list::size_type index,
        const T &default_value = T()) const
    {
      T value(default_value);
      value_map::const_iterator it = values_.find(key);
      if (it != values_.end() && 0 <= index && index < it->second.size())
        value = config_value_cast<T>(it->second.at(index));
      return value;
    }

    template <typename T>
    T get(const std::string &key, const T &default_value = T()) const
    {
      return get_at<T>(key, 0, default_value);
    }

  protected:
    value_map values_;

    std::string &trim(std::string &str, const std::string &pattern = " \t") const
    {
      str.erase(0, str.find_first_not_of(pattern));
      str.erase(str.find_last_not_of(pattern) + 1);
      return str;
    }

    void add_value(std::vector<std::string> &container, std::string &str, bool quoted)
    {
      trim(str);
      if (!str.empty()) {
        if (quoted)
          str = str.substr(1, str.length() - 2);
        container.push_back(str);
        str.clear();
      }
    }
  };
}

#endif//CFGXX_H

