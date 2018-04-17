#include "xmlmanager.h"

using namespace Adon::AdonObjects::Managers;
using namespace tinyxml2;
using namespace Adon::AdonObjects::XML;

XMLError XMLManager::ParseFile(const std::string filename,const std::string unique_id)
{
  unique_ptr<Data> ptr = std::make_unique<Data>();
  documents.push_back(std::move(ptr));
  XMLError error = documents.back().get()->xmldoc.LoadFile(filename.c_str());
  documents.back().get()->unique_id = unique_id;
  if(error != XML_SUCCESS)
  {
    documents.pop_back();
    printf("Error reading file %s\n",filename.c_str());
  }
  fprintf(stderr, "Parsing gave this result %d\n", error);
  return error;
}

XMLError XMLManager::ParseDoc(const XML::Data& data)
{
  ///Check if it is a container
  const XMLElement* root = data.xmldoc.FirstChildElement("Containers");
	if(root!=nullptr)
	{
    for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement()) {
      /* code */
      const XMLAttribute* attr_gui_id = node->FirstAttribute();
      const XMLAttribute* attr_script_id = node->FirstChildElement()->FirstAttribute();
      const XMLAttribute* attr_model_id = node->FirstChildElement()->NextSiblingElement()->FirstAttribute();
      fprintf(stderr, "%s %s %s\n", attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value());
			}
      return XML_SUCCESS;
	}
	else
	{
    printf("%s\n", "Not Container XML File");
  }
  ///Check if it is a Model
  root = data.xmldoc.FirstChildElement("Models");
	if(root!=nullptr)
	{
    for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement()) {
      /* code */
      const XMLAttribute* attr_gui_id = node->FirstAttribute();
      const XMLAttribute* attr_script_id = node->FirstChildElement()->FirstAttribute();
      const XMLAttribute* attr_model_id = node->FirstChildElement()->NextSiblingElement()->FirstAttribute();
      fprintf(stderr, "%s %s %s\n", attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value());
			}
      return XML_SUCCESS;
	}
	else
	{
    printf("%s\n", "Not Model XML File");
  }
  ///Check if it is a Script
  root = data.xmldoc.FirstChildElement("Scripts");
	if(root!=nullptr)
	{
    for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement()) {
      /* code */
      const XMLAttribute* attr_gui_id = node->FirstAttribute();
      const XMLAttribute* attr_script_id = node->FirstChildElement()->FirstAttribute();
      const XMLAttribute* attr_model_id = node->FirstChildElement()->NextSiblingElement()->FirstAttribute();
      fprintf(stderr, "%s %s %s\n", attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value());
			}
      return XML_SUCCESS;
  }
  else
	{
    printf("%s\n", "Not Scripts XML File");
  }
  return XMLError::XML_ERROR_FILE_READ_ERROR;
}
