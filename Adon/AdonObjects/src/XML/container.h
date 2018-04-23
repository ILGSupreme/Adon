#ifndef CONTAINER_HEADER
#define CONTAINER_HEADER

#include <adonobjects_exports.h>
#include <string>

namespace Adon
{
  namespace AdonObjects
  {
    namespace XML
    {
      namespace Classes
      {
        class ADONOBJECTS_EXPORT  Container
        {
        public:
          Container();
          Container(std::string cont_id,std::string script_id,std::string model_id,std::string unique_guid);

          void ChangeContainerValue(std::string value);
          void ChangeScriptValue(std::string value);
          void ChangeModelValue(std::string value);

          std::string GetContainerValue();
          std::string GetScriptValue();
          std::string GetModelValue();
          std::string GetUniqueGUID();

        protected:
          std::string cont_attr_id;
          std::string script_attr_id;
          std::string model_attr_id;
          std::string unique_guid;
        };
      }
    }
  }
}

#endif //CONTAINER_HEADER
