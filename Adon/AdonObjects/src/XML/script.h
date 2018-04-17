#ifndef SCRIPT_HEADER
#define SCRIPT_HEADER

#include <adonobjects_exports.h>
#include <string>
#include "xmlobject.h"

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT  Script : private XML::Classes::XMLObject
        {
        public:
          Script(const std::string objectID,std::string documentID);
        };
      }
    }
  }
}

#endif //SCRIPT_HEADER
