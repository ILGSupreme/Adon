#ifndef FILE_HEADER
#define FILE_HEADER

#include <string>
#include "filetype.h"

namespace Adon
{
  namespace AdonObjects
  {
    namespace Filesystem
    {
      class File
      {
      public:
        File(const std::string name,const std::string path);
        std::string GetPath();
        std::string GetName();
        std::string GetFullPath();
        bool operator==(Filetype);
      private:
        void GetFileType();
        std::string name;
        std::string path;
        Filetype type;
      };
    }
  }
}

#endif//FILE_HEADER
