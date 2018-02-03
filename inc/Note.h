#pragma once

#include <iNote.h>
#include <RepeatingBuffer.h>

namespace Instrument
{
namespace Note
{
template <typename T>
class Baked : public iNote<T>
{
  private:
    DataFlow::RepeatingBuffer<T> buffer;
    //! \todo TODO
};
};
};