/*************************************************************************
	> File Name: friend_function.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年01月09日 星期四 09时27分47秒
 ************************************************************************/

#include<iostream>

using namespace std;

class Box {
public:
    Box() = default;
    Box(double length, double width);
    double length;
    friend void printWidth(Box box);
    void setWidth(double width);
private:
    double width;
};

Box::Box(double length, double width) {
    this->length = length;
    this->width = width;
}

void Box::setWidth(double width) {
    if (width > 0 ) {
        this->width = width;
    } else {
        cout << "wodth is invaid" << endl;
    }
}

void printWidth(Box box) {
    cout << "Box width is: " << box.width << endl;
}

int main() {
    Box box(10, 20);
    printWidth(box);
 
    return 0;
}
