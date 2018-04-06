#ifndef GUI_OBJECT_HEADER
#define GUI_OBJECT_HEADER

#include <adonobjects_exports.h>
#include <string>

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT XMLObject
        {
        public:
          XMLObject();
          XMLObject(const char*,const char*,const char*);
          ~XMLObject();
          std::string gui_id;
          std::string script_id;
          std::string model_id;
        };
      }
    }
  }
}


#endif //GUI_OBJECT_HEADER
