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
   this->filename = filename;
   return this->xmldocument.LoadFile(filename.c_str());
}

EDITOR_OBJECTS_EXPORT const tinyxml2::XMLDocument& Adon::EditorObjects::XML::XMLData::XMLDocument() const
{
  return xmldocument;
}
