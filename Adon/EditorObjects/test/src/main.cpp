#include <xmlstaticfuncs.h>
#include <iostream>
#include <cstdio>

using namespace Adon::EditorObjects;

int main()
{
	std::list<GUIObject> objects;
	const char* filename = "xmltestfile.xml";
	Adon::EditorObjects::XML::XMLData data;
	int eerr = Adon::EditorObjects::XML::XMLStaticFuncs::LoadXMLFile(filename,data);
	int eerr2 = Adon::EditorObjects::XML::XMLStaticFuncs::LoadObjects(objects,data);
	printf("Loading XMLFILE is %d \n LOADING OBJECTS is %d \n", eerr, eerr2);

	for(const GUIObject& object : objects)
	{
		fprintf(stderr, "Value of Object : name %s script %s model %s\n", object.gui_id.c_str(),object.script_id.c_str(),object.model_id.c_str());
	}

	return 1;
}
