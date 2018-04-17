#include "directory.h"
#include "fileconfig.h"

using namespace Adon::AdonObjects::Filesystem;

Directory::Directory(const std::string name,const std::string path,bool deepSearch): name(name), path(path)
{
  fprintf(stderr,"Directory::Directory::Creating %s \n",name.c_str());
  if(deepSearch)
  {
    LoadFiles(GetFullPath());
    LoadFolders(GetFullPath());
  }
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

void Directory::LoadFolders(const std::string path,bool deepSearch)
{
  std::vector<std::string> tempfiles;
  bool tempbol = false;
  read_directory(path,tempfiles);
  for(auto& value : tempfiles)
  {
    if(is_dir((path+"/"+value).c_str())) {
      if (!IsDirDot(value) && !HaveDir(path+"/"+value)) tempbol = true;
    }
    if(tempbol) {
      directories.emplace_back(value,path,deepSearch);
      tempbol = false;
    }
  }
}

void Directory::LoadFiles(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  for(auto& value : vector)
  {
    if(is_file((path+"/"+value).c_str())) {
      if (!HaveFile(path+"/"+value)) {
        files.emplace_back(value,path);
      }
    }
  }
}

bool Directory::Exists()
{
  return is_dir(GetFullPath().c_str());
}

std::vector<File>& Directory::GetFiles()
{
  return files;
}

const std::vector<Directory>& Directory::GetDirectories()
{
  return directories;
}

bool Directory::operator==(std::string other)
{
  return ((GetFullPath().compare(other))==0);
}

void Directory::GetAllFilesOfType(Filetype type,std::unique_ptr<Directory>& ptr,std::vector<File>& allfiles)
{
  for(auto& file : ptr.get()->GetFiles())
  {
    if(file==type)
    {
      allfiles.push_back(file);
    }
  }
  for(auto& dir : ptr.get()->GetDirectories())
  {
    std::unique_ptr<Directory> tempPtr = std::make_unique<Directory>(dir);
    Directory::GetAllFilesOfType(type, tempPtr, allfiles);
  }
}

bool Directory::HaveDir(std::string path)
{
  for(auto& dir : directories)
  {
    if(dir == path) {return true;}
  }
  return false;
}

bool Directory::HaveFile(std::string path)
{
  for(auto& file : files)
  {
    if(file == path) {return true;}
  }
  return false;
}

bool Directory::IsDirDot(const std::string& path)
{
  if (path.compare(std::string(".."))<=0 || path.compare(std::string("."))<=0) {
    return true;
  }
  return false;
}


void Directory::Update()
{
  LoadFiles(GetFullPath());
  LoadFolders(GetFullPath(),false);
  for(auto& dir : directories)
  {
    dir.Update();
  }
}
