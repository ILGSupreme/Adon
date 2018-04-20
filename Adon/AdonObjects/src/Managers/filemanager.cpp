#include "filemanager.h"
#include <fileconfig.h>
#include <mutex>
#include "atom.h"

using namespace Adon::AdonObjects::Managers;
using namespace Adon::AdonObjects::Filesystem;

Filemanager::Filemanager()
{
  long size;
  char *buf;
  char *ptr;
  size = PATH_SIZE;
  if ((buf = (char *)malloc((size_t)size)) != NULL)
    GetCurrentDir(buf, (size_t)size,ptr);
  std::string path = std::string(ptr);
  std::string value = path.substr(path.find_last_of("/") + 1);
  std::string filepath = path.substr(0,path.find_last_of("/"));
  directory = std::make_unique<Directory>(value,filepath);
}

void Filemanager::GetAllFilesOfType(std::vector<std::shared_ptr<Adon::AdonObjects::Filesystem::File>>& allfiles,Filetype type)
{
  Directory::GetAllFilesOfType(type,directory,allfiles);
}

void Filemanager::GetNewFiles(std::vector<std::shared_ptr<Adon::AdonObjects::Filesystem::File>>& files,Filetype type)
{
  Directory::GetNewFiles(type,directory,files);
}
