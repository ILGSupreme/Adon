#include "container.h"

using namespace Adon::AdonObjects::XML::Classes;

Container::Container()
{

}

Container::Container(std::string cont_id,std::string script_id,std::string model_id,std::string _unique_guid) :
cont_attr_id(cont_id),
script_attr_id(script_id),
model_attr_id(model_id),
unique_guid(_unique_guid)
{

}

void Container::ChangeContainerValue(std::string value)
{
  cont_attr_id = value;
}

void Container::ChangeScriptValue(std::string value)
{
  script_attr_id = value;
}

void Container::ChangeModelValue(std::string value)
{
  model_attr_id = value;
}

std::string Container::GetContainerValue()
{
  return cont_attr_id;
}

std::string Container::GetScriptValue()
{
  return script_attr_id;
}

std::string Container::GetModelValue()
{
  return model_attr_id;
}

std::string Container::GetUniqueGUID()
{
  return unique_guid;
}
