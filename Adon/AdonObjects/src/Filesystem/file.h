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
        std::string GetUniqueID();
        void SetParsed(bool);
        bool isParsed();
        bool operator==(Filetype);
        bool operator==(std::string value);
      private:
        void GetFileType();
        std::string name;
        std::string path;
        std::string unique_id;
        Filetype type;
        bool parsed;
      };
    }
  }
}

#endif//FILE_HEADER
