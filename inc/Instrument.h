#pragma once

#include <map>
#include <string>
#include <functional>
#include <vector>

#include <iNote.h>

namespace Instrument
{
template <typename T>
class Simple
{
  private:
    std::map<std::string,iNote<T>&> noteset;

  public:
    std::vector<T> play(std::vector<std::pair<float, std::string>>);

    void add(Instrument::iNote<T> &note, std::string name);
    bool remove(std::string name) { noteset.erase(name); }
    std::vector<std::pair<std::string,std::reference_wrapper<iNote<T>>>> getNoteset();
};
};