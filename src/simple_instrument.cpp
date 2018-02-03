#include <Instrument.h>

template <typename T>
std::vector<T> Instrument::Simple<T>::play(std::vector<std::pair<float, std::string>>) {
    //! \todo TODO: the important stuff
}

template <typename T>
void Instrument::Simple<T>::add(iNote<T> &note, std::string name)
{
    noteset.insert(std::make_pair(name, std::ref(note)));
}

template <typename T>
std::vector<std::pair<std::string, std::reference_wrapper<Instrument::iNote<T>>>> Instrument::Simple<T>::getNoteset()
{
    return std::vector<std::pair<std::string, std::reference_wrapper<Instrument::iNote<T>>>>(noteset.begin(),noteset.end());
}

template class Instrument::Simple<float>;