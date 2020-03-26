/*************************************************************************
	> File Name: yamlcpp_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月25日 星期三 14时43分31秒
 ************************************************************************/

#include<iostream>
#include <iostream>
#include "yaml-cpp/yaml.h"
#include <fstream>

using namespace std;

int main(int argc,char** argv)
{
    YAML::Node config = YAML::LoadFile("./config.yaml");
    config["test"]["test"] = "tets";
    std::cout << config["test"]["test"] << std::endl;

    cout << "Node type " << config.Type() << endl;
    cout << "skills type " << config["skills"].Type() << endl;

    cout << "name:" << config["name"].as<string>() << endl;
    cout << "sex:" << config["sex"].as<string>() << endl;
    cout << "age:" << config["age"].as<int>() << endl;

    cout << "skills c++:" << config["skills"]["c++"].as<int>() << endl;
    cout << "skills java:" << config["skills"]["java"].as<int>() << endl;
    cout << "skills android:" << config["skills"]["android"].as<int>() << endl;
    cout << "skills python:" << config["skills"]["python"].as<int>() << endl;

    for(YAML::const_iterator it= config["skills"].begin(); it != config["skills"].end();++it){
        cout << it->first.as<string>() << ":" << it->second.as<int>() << endl;
    }

    YAML::Node test1 = YAML::Load("[1,2,3,4]");
    cout << " Type: " << test1.Type() << endl;

    YAML::Node test2 = YAML::Load("1");
    cout << " Type: " << test2.Type() << endl;

    YAML::Node test3 = YAML::Load("{'id':1,'degree':'senior'}");
    cout << " Type: " << test3.Type() << endl;

    ofstream fout("testconfig.xml");

    config["score"] = 99;

    fout << config;

    fout.close();


    return 0;

}

