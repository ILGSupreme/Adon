#ifndef FILE_MANAGER_HEADER
#define FILE_MANAGER_HEADER

#include <adonobjects_exports.h>
#include <config.h>
#include <string>
#include <vector>
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
        void Init();
        void Update();
        void GetFolders(const std::string path);
        void GetFiles(const std::string path);
      protected:
        std::string filepath;
        std::vector<Directory> directories;
        std::vector<File> files;
      };
    }
  }
}

#endif //FILE_MANAGER_HEADER
