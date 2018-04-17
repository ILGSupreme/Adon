#ifndef XML_HEADER
#define XML_HEADER

#include <adonobjects_exports.h>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include "xmlbase.h"
#include "xmlobject.h"

namespace Adon
{
	namespace AdonObjects
	{
		namespace XML
		{
			class Data
			{
			public:
				Data(){}
				Data(const Data& dat){}
				XMLDocument xmldoc;
				std::string unique_id;
			};
		}
	}
}

#endif //XML_HEADER
