#ifndef FILE_MANAGER_HEADER
#define FILE_MANAGER_HEADER

#include <adonobjects_exports.h>
#include <config.h>
#include <string>
#include <vector>
#include <memory>
#include "directory.h"
#include "file.h"

using namespace Adon::AdonObjects::Filesystem;

namespace Adon
{
  namespace AdonObjects
  {
    namespace Managers
    {
      class ADONOBJECTS_EXPORT Filemanager
      {
      public:
        Filemanager();
        void GetAllFilesOfType(std::vector<File>&,Filetype);
      protected:
        std::string filepath;
        std::unique_ptr<Directory> directory;
      };
    }
  }
}

#endif //FILE_MANAGER_HEADER
