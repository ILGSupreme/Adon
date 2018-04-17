#include "script.h"

using namespace Adon::AdonObjects::XML::Classes;

Script::Script(const std::string objectID,std::string documentID)
{
  XMLBase::SetDocID(documentID);
  XMLObject::SetObjectID(objectID);
}
