#ifndef ENTITY_MANAGER_HEADER
#define ENTITY_MANAGER_HEADER

#include <adonobjects/xmlmanager.h>
#include <adonobjects/filemanager.h>
#include <thread>
#include <atomic>
#include <memory>
#include "entity.h"

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
      void UpdateEntitiesThread();
    private:
      void SearhDirectoriesUpdate_Thread();
      void ParseUpdate_Thread();
      std::thread t1;
      std::thread t2;
      std::atomic<bool> run_thread;
      std::vector<std::shared_ptr<Entity>> entities;
    };
  }
}

#endif ///ENTITY_MANAGER_HEADER
