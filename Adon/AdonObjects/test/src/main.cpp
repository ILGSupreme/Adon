#include <adonobjects/xml.h>
#include <iostream>
#include <cstdio>
#include <exception/exception.h>

using namespace Adon::AdonObjects;
using namespace Adon::Exception;

int main()
{
	std::list<XML::Classes::XMLObject> objects;
	const char* filename = "xmltestfile.xml";
	XML::Classes::XMLData data;
	checkFunctionCall<const char*,XML::Classes::XMLData&>(XML::LoadXMLFile,filename,data);
	checkFunctionCall<std::list<XML::Classes::XMLObject>&,const XML::Classes::XMLData&>(Adon::AdonObjects::XML::LoadObjects,objects,data);
	for(const XML::Classes::XMLObject& object : objects)
	{
		fprintf(stderr, "Value of Object : name %s script %s model %s\n", object.gui_id.c_str(),object.script_id.c_str(),object.model_id.c_str());
	}
	return 1;
}
