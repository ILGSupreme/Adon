#include "xmlstaticfuncs.h"
#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;
XMLError Adon::EditorObjects::XML::XMLStaticFuncs::LoadXMLFile(const char* filename, XMLData& data)
{
	return data.LoadFile(filename);
}

XMLError Adon::EditorObjects::XML::XMLStaticFuncs::LoadObjects(std::list<GUIObject>& objects,const XMLData& data)
{
	const XMLElement* root = data.XMLDocument().FirstChildElement("GUIObjects");
	if(root!=nullptr)
	{
		for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement()) {
			/* code */
			const XMLAttribute* attr_gui_id = node->FirstAttribute();
			const XMLAttribute* attr_script_id = node->FirstChildElement()->FirstAttribute();
			const XMLAttribute* attr_model_id = node->FirstChildElement()->NextSiblingElement()->FirstAttribute();
			//fprintf(stderr, "%s\n", attr->Value());
			objects.push_back(GUIObject(attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value()));
		}
	}
	return XML_SUCCESS;
}
