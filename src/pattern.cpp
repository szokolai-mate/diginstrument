#include <Pattern.h>
#include <functional>
void Composition::Pattern::flattenPatternInto(std::multiset<std::pair<float, std::string>> &container, float position = 0)
{
    for (std::pair<float,Pattern&> a : subpatterns)
    {
        a.second.flattenPatternInto(container, a.first + position);
    }
}

void Composition::Note::flattenPatternInto(std::multiset<std::pair<float, std::string>> &container, float position)
{
    container.insert(std::make_pair(position, getName()));
}

std::vector<std::pair<float, std::string>> Composition::Pattern::serialize()
{
    std::multiset<std::pair<float, std::string>> container;
    flattenPatternInto(container);
    return std::vector<std::pair<float, std::string>>(container.begin(), container.end());
}

float Composition::Pattern::getLength() const
{
    float res = 0;
    for(auto a : subpatterns){
        float currentLength = a.second.getLength() + a.first;
        if(currentLength > res){
            res = currentLength;
        }
    }
    return res;
}

void Composition::Pattern::add(Pattern &pattern, float start)
{
    subpatterns.insert(std::make_pair(start,std::ref(pattern)));
}

bool Composition::Pattern::remove(Pattern &pattern, float start)
{
    auto itr = subpatterns.find(std::make_pair(start,std::ref(pattern)));
    if (itr != subpatterns.end())
    {
        subpatterns.erase(itr);
        return true;
    }
    return false;
}
