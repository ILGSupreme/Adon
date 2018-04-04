#include <xmlstaticfuncs.h>
#include <iostream>
#include <cstdio>
#include <exception/exception.h>

using namespace Adon::EditorObjects;
using namespace Adon::Exception;

int main()
{
	std::list<GUIObject> objects;
	const char* filename = "xmltestfile.xml";
	Adon::EditorObjects::XML::XMLData data;
	Adon::Exception::checkFunctionCall<const char*,XML::XMLData&>(XML::XMLStaticFuncs::LoadXMLFile,filename,data);
	Adon::Exception::checkFunctionCall<std::list<GUIObject>&,const XML::XMLData&>(Adon::EditorObjects::XML::XMLStaticFuncs::LoadObjects,objects,data);
	for(const GUIObject& object : objects)
	{
		fprintf(stderr, "Value of Object : name %s script %s model %s\n", object.gui_id.c_str(),object.script_id.c_str(),object.model_id.c_str());
	}
	return 1;
}
