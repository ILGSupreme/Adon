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
        class ADONOBJECTS_EXPORT  Container : private XML::Classes::XMLObject
        {
        public:
          Container(const std::string objectID,int32 documentID,
            XMLAttribute* contattr,XMLAttribute* scriptattr,
            XMLAttribute* modelattr);

          void ChangeContainerValue(std::string value);
          void ChangeScriptValue(std::string value);
          void ChangeModelValue(std::string value);

          std::string GetContainerValue();
          std::string GetScriptValue();
          std::string GetModelValue();

        private:
          XMLAttribute* cont_attr_id;
          XMLAttribute* script_attr_id;
          XMLAttribute* model_attr_id;
        };
      }
    }
  }
}

#endif //CONTAINER_HEADER
