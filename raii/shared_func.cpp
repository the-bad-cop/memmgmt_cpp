#include <iostream>
#include <memory>

class MyClass
{
    int _value;

public:
    MyClass(int n) : _value(n) {}
    ~MyClass() { std::cout << "Destructor called on " << this << "\n"; }
    void printValue() { std::cout << "\ninstance is: " << this << " with value " << _value << std::endl; }
};
void f(std::shared_ptr<MyClass> ptr)
{
    std::cout << "\nptr is: " << &ptr << "ref count is: " << ptr.use_count() << std::endl;
    ptr->printValue();
}

int main()
{
    std::shared_ptr<MyClass> sptr = std::make_shared<MyClass>(21);
    std::cout << "\nSptr is: " << &sptr << " and refcount is: " << sptr.use_count();
    sptr->printValue();
    std::cout << sptr.get(); //internal pointer is same as the instance
    f(sptr);
    std::cout << "Sptr is: " << &sptr << " and refcount is: " << sptr.use_count();
    sptr->printValue();
}