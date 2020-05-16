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
    MyClass(MyClass &&source)
    {
        std::cout << "MOVING instance(cons~t): " << &source << " to instance: " << this << std::endl;
        _value = source._value;
        _size = source._size;
        source._size = 0;
        source._value = nullptr;
    }
    MyClass &operator=(MyClass &&source)
    {
        std::cout << "MOVING instance(asignOPera): " << &source << " to instance: " << this << std::endl;
        if (this == &source)
        {
            return *this;
        }
        _size = source._size;
        _value = source._value;
        source._value = nullptr;
        source._size = 0;
        return *this;
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
    /*
    MyClass obj1(10), obj2(20);
    MyClass obj3(obj1);
    MyClass obj4 = obj1;
    obj4 = obj2;
    */
    // MyClass obj1(10);
    // obj1 = MyClass(20);
    MyClass obj2 = std::move(MyClass(30));
    // MyClass obj3(std::move(obj1));
}