#include "filemanager.h"
#include <fileconfig.h>

using namespace Adon::AdonObjects::Managers;

Filemanager::Filemanager()
{
  //printf("%s\n", "Filemanager Constructor");
  long size;
  char *buf;
  char *ptr;
  size = PATH_SIZE;
  if ((buf = (char *)malloc((size_t)size)) != NULL)
    GetCurrentDir(buf, (size_t)size,ptr);
  std::string path = std::string(ptr);
  //fprintf(stderr, "%s\n", path.c_str());
  std::string value = path.substr(path.find_last_of("/") + 1);
  std::string filepath = path.substr(0,path.find_last_of("/"));
  directory = std::make_unique<Directory>(value,filepath);
}

void Filemanager::GetAllFilesOfType(std::vector<File>& allfiles,Filetype type)
{
  Directory::GetAllFilesOfType(type,directory,allfiles);
}
