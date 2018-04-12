#include "file.h"

using namespace Adon::AdonObjects::Filesystem;

File::File(const std::string name, const std::string path)
{
  this->name = name;
  this->path = path;
}

std::string File::GetPath()
{
  return  path;
}

std::string File::GetName()
{
  return  name;
}
