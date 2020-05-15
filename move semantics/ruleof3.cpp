#include <iostream>
#include <stdlib.h>

class MyClass
{
    int *_value;
    int _size;

public:
    MyClass(size_t size)
    {
        _size = size;
        _value = new int[_size];
        std::cout << "Creating INSTANCE at: " << this << " with size " << _size * sizeof(int) << " bytes\n";
    }
    ~MyClass()
    {
        std::cout << "Deleting INSTANCE at: " << this << std::endl;
        delete[] _value;
    }
    MyClass(const MyClass &source)
    {
        _size = source._size;
        _value = new int[_size];
        *_value = *source._value;
        std::cout << "Copying content of INSTANCE :" << &source << " to instance " << this << std::endl;
    }
    MyClass &operator=(const MyClass &source)
    {
        std::cout << "Assigning content of INSTANCE: " << &source << " to instance: " << this << std::endl;
        if (this == &source)
        {
            return *this; //self assignment pot-boiler code
        }
        delete[] _value;
        _size = source._size;
        _value = new int[_size];
        *_value = *source._value;
        return *this;
    }
};
int main()
{
    MyClass obj1(99);
    MyClass obj2(obj1);
    MyClass obj3 = obj2;
    obj3 = obj1;
    obj3 = obj3; //self assignment
}