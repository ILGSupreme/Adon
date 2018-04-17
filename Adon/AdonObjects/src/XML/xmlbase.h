#ifndef XMLDATA_HEADER
#define XMLDATA_HEADER

#include <adonobjects_exports.h>
#include <tinyxml2.h>
#include <string>
#include <config.h>

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT XMLBase
        {
        public:
          std::string GetDocID() {return this->document_id;}
        protected:
          void SetDocID(std::string document_id) {this->document_id = std::string(document_id);}

          std::string document_id;
        };
      }
    }
  }
}

#endif //XMLData_HEADER
