#include "xmlmanager.h"

using namespace Adon::AdonObjects::Managers;

void XMLManager::ParseFile(const std::string filename)
{
  documents.emplace_back();
  documents.back().xmldoc.LoadFile(filename.c_str());
}
