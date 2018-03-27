#include "xmlstaticfuncs.h"
#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;
XMLError Adon::EditorObjects::XML::XMLStaticFuncs::LoadObjectsFromFile(const char* filename, XMLData& data)
{
	return data.LoadFile(filename);
}
