#ifndef CONTAINER_HEADER
#define CONTAINER_HEADER

#include <adonobjects_exports.h>
#include <string>
#include "xmlobject.h"

using namespace tinyxml2;

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT  Container : protected XML::Classes::XMLObject
        {
        public:
          Container(){}
          Container(const std::string objectID,std::string document_id,
            const XMLAttribute*& contattr,const XMLAttribute*& scriptattr,
            const XMLAttribute*& modelattr);

          void ChangeContainerValue(std::string value);
          void ChangeScriptValue(std::string value);
          void ChangeModelValue(std::string value);

          std::string GetContainerValue();
          std::string GetScriptValue();
          std::string GetModelValue();

        private:
          const XMLAttribute* cont_attr_id;
          const XMLAttribute* script_attr_id;
          const XMLAttribute* model_attr_id;
        };
      }
    }
  }
}

#endif //CONTAINER_HEADER
