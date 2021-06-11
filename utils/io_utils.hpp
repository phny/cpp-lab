#ifndef IO_UTILS_HPP_
#define IO_UTILS_HPP_

#include <dirent.h>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

/// @brief 获取文件的大小，单位是字节
static int64_t GetFileSize(const std::string &file_path) {
  struct stat stat_buf;
  int rc = stat(file_path.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
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

/// @brief 直接创建文件夹
///   directory: 要创建的文件夹路径
///   try_time: 多次尝试的次数
static void CreateDirectory(const std::string &directory,
                            const int try_time = 2) {
  try {
    if (mkdir(directory.c_str(), 0777) == 0) {
      return;
    }
  } catch (...) {
    // 如果创建出了异常，有可能是文件夹已经存在
    //   重新判断文件夹是否存在，如果存在则返回
    if (IsDirectory(directory)) {
      return;
    } else {
      if (try_time > 0) {
        CreateDirectory(directory, try_time - 1);
      } else {
        std::cout << "[ERROR] cannot create directory: " << directory
                  << std::endl;
        exit(-1);
      }
    }
  }
}

/// @brief 如果文件夹不存在，则创建
///   里面调用系统 mkdir 接口: man 2 mkdir 查看具体用法
static void CreateDirectoryIfNotExists(const std::string &directory) {
  // 文件夹已存在，则直接返回
  if (IsDirectory(directory)) {
    return;
  }

  const int directory_len = directory.length();
  int slash_position = 0;

  // 如果文件夹以 / 开头，则往后继续遍历
  if (directory[0] == '/') {
    slash_position++;
  }

  while (slash_position < directory_len) {
    // 如果找到，则创建子文件夹
    if (directory[slash_position] == '/') {
      const std::string sub_folder = directory.substr(0, slash_position);

      // 如果子文件夹不存在，则创建
      if (!IsDirectory(sub_folder)) {
        CreateDirectory(sub_folder);
      }
    }

    slash_position++;
  }

  // 最后创建整个文件夹路径
  if (!IsDirectory(directory)) {
    CreateDirectory(directory);
  }
}

/// @brief 如果文件所在的文件夹不存在，则创建
static void CreateDirectoryForFile(const std::string &file_path) {
  const std::string directory =
      file_path.substr(0, file_path.find_last_of("/"));
  CreateDirectoryIfNotExists(directory);
}

static void RemoveFile(const std::string &file_path) {
  remove(file_path.c_str());
}

static void RemoveDir(const std::string &dir_path) {
  if (!IsDirectory(dir_path)) {
    return;
  }
  struct dirent *entry = NULL;
  DIR *dir = NULL;
  const char *path = dir_path.c_str();
  dir = opendir(path);
  entry = readdir(dir);
  while (entry) {
    DIR *sub_dir = NULL;
    FILE *file = NULL;
    char abs_path[100] = {0};
    if (*(entry->d_name) != '.') {
      sprintf(abs_path, "%s/%s", path, entry->d_name);
      sub_dir = opendir(abs_path);
      if (sub_dir) {
        closedir(sub_dir);
        RemoveDir(abs_path);
      } else {
        file = fopen(abs_path, "r");
        if (file) {
          fclose(file);
          remove(abs_path);
        }
      }
    }
    entry = readdir(dir);
  }
  closedir(dir);
  remove(path);
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

/// @brief 获取文件夹下面的所有文件（不包含子目录的文件）
static void GetDirAllFilesWithSubDir(std::string feature_dir,
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
    } else {
      /// 递归遍历子目录
      GetDirAllFilesWithSubDir(abs_path, out_file_paths);
    }
  }
}

/// @brief 读取指定文件夹下面的所有子文件夹
void GetAllDirectories(std::string dir_path,
                       std::vector<std::string> &all_dirs) {
  const char *PATH = dir_path.c_str();
  DIR *dir = opendir(PATH);

  if (dir_path.back() != '/') {
    dir_path += "/";
  }

  struct dirent *entry = readdir(dir);

  while (entry != NULL) {
    if (entry->d_type == DT_DIR) {
      std::string dir_name(entry->d_name);
      if (dir_name != R"(.)" && dir_name != R"(..)") {
        all_dirs.push_back(dir_path + entry->d_name);
      }
    }
    entry = readdir(dir);
  }
  closedir(dir);
}

/// @brief 文件重命名
void FileRename(const std::string src_file_path,
                const std::string dst_file_path) {
  rename(src_file_path.c_str(), dst_file_path.c_str());
}

/// @brief 拷贝文件
void FileCopy(const std::string src_path, const std::string dst_path) {
  std::ifstream src(src_path, std::ios::binary);
  std::ofstream dst(dst_path, std::ios::binary);

  dst << src.rdbuf();

  src.close();
  dst.close();
}

/// @brief 移动文件
void MoveFile(const std::string src_path, const std::string dst_path) {
  std::ifstream in(src_path, std::ios::in | std::ios::binary);
  std::ofstream out(dst_path, std::ios::out | std::ios::binary);
  out << in.rdbuf();
  std::remove(src_path.c_str());
  out.close();
  in.close();
}

/// @brief 从文件中加载所有行
void LoadVectorFromFile(const std::string &file_path,
                        std::vector<std::string> &vec) {
  std::ifstream in_file(file_path);

  if (!in_file) {
    std::cout << "can not open file: " << file_path << std::endl;
    exit(-1);
  }

  vec.clear();
  // 一次读取一行数据
  if (in_file.is_open()) {
    std::string line;
    while (std::getline(in_file, line)) {
      vec.push_back(line);
    }
  }

  in_file.close();
}

/// @brief 读取文本文件到数组中
template <typename Dtype>
void LoadLinesToVector(const std::string path, std::vector<Dtype> &output_vec) {
  // 读取所有行
  std::vector<std::string> v;
  LoadVectorFromFile(path, v);
  output_vec = [&v]() -> std::vector<Dtype> {
    // 将 camera_ids 转换成 int32_t
    std::vector<Dtype> ret;
    std::stringstream oss;
    for (auto &item : v) {
      Dtype dst;
      oss << item;
      oss >> dst;
      oss.clear();
      ret.push_back(dst);
    }
    return ret;
  }();
}

#endif
