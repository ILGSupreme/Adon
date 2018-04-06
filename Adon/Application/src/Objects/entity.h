#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <adonobjects/xmlobject.h>

namespace Adon
{
  namespace Application
  {
    class Entity : public AdonObjects::XML::Classes::XMLObject
    {
    public:
      Entity();
      ~Entity();
    private:
    };
  }
}

#endif///ENTITY_HEADER
