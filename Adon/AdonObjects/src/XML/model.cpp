#include "model.h"

using namespace Adon::AdonObjects::XML::Classes;

Model::Model(const std::string objectID,std::string documentID)
{
  XMLBase::SetDocID(documentID);
  XMLObject::SetObjectID(objectID);
}
