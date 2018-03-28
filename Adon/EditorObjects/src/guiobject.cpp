#include "guiobject.h"

EDITOR_OBJECTS_EXPORT Adon::EditorObjects::GUIObject::GUIObject()
{
  //empty
}

EDITOR_OBJECTS_EXPORT Adon::EditorObjects::GUIObject::GUIObject(const char* gui_id,const char* script_id,const char* model_id)
{
  this->gui_id = std::string(gui_id);
  this->script_id = std::string(script_id);
  this->model_id = std::string(model_id);
}

EDITOR_OBJECTS_EXPORT Adon::EditorObjects::GUIObject::~GUIObject()
{
  //empty
}
