#ifndef ENTITY_MANAGER_HEADER
#define ENTITY_MANAGER_HEADER

#include <adonobjects/xmlmanager.h>
#include <adonobjects/filemanager.h>
#include <thread>

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
      void Run();
      void Stop();
    private:
      void Update();
      bool HaveDir(std::string path);
      bool IsDirDot(const std::string& path);
      XMLError ParseAllDocs();
      XMLError ParseDoc(const XML::Data&);
      std::thread t1;
      bool run_thread;
    };
  }
}

#endif ///ENTITY_MANAGER_HEADER
