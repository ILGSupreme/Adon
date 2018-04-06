#include "xmlobject.h"

using namespace Adon::AdonObjects;

ADONOBJECTS_EXPORT XML::Classes::XMLObject::XMLObject()
{
  //empty
}

ADONOBJECTS_EXPORT XML::Classes::XMLObject::XMLObject(const char* gui_id,
  const char* script_id,
  const char* model_id)
{
  this->gui_id = std::string(gui_id);
  this->script_id = std::string(script_id);
  this->model_id = std::string(model_id);
}

ADONOBJECTS_EXPORT XML::Classes::XMLObject::~XMLObject()
{
  //empty
}
