#ifndef ENTITY_MANAGER_HEADER
#define ENTITY_MANAGER_HEADER

#include <adonobjects/xmlmanager.h>
#include <adonobjects/filemanager.h>

using namespace Adon::AdonObjects;

namespace Adon
{
  namespace Application
  {
    class EntityManager : public Managers::XMLManager,public Managers::Filemanager
    {
    public:
      EntityManager();
      ~EntityManager();
      void Init();
    private:
      XMLError ParseAllDocs();
      XMLError ParseDoc(const XML::Data&);
    };
  }
}

#endif ///ENTITY_MANAGER_HEADER
