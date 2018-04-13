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
        const std::vector<Directory>& GetDirectories();
        std::vector<File>& GetFiles();
        std::string GetFullPath();

        bool Exists();
        bool operator==(std::string other);

        void LoadFolders(const std::string path);
        void LoadFiles(const std::string path);
        void Update();
        bool HaveDir(std::string path);
        bool IsDirDot(const std::string& path);
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
