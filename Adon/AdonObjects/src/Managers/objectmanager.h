#ifndef ENTITY_MANAGER_HEADER
#define ENTITY_MANAGER_HEADER

#include <adonobjects_exports.h>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <xmldata.h>
#include <xmlobject.h>
#include <xml.h>

using namespace Adon::AdonObjects::XML;

namespace Adon
{
  namespace AdonObjects
  {
    class ADONOBJECTS_EXPORT ObjectManager
    {
    public:
      void LoadXMLFiles(const std::vector<std::string>& files);
    private:
      std::map<int,std::vector<Classes::XMLObject>> data;
      std::vector<std::pair<int,Classes::XMLData>> xmldata_vector;
      //needs to change
      int instanceId = 0;
    };
  }
}


#endif //ENTITY_MANAGER_HEADER
