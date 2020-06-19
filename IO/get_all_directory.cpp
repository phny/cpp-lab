/*************************************************************************
> File Name: get_all_directory.cpp
> Author:
> Mail:
> Created Time: 2020年06月01日 星期一 16时15分27秒
************************************************************************/

#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <vector>

using namespace std;

/// @brief 读取指定文件夹下面的所有子文件夹
void GetAllDirectories(std::string path, std::vector<std::string> &all_dirs) {
  const char *PATH = path.c_str();
  DIR *dir = opendir(PATH);
  if (path.back() != '/') {
    path += "/";
  }

  struct dirent *entry = readdir(dir);

  while (entry != NULL) {
    if (entry->d_type == DT_DIR) {
      std::string dir_name(entry->d_name);
      if (dir_name.compare(R"(.)") != 0 && dir_name.compare(R"(..)") != 0) {
        all_dirs.push_back(path + entry->d_name);
      }
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

/// @brief 判断路径是否为文件
///   里面调用了 stat 的系统接口: man 2 stat 查看具体用法
static bool IsFile(const std::string &path) {
  struct stat path_stat;

  if (stat(path.c_str(), &path_stat) == 0) {
    // 路径存在则判断是否为文件 (REG 表示 regular file)
    return S_ISREG(path_stat.st_mode);
  } else {
    // 路径不存在则返回 false
    return false;
  }
}

static void GetDirAllFiles(std::string feature_dir,
                           std::vector<std::string> &out_file_paths) {
  if ("" == feature_dir) {
    std::cout << " feature_dir is null ! " << std::endl;
    exit(-1);
  }
  struct stat s;
  lstat(feature_dir.c_str(), &s);
  if (!S_ISDIR(s.st_mode)) {
    std::cout << "feature_dir is not a valid directory !" << std::endl;
    exit(-1);
  }
  struct dirent *filename;
  DIR *dir;
  dir = opendir(feature_dir.c_str());
  if (NULL == dir) {
    std::cout << "Can not open dir " << feature_dir << std::endl;
    exit(-1);
  }
  while ((filename = readdir(dir)) != NULL) {
    if (strcmp(filename->d_name, ".") == 0 ||
        strcmp(filename->d_name, "..") == 0) {
      continue;
    }
    auto ind = feature_dir.find_last_of("/");
    std::string abs_path = ind == feature_dir.length() - 1
                               ? feature_dir + filename->d_name
                               : feature_dir + "/" + filename->d_name;
    // 判断是否为文件
    if (IsFile(abs_path)) {
      out_file_paths.push_back(abs_path);
    }
  }
}

int main() {
  std::vector<string> all_dirs;
  GetAllDirectories(
      "/home/SENSETIME/heyulin/dev/cstk/build/samples/body_cluster/result",
      all_dirs);

  for (auto &dir : all_dirs) {
    cout << dir << endl;
  }

  std::vector<string> aa;
  GetDirAllFiles("/home/SENSETIME/heyulin/dev/cstk/build/samples/body_cluster/"
                 "result/day_0",
                 aa);
  for (auto &file : aa) {
    cout << file << endl;
  }

  return 0;
}
