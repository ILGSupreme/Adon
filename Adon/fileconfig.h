#ifndef FILE_CONFIG_HEADER
#define FILE_CONFIG_HEADER

#include <cstdio>
#include <string>

#ifndef _WIN32

#if defined(unix) || defined(__unix__) || defined(__unix)
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <vector>
#include <unistd.h>
#include <uuid/uuid.h>
#define GetCurrentDir(a,b,c) c=getcwd(a,b);
#define PATH_SIZE pathconf(".", _PC_PATH_MAX);
#define GetStat(p,b)  stat(p,b);
#endif // NOT UNIX MACHINE

#else //IT IS WINDOWS

#include <windows.h>
#include <direct.h>
#include <Rpcdce.h>
#define GetCurrentDir(a,b,c) c=_getcwd(a,b);
#define PATH_SIZE _MAX_PATH;
#define GetStat(p,b)  _stat(p,b);

#endif // END OF DEF
bool is_file(const char* path);
bool is_dir(const char* path);
void read_directory(const std::string& name, std::vector<std::string>& v);
void generate_unique_id(std::string& unique_id);
#endif //FILE_CONFIG_HEADER
