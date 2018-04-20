#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <adonobjects/container.h>

namespace Adon
{
  namespace Application
  {
    class Entity : public Adon::AdonObjects::XML::Classes::Container
    {
    public:
      Entity(std::string,std::string,std::string);
      ~Entity();
    private:
    };
  }
}

#endif///ENTITY_HEADER
