#ifndef DIRECTORY_HEADER
#define DIRECTORY_HEADER

#include <string>
#include <vector>
#include <memory>
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
        Directory(const std::string name,const std::string path, bool deepSearch=true);
        const std::string GetPath();
        const std::string GetName();
        std::vector<std::shared_ptr<Directory>>& GetDirectories();
        std::vector<std::shared_ptr<File>>& GetFiles();
        std::string GetFullPath();

        bool Exists();
        bool operator==(std::string other);

        void LoadFolders(const std::string path,bool deepSearch=true);
        void LoadFiles(const std::string path);
        void Update();
        bool HaveDir(std::string path);
        bool HaveFile(std::string path);
        bool IsDirDot(const std::string& path);
        static void GetAllFilesOfType(Filetype,std::shared_ptr<Directory>&,std::vector<std::shared_ptr<File>>&);
        static void GetNewFiles(Filetype,std::shared_ptr<Directory>&,std::vector<std::shared_ptr<File>>&);
      private:
        void SortFiles();
        const std::string name;
        const std::string path;
        std::vector<std::shared_ptr<Directory>> directories;
        std::vector<std::shared_ptr<File>> files;
      };
    }
  }
}

#endif//DIRECTORY_HEADER
