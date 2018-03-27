#ifndef XML_READER_HEADER
#define XML_READER_HEADER

#include <editor_objects_exports.h>
#include <xmldata.h>

namespace Adon
{
	namespace EditorObjects
	{
		namespace XML
		{
			namespace XMLStaticFuncs
			{
				EDITOR_OBJECTS_EXPORT tinyxml2::XMLError LoadObjectsFromFile (const char* filename, XMLData& data);
			}
		}
	}
}

#endif //XML_READER_HEADER
