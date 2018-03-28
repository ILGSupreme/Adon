#ifndef XML_READER_HEADER
#define XML_READER_HEADER

#include <editor_objects_exports.h>
#include <xmldata.h>
#include <guiobject.h>
#include <list>

namespace Adon
{
	namespace EditorObjects
	{
		namespace XML
		{
			namespace XMLStaticFuncs
			{
				EDITOR_OBJECTS_EXPORT tinyxml2::XMLError LoadXMLFile (const char* filename, XMLData& data);
				EDITOR_OBJECTS_EXPORT tinyxml2::XMLError LoadObjects(std::list<GUIObject>& objects,	const XMLData& data);
			}
		}
	}
}

#endif //XML_READER_HEADER
