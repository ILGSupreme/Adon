#ifndef GUI_OBJECT_HEADER
#define GUI_OBJECT_HEADER

#include <adonobjects_exports.h>
#include "xmlbase.h"
#include <string>
#include <memory>

using namespace std;
using namespace tinyxml2;

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT XMLObject : public XMLBase
        {
        protected:
          void ChangeAttrValueInt(XMLAttribute* attr, int32 value) {attr->SetAttribute(value);}
          void ChangeAttrValueString(XMLAttribute* attr, std::string value) {attr->SetAttribute(value.c_str());}

          std::string GetObjectID() {return object_id;}
          void        SetObjectID(std::string object_id) {this->object_id = object_id;}

          std::string object_id;
        };
      }
    }
  }
}


#endif //GUI_OBJECT_HEADER
