#ifndef GUI_OBJECT_HEADER
#define GUI_OBJECT_HEADER

#include <editor_objects_exports.h>
#include <string>

namespace Adon
{
  namespace EditorObjects
  {
    class EDITOR_OBJECTS_EXPORT GUIObject
    {
    public:
      GUIObject();
      GUIObject(const char*,const char*,const char*);
      ~GUIObject();
      std::string gui_id;
      std::string script_id;
      std::string model_id;
      //Model
      //Script
    };
  }
}


#endif //GUI_OBJECT_HEADER
