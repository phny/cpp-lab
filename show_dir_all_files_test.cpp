/*************************************************************************
	> File Name: show_dir_all_files_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月20日 星期五 16时16分22秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <vector>
using namespace std;
 
void GetDirAllFiles(std::string& feature_dir, std::vector<std::string>& out_file_paths) {
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
    struct dirent* filename;
    DIR* dir;
    dir = opendir(feature_dir.c_str());
    if (NULL == dir) {
        cout << "Can not open dir " << feature_dir << endl;
        exit(-1);
    }
    while ((filename = readdir(dir)) != NULL) {
        if (strcmp(filename->d_name, ".") == 0 || strcmp(filename->d_name, "..") == 0){
            continue;
        }
        auto ind = feature_dir.find_last_of("/");
        std::string abs_path = ind == feature_dir.length()-1 ? feature_dir + filename->d_name : feature_dir + "/" + filename->d_name; 
        out_file_paths.push_back(abs_path);
    }
}

 
int main()
{
    std::string feature_dir = "/data/pyutils";
    std::vector<std::string> out;
    GetDirAllFiles(feature_dir, out);
    for (auto i : out) {
        std::cout << i << std::endl;
    }
	return 0; 
}
