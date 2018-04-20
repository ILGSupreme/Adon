#include "xmlmanager.h"
#include "atom.h"

using namespace Adon::AdonObjects::Managers;
using namespace Adon::AdonObjects::XML;
using namespace tinyxml2;

XMLError XMLManager::ParseFile(const std::string filename,const std::string unique_id)
{
  fprintf(stderr, "%s\n", "PARSING");
  XMLDocument doc;
  if(doc.LoadFile(filename.c_str())!=XML_SUCCESS)
  {
    fprintf(stderr, "%s\n", "ERROR");
    return XML_ERROR_PARSING;
  }
  fprintf(stderr, "%s\n", "NO ERROR");
  const XMLElement* root = doc.FirstChildElement("Containers");
  if(root!=nullptr)
  {
    for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement()) {
      /* code */
      const XMLAttribute* attr_gui_id = node->FirstAttribute();
      const XMLAttribute* attr_script_id = node->FirstChildElement()->FirstAttribute();
      const XMLAttribute* attr_model_id = node->FirstChildElement()->NextSiblingElement()->FirstAttribute();
      fprintf(stderr, "%s %s %s\n", attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value());
      Container cont = {attr_gui_id->Value(),attr_model_id->Value(),attr_script_id->Value()};
      container_map.insert(std::pair<std::string,std::shared_ptr<cont_pair>>(unique_id,std::make_shared<cont_pair>(cont_pair(attr_gui_id->Value(),cont))));
    }
    return XML_SUCCESS;
  }
  else
  {
    printf("%s\n", "Not Container XML File");
  }
  ///Check if it is a Model
  root = doc.FirstChildElement("Models");
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
  root = doc.FirstChildElement("Scripts");
  if(root!=nullptr)
  {
    for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement())
    {
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

void XMLManager::ParseAllFiles(std::vector<std::shared_ptr<Filesystem::File>>& ptr_files)
{
  for(auto ptr : ptr_files)
  {
    std::string test = ptr->GetFullPath();
    ParseFile((ptr.get())->GetFullPath(),(ptr.get())->GetUniqueID());
    ptr.get()->SetParsed(true);
  }
  ptr_files.clear();
}
