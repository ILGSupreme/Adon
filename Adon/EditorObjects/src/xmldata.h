#ifndef XMLDATA_HEADER
#define XMLDATA_HEADER

#include <editor_objects_exports.h>
#include <tinyxml2.h>
#include <string>

namespace Adon
{
  namespace EditorObjects
  {
    namespace XML
    {
      class EDITOR_OBJECTS_EXPORT XMLData
      {
      public:
        XMLData();
        ~XMLData();
        tinyxml2::XMLError LoadFile(std::string filename);
      private:
        tinyxml2::XMLDocument xmldocument;
      };
    }
  }
}

#endif //XMLData_HEADER
