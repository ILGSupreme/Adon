#include "filemanager.h"
#include <fileconfig.h>

using namespace Adon::AdonObjects::Managers;

Filemanager::Filemanager()
{
  printf("%s\n", "Filemanager Constructor");
  long size;
  char *buf;
  char *ptr;
  size = PATH_SIZE;
  if ((buf = (char *)malloc((size_t)size)) != NULL)
    GetCurrentDir(buf, (size_t)size,ptr);
  filepath = std::string(ptr);
  fprintf(stderr, "%s\n", filepath.c_str());
}

void Filemanager::Init()
{
  //List all directories, then get all files.
  LoadFolders(filepath);
}

void Filemanager::LoadFolders(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  for(auto& value : vector)
  {
    if(is_dir((path+"/"+value).c_str())) {
      if(value.compare(std::string(".."))==0 || value.compare(std::string("."))==0){
      }
      else {
        directories.emplace_back(value,path);
      }
    }
  }
}

void Filemanager::GetAllFilesOfType(std::vector<File>& allfiles,Filetype type)
{
  for(auto& dir : directories)
  {
    Directory::GetAllFilesOfType(type,dir,allfiles);
  }
}
