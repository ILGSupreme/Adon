#ifndef DIRECTORY_HEADER
#define DIRECTORY_HEADER

#include <string>
#include <vector>
#include "file.h"

namespace Adon
{
  namespace AdonObjects
  {
    namespace Filesystem
    {
      class Directory
      {
      public:
        Directory(const std::string name,const std::string path);
        const std::string GetPath();
        const std::string GetName();
        std::string GetFullPath();
        void LoadFolders(const std::string path);
        void LoadFiles(const std::string path);

        std::vector<File>& GetFiles();
        const std::vector<Directory>& GetDirectories();

        static void GetAllFilesOfType(Filetype,Directory,std::vector<File>&);
      private:
        const std::string name;
        const std::string path;
        std::vector<Directory> directories;
        std::vector<File> files;
      };
    }
  }
}

#endif//DIRECTORY_HEADER
