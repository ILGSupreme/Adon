#ifndef XMLDATA_HEADER
#define XMLDATA_HEADER

#include <adonobjects_exports.h>
#include <tinyxml2.h>
#include <string>
#include <config.h>

typedef int32  containerId;

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
        protected:
          int32 GetDocID() {return this->document_id;}
          void SetDocID(int32 document_id) {this->document_id = document_id;}

          int32 document_id;
        };
      }
    }
  }
}

#endif //XMLData_HEADER
