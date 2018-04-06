#include "xml.h"
#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;
using namespace Adon::AdonObjects;
XMLError Adon::AdonObjects::XML::LoadXMLFile(const char* filename, Classes::XMLData& data)
{
	return data.LoadFile(filename);
}

XMLError Adon::AdonObjects::XML::LoadObjects(std::list<Classes::XMLObject>& objects,const XML::Classes::XMLData& data)
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
			objects.push_back(Classes::XMLObject(attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value()));
		}
	}
	return XML_SUCCESS;
}
