#include "file.h"

using namespace Adon::AdonObjects::Filesystem;

File::File(const std::string name, const std::string path)
{
  this->name = name;
  this->path = path;
  GetFileType();
}

std::string File::GetPath()
{
  return  path;
}

std::string File::GetName()
{
  return  name;
}

std::string File::GetFullPath()
{
  return (path+"/"+name);
}

void File::GetFileType()
{
  if(name.substr(name.find_last_of(".") + 1) == "xml") {
    type = Filetype::XML;
  } else {
    type = Filetype::OTHER;
  }
}

bool File::operator==(Adon::AdonObjects::Filesystem::Filetype type)
{
  return (this->type==type);
}
