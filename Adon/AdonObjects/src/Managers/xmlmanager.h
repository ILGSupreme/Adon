#ifndef MEMORY_MANAGER_HEADER
#define MEMORY_MANAGER_HEADER

#include <adonobjects_exports.h>
#include <tinyxml2.h>
#include <memory>
#include <map>
#include <vector>
#include "file.h"
#include "xml.h"

typedef std::pair<std::string,Adon::AdonObjects::XML::Container> cont_pair;

namespace Adon
{
  namespace AdonObjects
  {
    namespace Managers
    {
      class ADONOBJECTS_EXPORT XMLManager
      {
      public:
        void ParseAllFiles(std::vector<std::shared_ptr<Filesystem::File>>&);
      protected:
        std::map<std::string,std::shared_ptr<cont_pair>> container_map;
        tinyxml2::XMLError ParseFile(const std::string filename,const std::string unique_id);
      };
    }
  }
}

#endif  //MEMORY_MANAGER_HEADER
