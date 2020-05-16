#include <iostream>
#include <string>
#include <memory>
class MyClass
{
    std::string _text;

public:
    MyClass() {}
    MyClass(std::string str) : _text(str) {}
    ~MyClass() { std::cout << _text << "Text destroyed\n "; }
    void setText(std::string text) { _text = text; }
};

int main()
{
    std::unique_ptr<MyClass> obj1(new MyClass());
    std::unique_ptr<MyClass> obj2(new MyClass("Hello"));
    obj1->setText("World");
    *obj2 = *obj1; //even after copying both have different stack adresses coz heap data is only copied

    // std::unique_ptr<MyClass> obj3 = obj1;

    //use the .get() fn to het the address of the raw pointer. ie; the obj handle ptr exists in the stack mem
    //to get the adress of the object alocated in the heap, .get() is used
    std::cout << "Address of obj1 in stack is " << &obj1 << " and heap is " << obj1.get() << std::endl;
}