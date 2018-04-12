#ifndef FILE_CONFIG_HEADER
#define FILE_CONFIG_HEADER

#include <cstdio>
#include <string>

#ifndef _WIN32
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <unistd.h>
#define GetCurrentDir(a,b,c) c=getcwd(a,b);
#define PATH_SIZE pathconf(".", _PC_PATH_MAX);

void read_directory(const std::string& name, std::vector<std::string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}

#define GetStat(p,b)  stat(p,b);

#else
#include <windows.h>
#include <direct.h>
#define GetCurrentDir(a,b,c) c=_getcwd(a,b);
#define PATH_SIZE _MAX_PATH;

void read_directory(const std::string& name, std::vector<std::string>& v)
{
  std::string pattern(name);
  pattern.append("\\*");
  WIN32_FIND_DATA data;
  HANDLE hFind;
  if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
    do {
      v.push_back(data.cFileName);
    } while (FindNextFile(hFind, &data) != 0);
    FindClose(hFind);
  }
}

#define GetStat(p,b)  _stat(p,b);

#endif //

bool is_file(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool is_dir(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

#endif //FILE_CONFIG_HEADER
