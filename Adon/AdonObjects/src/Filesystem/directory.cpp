#include "directory.h"
#include "fileconfig.h"

using namespace Adon::AdonObjects::Filesystem;

Directory::Directory(const std::string name,const std::string path): name(name), path(path)
{
  LoadFiles(GetFullPath());
  LoadFolders(GetFullPath());
}

const std::string Directory::GetPath()
{
  return path;
}

const std::string Directory::GetName()
{
  return name;
}

std::string Directory::GetFullPath()
{
  return (path+"/"+name);
}

void Directory::LoadFolders(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  for(auto& value : vector)
  {
    if(is_dir((path+"/"+value).c_str())) {
      fprintf(stderr, "%s\n", value.c_str());
      if(value.compare(std::string(".."))==0 || value.compare(std::string("."))==0){
      }
      else {
        directories.emplace_back(value,path);
      }
    }
  }
  for(auto& dir : directories)
  {
    LoadFolders(dir.GetFullPath());
  }
}

void Directory::LoadFiles(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  for(auto& value : vector)
  {
    if(is_file((path+"/"+value).c_str())) {
        files.emplace_back(value,path);
    }
  }
}

std::vector<File>& Directory::GetFiles()
{
  return files;
}

const std::vector<Directory>& Directory::GetDirectories()
{
  return directories;
}

void Directory::GetAllFilesOfType(Filetype type,Directory curdir,std::vector<File>& allfiles)
{
  for(auto file : curdir.GetFiles())
  {
    fprintf(stderr, "%s\n", file.GetName().c_str());
    if(file==type)
    {
      allfiles.push_back(file);
    }
  }
  for(auto dir : curdir.GetDirectories())
  {
    Directory::GetAllFilesOfType(type, dir, allfiles);
  }
}
