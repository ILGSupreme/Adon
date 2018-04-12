#ifndef DIRECTORY_HEADER
#define DIRECTORY_HEADER

#include <string>

namespace Adon
{
  namespace AdonObjects
  {
    namespace Filesystem
    {
      class Directory
      {
      public:
        Directory(const std::string dirname,const std::string path);
        const std::string GetPath();
        const std::string GetName();
      private:
        const std::string dirname;
        const std::string path;
      };
    }
  }
}

#endif//DIRECTORY_HEADER
