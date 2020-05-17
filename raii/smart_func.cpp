#include <iostream>
#include <memory>
class MyClass
{
    int _val;

public:
    MyClass(int n) : _val(n) {}
    ~MyClass() { std::cout << "\nDestrucutor called\n"; }
    void printVal() { std::cout << "\nManaged object :" << this << "  Value :" << _val << std::endl; }
};

void f(std::unique_ptr<MyClass> ptr)
{
    std::cout << "Unique_ptr: " << &ptr;
    ptr->printVal();
}
//the adress of the object in heap is same in both the outputs but the handle has been changed
int main() //now the function contains the handle and the handle in the main is disqualified
{
    std::unique_ptr<MyClass> uptr = std::make_unique<MyClass>(9);
    // std::unique_ptr<MyClass> uptr(new MyClass(9));
    std::cout << "Unique_ptr: " << &uptr << std::endl;
    uptr->printVal();
    f(std::move(uptr));
    if (uptr) //the uptr is not valid anymore as smartptr adhere with move semantics internally
    {         //the handle is only transferred
        std::cout << "Uptr after f :" << &uptr << std::endl;
    }
}