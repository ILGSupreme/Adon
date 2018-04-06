#include "objectmanager.h"

using namespace Adon::AdonObjects::XML;

void Adon::AdonObjects::ObjectManager::LoadXMLFiles(const std::vector<std::string>& files)
{
  for (auto& file : files) {
    xmldata_vector.push_back(std::pair<int,Classes::XMLData>(++instanceId,Classes::XMLData()));
  }
}
