#include "xmldata.h"

using namespace Adon::AdonObjects;

ADONOBJECTS_EXPORT XML::Classes::XMLData::XMLData()
{
  //empty
}

ADONOBJECTS_EXPORT XML::Classes::XMLData::~XMLData()
{
	//empty
}

ADONOBJECTS_EXPORT tinyxml2::XMLError  XML::Classes::XMLData::LoadFile(std::string filename)
{
   this->filename = filename;
   return this->xmldocument.LoadFile(filename.c_str());
}

ADONOBJECTS_EXPORT const tinyxml2::XMLDocument& XML::Classes::XMLData::XMLDocument() const
{
  return xmldocument;
}
