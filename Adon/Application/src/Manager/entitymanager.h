#ifndef ENTITY_MANAGER_HEADER
#define ENTITY_MANAGER_HEADER

#include <adonobjects/xmlmanager.h>

using namespace Adon::AdonObjects;

namespace Adon
{
  namespace Application
  {
    class EntityManager : public Managers::XMLManager
    {
    public:
      void Init();
    private:
      XMLError ParseAllDocs();
      XMLError ParseDoc(const XML::Data&);
    };
  }
}

#endif ///ENTITY_MANAGER_HEADER
