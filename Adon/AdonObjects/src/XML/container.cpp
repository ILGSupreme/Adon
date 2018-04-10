#include "container.h"

using namespace Adon::AdonObjects::XML::Classes;

Container::Container(const std::string objectID,int32 documentID,
  XMLAttribute* contattr,XMLAttribute* scriptattr,
  XMLAttribute* modelattr) : cont_attr_id(contattr),script_attr_id(scriptattr),model_attr_id(modelattr)
{
  XMLBase::SetDocID(documentID);
  XMLObject::SetObjectID(objectID);
}

void Container::ChangeContainerValue(std::string value)
{
  XMLObject::ChangeAttrValueString(cont_attr_id,value);
}

void Container::ChangeScriptValue(std::string value)
{
  XMLObject::ChangeAttrValueString(script_attr_id,value);
}

void Container::ChangeModelValue(std::string value)
{
  XMLObject::ChangeAttrValueString(model_attr_id,value);
}
