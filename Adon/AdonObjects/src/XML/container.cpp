#include "container.h"

using namespace Adon::AdonObjects::XML::Classes;

Container::Container(const std::string objectID,std::string documentId,
  const XMLAttribute*& contattr,const XMLAttribute*& scriptattr,
  const XMLAttribute*& modelattr) : cont_attr_id(contattr),script_attr_id(scriptattr),model_attr_id(modelattr)
{
  XMLBase::SetDocID(documentId);
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

std::string Container::GetContainerValue()
{
  return std::string(cont_attr_id->Value());
}

std::string Container::GetScriptValue()
{
  return std::string(script_attr_id->Value());
}

std::string Container::GetModelValue()
{
  return std::string(model_attr_id->Value());
}
