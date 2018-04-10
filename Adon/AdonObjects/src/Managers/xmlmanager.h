#ifndef MEMORY_MANAGER_HEADER
#define MEMORY_MANAGER_HEADER

#include <adonobjects_exports.h>
#include "xml.h"

namespace Adon
{
  namespace AdonObjects
  {
    namespace Managers
    {
      class ADONOBJECTS_EXPORT XMLManager
      {
      public:
        void ParseFile(const std::string filename);
      private:
        std::vector<XML::Data> documents;
      };
    }
  }
}

#endif  //MEMORY_MANAGER_HEADER
