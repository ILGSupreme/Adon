#include "entitymanager.h"
#include "entity.h"
#include "fileconfig.h"

using namespace Adon::Application;
using namespace tinyxml2;

EntityManager::EntityManager()
{
  run_thread = true;
}

EntityManager::~EntityManager()
{
  //empty code
  if(t1.joinable())
  {
    t1.join();
  }
}

void EntityManager::Init()
{
  std::vector<File> xmlfiles;
  Adon::AdonObjects::Managers::Filemanager::GetAllFilesOfType(xmlfiles,Filetype::XML);

  fprintf(stderr, "EntityManager::Init: size of xml vector %lu\n", xmlfiles.size());
  for(auto& file : xmlfiles)
  {
      fprintf(stderr, "%s\n", file.GetFullPath().c_str());
      if(ParseFile(file.GetFullPath())!=XML_SUCCESS)
      {
        fprintf(stderr, "Cant parse file: %s\n", file.GetName().c_str());
      }
      else
      {
        fprintf(stderr, "%s\n", "Parsed XML FILE");
      }
  }

  ParseAllDocs();
}

void EntityManager::Run()
{
    t1 = std::thread(&EntityManager::Update,this);
}

void EntityManager::Stop()
{
  run_thread = false;
}

XMLError EntityManager::ParseAllDocs()
{
  XMLError err;
  for (auto& doc :  documents) {
    err = ParseDoc(doc);
  }
  return err;
}

XMLError EntityManager::ParseDoc(const XML::Data& data)
{
  ///Check if it is a container
  const XMLElement* root = data.xmldoc.FirstChildElement("Containers");
	if(root!=nullptr)
	{
    std::pair<std::map<int,Container_Vector>::iterator,bool> cont_pair = containers.insert(std::map<int,Container_Vector>::value_type(0,Container_Vector()));
    for (const XMLElement* node = root->FirstChildElement(); node != nullptr; node = node->NextSiblingElement()) {
      /* code */
      const XMLAttribute* attr_gui_id = node->FirstAttribute();
      const XMLAttribute* attr_script_id = node->FirstChildElement()->FirstAttribute();
      const XMLAttribute* attr_model_id = node->FirstChildElement()->NextSiblingElement()->FirstAttribute();
      fprintf(stderr, "%s %s %s\n", attr_gui_id->Value(),attr_script_id->Value(),attr_model_id->Value());
      (*cont_pair.first).second.emplace_back(
        new Adon::Application::Entity(
          std::string(node->Value()),0,attr_gui_id,attr_script_id,attr_model_id));
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

void EntityManager::Update()
{
  while(run_thread)
  {
    directory.get()->Update();
    std::this_thread::sleep_for(5s);
  }
}
