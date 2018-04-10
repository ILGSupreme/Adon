#include "script.h"

using namespace Adon::AdonObjects::XML::Classes;

Script::Script(const std::string objectID,int32 documentID)
{
  XMLBase::SetDocID(documentID);
  XMLObject::SetObjectID(objectID);
}
