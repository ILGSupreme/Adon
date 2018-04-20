#include "entity.h"

using namespace Adon::AdonObjects;

Adon::Application::Entity::Entity(std::string cont_id,std::string script_id,std::string model_id) : Container(cont_id,script_id,model_id)
{
  fprintf(stderr, "Entity created with id %s\n", cont_attr_id.c_str());
}

Adon::Application::Entity::~Entity()
{
}
