#include "entity.h"

using namespace Adon::AdonObjects;

Adon::Application::Entity::Entity(
  const std::string objectID,int32 documentID,const XMLAttribute*& contattr,
  const XMLAttribute*& scriptattr,const XMLAttribute*& modelattr)
{
  Adon::AdonObjects::XML::Classes::Container(objectID,documentID,contattr,scriptattr,modelattr);
}

Adon::Application::Entity::~Entity()
{
}
