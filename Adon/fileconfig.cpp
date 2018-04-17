#include "fileconfig.h"

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

#ifdef _WIN32
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

void generate_unique_id(std::string& unique_id)
{
}

#else

void generate_unique_id(std::string& unique_id)
{
  uuid_t id;
  uuid_generate(id);
  char uuid_str[37];
  uuid_unparse(id, uuid_str);
  unique_id = std::string(uuid_str);
}

void read_directory(const std::string& name, std::vector<std::string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(dp->d_name);
    }
    closedir(dirp);
}
#endif
