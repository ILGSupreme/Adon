#include "xmlobject.h"


using namespace Adon::AdonObjects::XML::Classes;

void XMLObject::ChangeAttrValueInt(const XMLAttribute*& attr, int32 value) const
{
  (const_cast<XMLAttribute*&>(attr))->SetAttribute(value);
}

void XMLObject::ChangeAttrValueString(const XMLAttribute*& attr, std::string value) const
{
  (const_cast<XMLAttribute*&>(attr))->SetAttribute(value.c_str());
}
