#ifndef ATOM_HEADER
#define ATOM_HEADER

#include <adonobjects_exports.h>
#include <mutex>

namespace Adon
{
  namespace AdonObjects
  {
    namespace Thread
    {
      static std::mutex thread_lock_variable;
    }
  }
}


#endif//ATOM_HEADER
