#ifndef XML_HEADER
#define XML_HEADER

#include <adonobjects_exports.h>
#include <list>
#include <vector>
#include <string>
#include <memory>

namespace Adon
{
	namespace AdonObjects
	{
		namespace XML
		{
			struct Container {
				std::string attr_cont_id;
				std::string attr_script_id;
				std::string attr_model_id;
				std::string unique_id;
				std::string unique_guid;
			};
		}
	}
}

#endif //XML_HEADER
