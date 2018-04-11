#ifndef MEMORY_MANAGER_HEADER
#define MEMORY_MANAGER_HEADER

#include <adonobjects_exports.h>
#include <tinyxml2.h>
#include <memory>
#include <map>
#include "container.h"
#include "model.h"
#include "script.h"
#include "xml.h"

using namespace tinyxml2;
using namespace Adon::AdonObjects;

typedef std::vector<std::unique_ptr<XML::Classes::Container>> Container_Vector;
typedef std::vector<std::unique_ptr<XML::Classes::Model>> Model_Vector;
typedef std::vector<std::unique_ptr<XML::Classes::Script>> Script_Vector;

namespace Adon
{
  namespace AdonObjects
  {
    namespace Managers
    {
      class ADONOBJECTS_EXPORT XMLManager
      {
      public:
        XMLError ParseFile(const std::string filename);
        virtual XMLError ParseDoc(const XML::Data& data);
        virtual XMLError ParseAllDocs() {}
        std::vector<XML::Data> documents;
        std::map<int,Container_Vector> containers;
        std::map<int,Model_Vector> models;
        std::map<int,Script_Vector> scripts;
      };
    }
  }
}

#endif  //MEMORY_MANAGER_HEADER
