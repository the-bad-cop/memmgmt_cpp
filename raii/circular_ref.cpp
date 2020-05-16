#include <iostream>
#include <memory>
class MyClass
{
public:
    MyClass() {}
    ~MyClass() { std::cout << "DEstrucutor called \n"; }
    std::shared_ptr<MyClass> ptr;
};

int main()
{
    MyClass obj1();
    MyClass obj2();
    std::shared_ptr<MyClass> obj3(new MyClass());
    std::shared_ptr<MyClass> obj4(new MyClass());
    obj3->ptr = obj4;
    obj4->ptr = obj3; //destructor is not called due to deaadlock
}