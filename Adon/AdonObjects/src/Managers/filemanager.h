#ifndef FILE_MANAGER_HEADER
#define FILE_MANAGER_HEADER

#include <adonobjects_exports.h>
#include <config.h>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include "directory.h"
#include "file.h"

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
        void GetAllFilesOfType(std::vector<std::shared_ptr<Adon::AdonObjects::Filesystem::File>>&,Adon::AdonObjects::Filesystem::Filetype);
        void GetNewFiles(std::vector<std::shared_ptr<Adon::AdonObjects::Filesystem::File>>&,Adon::AdonObjects::Filesystem::Filetype);
      protected:
        std::string filepath;
        std::shared_ptr<Adon::AdonObjects::Filesystem::Directory> directory;
        std::vector<std::shared_ptr<Adon::AdonObjects::Filesystem::File>> newfiles;
      };
    }
  }
}

#endif //FILE_MANAGER_HEADER
