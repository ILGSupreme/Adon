#include "container.h"

using namespace Adon::AdonObjects::XML::Classes;

Container::Container()
{

}

Container::Container(std::string cont_id,std::string script_id,std::string model_id) : cont_attr_id(cont_id),script_attr_id(script_id),model_attr_id(model_id)
{
  
}

void Container::ChangeContainerValue(std::string value)
{
}

void Container::ChangeScriptValue(std::string value)
{
}

void Container::ChangeModelValue(std::string value)
{
}

std::string Container::GetContainerValue()
{
}

std::string Container::GetScriptValue()
{
}

std::string Container::GetModelValue()
{
}
