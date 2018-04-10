#include <adonobjects/xml.h>
#include <adonobjects/container.h>
#include <adonobjects/model.h>
#include <adonobjects/script.h>
#include <adonobjects/xmlmanager.h>
#include <exception/exception.h>
#include <iostream>
#include <cstdio>

using namespace Adon::AdonObjects;
using namespace Adon::Exception;

int main()
{
	Managers::XMLManager manager;
	manager.ParseFile("xmltestfile.xml");
	//XML::Classes::Container test("test",2);
	//XML::Classes::Model	test2("dw",1);
	//XML::Classes::Script test3("sad",3);
	//ObjectManager manager;
	//std::list<XML::Classes::XMLObject> objects;
	//const char* filename = "xmltestfile.xml";
	//XML::Classes::XMLData data;
	//std::vector<std::string> v;
	//v.push_back(filename);
	//manager.LoadXMLFiles(v);
	//manager.ParseAllXMLData();
	//checkFunctionCall<const char*,XML::Classes::XMLData&>(XML::LoadXMLFile,filename,data);
	//checkFunctionCall<std::list<XML::Classes::XMLObject>&,const XML::Classes::XMLData&>(Adon::AdonObjects::XML::LoadObjectsL,objects,data);
	//for(const XML::Classes::XMLObject& object : objects)
	//{
	//	fprintf(stderr, "Value of Object : name %s script %s model %s\n", object.gui_id.c_str(),object.script_id.c_str(),object.model_id.c_str());
	//}
	return 1;
}
