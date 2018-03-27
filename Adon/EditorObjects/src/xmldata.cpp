#include "xmldata.h"


EDITOR_OBJECTS_EXPORT Adon::EditorObjects::XML::XMLData::XMLData()
{
  //empty
}

EDITOR_OBJECTS_EXPORT Adon::EditorObjects::XML::XMLData::~XMLData()
{
	//empty
}

EDITOR_OBJECTS_EXPORT tinyxml2::XMLError Adon::EditorObjects::XML::XMLData::LoadFile(std::string filename)
{
   return this->xmldocument.LoadFile(filename.c_str());
}
