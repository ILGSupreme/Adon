#include "directory.h"

using namespace Adon::AdonObjects::Filesystem;

Directory::Directory(const std::string dirname,const std::string path): dirname(dirname), path(path)
{
}

const std::string Directory::GetPath()
{
  return path;
}

const std::string Directory::GetName()
{
  return dirname;
}
