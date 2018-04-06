#ifndef XMLDATA_HEADER
#define XMLDATA_HEADER

#include <adonobjects_exports.h>
#include <tinyxml2.h>
#include <string>

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT XMLData
        {
        public:
          XMLData();
          XMLData(const XMLData&);
          ~XMLData();
          tinyxml2::XMLError LoadFile(std::string filename);
          const tinyxml2::XMLDocument& XMLDocument() const;
        private:
          std::string filename;
          tinyxml2::XMLDocument xmldocument;
        };
      }
    }
  }
}

#endif //XMLData_HEADER
