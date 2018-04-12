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
  GetFolders(filepath);
  GetFiles(filepath);
}

void Filemanager::GetFolders(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  for(auto& value : vector)
  {
    if(is_dir(value.c_str())) {
      fprintf(stderr, "%s\n", value.c_str());
      directories.emplace_back(value,path);
    }
  }
}

void Filemanager::GetFiles(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  for(auto& value : vector)
  {
    if(is_file(value.c_str())) {
      fprintf(stderr, "%s\n", value.c_str());
      files.emplace_back(value,path);
    }
  }
}
