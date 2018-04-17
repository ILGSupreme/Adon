#ifndef MODEL_HEADER
#define MODEL_HEADER

#include <adonobjects_exports.h>
#include <string>
#include "xmlobject.h"

using namespace tinyxml2;

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT  Model : private XML::Classes::XMLObject
        {
        public:
          Model(const std::string objectID,std::string documentID);
        };
      }
    }
  }
}

#endif ///MODEL_HEADER
