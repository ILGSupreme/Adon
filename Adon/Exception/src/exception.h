#ifndef FAULT_HEADER
#define FAULT_HEADER

#include <exception>
#include <cstdio>
#include <functional>
#include <type_traits>

namespace Adon
{
  namespace Exception
  {
    template <typename A,typename B>
    void checkFunctionCall(const std::function<int(A,B)>& func,A& arga, B& argb)
    {
      try
      {
        func(arga,argb);
      }
      catch(std::exception e)
      {
        std::printf("%s\n", e.what());
      }
    }
  }
}

#endif //FAULT_HANDLER_HEADER
