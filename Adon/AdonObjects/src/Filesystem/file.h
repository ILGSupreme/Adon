#ifndef FILE_HEADER
#define FILE_HEADER

#include <string>

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
      private:
        std::string name;
        std::string path;
      };
    }
  }
}

#endif//FILE_HEADER
