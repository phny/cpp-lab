/*************************************************************************
        > File Name: show_dir_all_files_test.cpp
        > Author:
        > Mail:
        > Created Time: 2020年03月20日 星期五 16时16分22秒
 ************************************************************************/

#include <dirent.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <vector>
using namespace std;

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

/// @brief 判断路径是否为文件夹
///   里面调用了 stat 的系统接口: man 2 stat 查看具体用法
static bool IsDirectory(const std::string &path) {
  struct stat path_stat;

  if (stat(path.c_str(), &path_stat) == 0) {
    // 路径存在则判断是否为文件夹
    return S_ISDIR(path_stat.st_mode);
  } else {
    // 路径不存在则返回 false
    return false;
  }
}

void GetDirAllFiles(std::string &feature_dir,
                    std::vector<std::string> &out_file_paths) {
  if ("" == feature_dir) {
    cout << " feature_dir is null ! " << endl;
    exit(-1);
  }
  struct stat s;
  lstat(feature_dir.c_str(), &s);
  if (!S_ISDIR(s.st_mode)) {
    cout << "feature_dir is not a valid directory !" << endl;
    exit(-1);
  }
  struct dirent *filename;
  DIR *dir;
  dir = opendir(feature_dir.c_str());
  if (NULL == dir) {
    cout << "Can not open dir " << feature_dir << endl;
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
    if (IsFile(abs_path)) {
      out_file_paths.push_back(abs_path);
    }
  }
}

int main() {
  std::string feature_dir = "/home/SENSETIME/heyulin";
  std::vector<std::string> out;
  GetDirAllFiles(feature_dir, out);
  for (auto i : out) {
    std::cout << i << std::endl;
  }
  return 0;
}
