#ifndef XML_READER_HEADER
#define XML_READER_HEADER

#include <adonobjects_exports.h>
#include <xmldata.h>
#include <xmlobject.h>
#include <list>

namespace Adon
{
	namespace AdonObjects
	{
		namespace XML
		{
				ADONOBJECTS_EXPORT tinyxml2::XMLError LoadXMLFile (const char* filename, Classes::XMLData& data);
				ADONOBJECTS_EXPORT tinyxml2::XMLError LoadObjects(std::list<Classes::XMLObject>& objects,	const Classes::XMLData& data);
		}
	}
}

#endif //XML_READER_HEADER
