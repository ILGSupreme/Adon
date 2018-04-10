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
				int32 id;
			};
				//ADONOBJECTS_EXPORT tinyxml2::XMLError LoadXMLFile (std::string filename, std::shared_ptr<Classes::XMLData>& data);
				//ADONOBJECTS_EXPORT tinyxml2::XMLError LoadObjectsV(std::vector<Classes::XMLObject>& objects,	const Classes::XMLData& data);
		}
	}
}

#endif //XML_HEADER
