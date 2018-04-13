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
  fprintf(stderr, "%lu\n", vector.size());
  for(auto& value : vector)
  {
    fprintf(stderr, "%s\n", (path+"/"+value).c_str());
    if(is_dir((path+"/"+value).c_str())) {
      fprintf(stderr, "Directory:LoadFolders %s\n", value.c_str());
      if(IsDirDot(value)){
        fprintf(stderr, "%s\n", "was dot stuff");
      }
      else {
        directories.emplace_back(value,path);
      }
    }
  }
  fprintf(stderr, "%s\n", "exiting");
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
  return (GetFullPath().compare(other));
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

bool Directory::HaveDir(std::string path)
{
  for(auto& dir : directories)
  {
    fprintf(stderr, "Directory: %s\n", path.c_str());
    if(dir == path) {return true;}
  }
  return false;
}

bool Directory::IsDirDot(const std::string& path)
{
  if (path.compare(std::string(".."))==0 || path.compare(std::string("."))==0) {
    return true;
  }
  return false;
}


void Directory::Update()
{
  std::vector<std::string> tempfiles;
  bool tempbol = false;
  read_directory(GetFullPath(),tempfiles);
  for(auto& value : tempfiles)
  {
    if(!is_file((GetFullPath()+"/"+value).c_str())) {
      if (!IsDirDot(value) && !HaveDir(GetFullPath()+"/"+value)) tempbol = true;
    }
    if(tempbol) {
      fprintf(stderr, "%s\n", "Directory: Found new Folder");
      //directories.emplace_back(value,GetFullPath());
      tempbol = false;
    }
  }
  for(auto& dir : directories)
  {
    dir.Update();
  }
}
