#include <iostream> 
using namespace std; 
class A { 
public: 
    virtual void foo() { 
        cout << "A's foo()" << endl; 
        bar(); 
    } 
    virtual void bar() { 
        cout << "A's bar()" << endl; 
    } 
};

class B: public A { 
public: 
    void foo() { 
        cout << "B's foo()" << endl; 
        A::foo(); 
    } 
    void bar() { 
        cout << "B's bar()" << endl; 
    } 
}; 
int main() { 
    B bobj; 
    A *aptr = &bobj; 
    aptr->foo(); /*输出: B's foo(), A's foo()*/
    A aobj = *aptr; //转化为A类对象
    aobj.foo(); 
} 