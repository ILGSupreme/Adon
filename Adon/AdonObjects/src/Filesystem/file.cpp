#include "file.h"
#include "fileconfig.h"

using namespace Adon::AdonObjects::Filesystem;

File::File(const std::string name, const std::string path)
{
  fprintf(stderr, "%s\n", "creating file");
  this->name = name;
  this->path = path;
  this->parsed = false;
  GetFileType();
  generate_unique_id(unique_id);
  fprintf(stderr, "%s\n", unique_id.c_str());
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

std::string File::GetUniqueID()
{
  return unique_id;
}

void File::GetFileType()
{
  if(name.substr(name.find_last_of(".") + 1) == "xml") {
    type = Filetype::XML;
  } else {
    type = Filetype::OTHER;
  }
}

void File::SetParsed(bool value)
{
  this->parsed = value;
}

bool File::isParsed()
{
  return parsed;
}

bool File::operator==(Adon::AdonObjects::Filesystem::Filetype type)
{
  return (this->type==type);
}

bool File::operator==(std::string path)
{
  return ((GetFullPath().compare(path))==0);
}
