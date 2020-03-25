/*************************************************************************
	> File Name: vector_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 17时10分13秒
    > 指针的指针， 可以用vector的指针， 理解vector的指针更能理解指针的指针
 ************************************************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

class Person {
    public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;

};

bool myCompare(Person &v1, Person &v2) {
    return v1.m_Age > v2.m_Age;

}

void test01() {
    vector<Person*> v;

    Person *p1 = new Person("刘备", 24);
    Person *p2 = new Person("关羽", 28);
    Person *p3 = new Person("张飞", 25);
    Person *p4 = new Person("赵云", 21);
    Person *p5 = new Person("诸葛", 33);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：" << (*it)->m_Name << "，年龄：" << (*it)->m_Age << endl;
    }
    
    Person** ind = v.data();
    std::cout << (*ind)->m_Name << (*ind)->m_Age << std::endl;
    ind++;
    std::cout << (*ind)->m_Name << (*ind)->m_Age << std::endl;
    ind++;
    std::cout << (*ind)->m_Name << (*ind)->m_Age << std::endl;

}

int main() {
    test01();
    return 0;
}

