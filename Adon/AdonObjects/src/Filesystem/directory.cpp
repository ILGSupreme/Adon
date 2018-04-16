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

void Directory::LoadFolders(const std::string path)
{
  std::vector<std::string> vector;
  read_directory(path,vector);
  //fprintf(stderr, "Directory::LoadFolders: Size of vector %lu\n", vector.size());
  for(auto& value : vector)
  {
    //fprintf(stderr, "%s\n", (path+"/"+value).c_str());
    if(is_dir((path+"/"+value).c_str())) {
      //fprintf(stderr, "Directory:LoadFolders %s\n", value.c_str());
      if(IsDirDot(value)) {
        //fprintf(stderr, "%s\n", "Directory::LoadFolders: Folder was of dot");
      }
      else {
        //fprintf(stderr, "Directory::LoadFolders Adding %s\n", value.c_str());
        directories.emplace_back(value,path);
        //fprintf(stderr, "Directory::LoadFolders: Size of directories %lu\n", directories.size());
      }
    }
  }
  //fprintf(stderr, "%s, Address %p\n", "Directory::LoadFolders:: Exiting",&*this);
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
  return ((GetFullPath().compare(other))==0);
}

void Directory::GetAllFilesOfType(Filetype type,std::unique_ptr<Directory>& ptr,std::vector<File>& allfiles)
{
  for(auto file : ptr.get()->GetFiles())
  {
    //fprintf(stderr, "Directory::GetAllFilesOfType: file %s\n", file.GetName().c_str());
    if(file==type)
    {
      allfiles.push_back(file);
    }
  }
  for(auto dir : ptr.get()->GetDirectories())
  {
    std::unique_ptr<Directory> tempPtr = std::make_unique<Directory>(dir);
    Directory::GetAllFilesOfType(type, tempPtr, allfiles);
  }
}

bool Directory::HaveDir(std::string path)
{
  for(auto& dir : directories)
  {
    //fprintf(stderr, "Directory::HaveDir: %s\n", dir.GetFullPath().c_str());
    if(dir == path) {return true;}
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
  //fprintf(stderr, "Directory::Update::Size of directories %lu\n", directories.size());
  std::vector<std::string> tempfiles;
  bool tempbol = false;
  read_directory(GetFullPath(),tempfiles);
  for(auto& value : tempfiles)
  {
    //fprintf(stderr, "Directory::Update::Value %s\n", value.c_str());
    if(is_dir((GetFullPath()+"/"+value).c_str())) {
      //if(value == "ii") {
      //fprintf(stderr, "Do we have it : %s\n", HaveDir((GetFullPath()+"/"+value).c_str()) ? "true" : "false");
      //fprintf(stderr, "Is it . or .. : %s\n", IsDirDot(value) ? "true" : "false");
      //}
      if (!IsDirDot(value) && !HaveDir(GetFullPath()+"/"+value)) tempbol = true;
    }
    if(tempbol) {
      //fprintf(stderr, "%s : %s : %s\n", "Directory: Found new Folder",value.c_str(), (GetFullPath()+"/"+value).c_str());
      directories.emplace_back(value,GetFullPath(),false);
      tempbol = false;
    }
  }
  for(auto& dir : directories)
  {
    dir.Update();
  }
}
