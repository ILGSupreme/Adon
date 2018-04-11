#ifndef ENTITY_HEADER
#define ENTITY_HEADER

#include <adonobjects/container.h>

namespace Adon
{
  namespace Application
  {
    class Entity : public AdonObjects::XML::Classes::Container
    {
    public:
      Entity(const std::string objectID,int32 documentID,
        const XMLAttribute*& contattr,const XMLAttribute*& scriptattr,
        const XMLAttribute*& modelattr);
      ~Entity();
    private:
    };
  }
}

#endif///ENTITY_HEADER
