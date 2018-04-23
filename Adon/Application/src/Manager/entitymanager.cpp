#include "entitymanager.h"
#include "entity.h"
#include <mutex>
#include <adonobjects/atom.h>
#include <adonobjects/file.h>
#include <chrono>

using namespace Adon::Application;
using namespace Adon::AdonObjects;
using namespace tinyxml2;

EntityManager::EntityManager()
{
  run_thread = true;
}

EntityManager::~EntityManager()
{
  //empty code
  if(t1.joinable())
  {
    t1.join();
  }
  if(t2.joinable())
  {
    t2.join();
  }
}

void EntityManager::Init()
{
}

void EntityManager::Run()
{
    t1 = std::thread(&EntityManager::SearchDirectoriesUpdate_Thread,this);
    t2 = std::thread(&EntityManager::ParseUpdate_Thread,this);
}

void EntityManager::Stop()
{
  run_thread = false;
}

void EntityManager::UpdateEntitiesThread()
{
  for(auto& _value : container_map)
  {
    auto inList = false;
    std::pair<std::string,std::shared_ptr<cont_pair>> map_set = _value;
    std::shared_ptr<cont_pair> cont = map_set.second;
    std::map<std::string,entity_set>::iterator it = entities.find(_value.first);
    if(it!=entities.end())
    {
      for(auto& entity_ptr : (*it).second)
      {
        if(cont.get()->second.unique_guid.compare(entity_ptr.first)==0)
        {
          inList = true;
        }
      }
      if(!inList) {
        entities.insert(std::pair<std::string,entity_set>(_value.first,entity_set()));
        entities[_value.first][cont.get()->second.unique_guid] = std::make_shared<Entity>(cont.get()->second.attr_cont_id,cont.get()->second.attr_script_id,cont.get()->second.attr_model_id,cont.get()->second.unique_guid);
      }
    }
    else {
      entities.insert(std::pair<std::string,entity_set>(_value.first,entity_set()));
      entities[_value.first][cont.get()->second.unique_guid] = std::make_shared<Entity>(cont.get()->second.attr_cont_id,cont.get()->second.attr_script_id,cont.get()->second.attr_model_id,cont.get()->second.unique_guid);
    }
  }
}

void EntityManager::SearchDirectoriesUpdate_Thread()
{
  while(run_thread)
  {
    Adon::AdonObjects::Thread::thread_lock_variable.lock();
    directory.get()->Update();
    Adon::AdonObjects::Managers::Filemanager::GetNewFiles(newfiles,Filesystem::Filetype::XML);
    Adon::AdonObjects::Thread::thread_lock_variable.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}

void EntityManager::ParseUpdate_Thread()
{
  while (run_thread)
  {
    Adon::AdonObjects::Thread::thread_lock_variable.lock();
    ParseAllFiles(newfiles);
    Adon::AdonObjects::Thread::thread_lock_variable.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(3));
  }
}
