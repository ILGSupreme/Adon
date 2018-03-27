#ifndef GUI_OBJECT_HEADER
#define GUI_OBJECT_HEADER

#include <editor_objects_exports.h>
#include <string>

namespace Adon
{
  namespace EntityManager
  {
    class EDITOR_OBJECTS_EXPORT GUIObject
    {
      GUIObject();
      ~GUIObject();
      std::string id;
      //Model
      //Script
    };
  }
}


#endif //GUI_OBJECT_HEADER
