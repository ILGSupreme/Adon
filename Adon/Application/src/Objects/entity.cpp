#include "entity.h"

using namespace Adon::AdonObjects;

Adon::Application::Entity::Entity(
  const std::string objectID,std::string documentId,const XMLAttribute*& contattr,
  const XMLAttribute*& scriptattr,const XMLAttribute*& modelattr) : Container(objectID,documentId,contattr,scriptattr,modelattr)
{
  fprintf(stderr, "Entity created with id %s\n", document_id.c_str());
}

Adon::Application::Entity::~Entity()
{
}
