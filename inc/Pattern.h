#pragma once

#include <vector>
#include <string>
#include <set>

namespace Composition
{

class Pattern
{
  private:
    std::multiset<std::pair<float, Pattern&>> subpatterns;
    virtual void flattenPatternInto(std::multiset<std::pair<float, std::string>> &container, float start);

  public:
    std::vector<std::pair<float, std::string>> serialize();
    virtual float getLength() const;

    void add(Pattern &, float start);
    bool remove(Pattern &, float start);

    int operator<(Pattern & other){
        return (subpatterns.begin())->first<(other.subpatterns.begin())->first;
    }
};

//! \todo TODO: give note more despcripting power (pitch, transition, oscillation, etc.)
// maybe merge Instrument::iNote nad this?

class Note : public Pattern
{
  private:
    std::string name;
    float length = 0;

    void flattenPatternInto(std::multiset<std::pair<float, std::string>> &container, float start);

  public:
    float getLength() const { return length; }
    std::string getName() const { return name; }

    Note(std::string name) : name(name) {}
    Note(std::string name, float length) : name(name), length(length) {}
};
}