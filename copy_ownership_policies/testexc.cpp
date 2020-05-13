#include <iostream>
#include <stdlib.h>

class ExclusiveClass
{
    int *_value;

public:
    ExclusiveClass()
    {
        std::cout << "Allocating memory";
        // _value = (int *)malloc(sizeof(int));
        _value = new int;
    }
    ~ExclusiveClass()
    {
        if (_value != nullptr)
        {
            std::cout << "Deallocating";
            free(_value);
        }
    }
    ExclusiveClass(ExclusiveClass &source)
    {
        _value = source._value;
        source._value = nullptr;
    }
    ExclusiveClass &operator=(ExclusiveClass &source)
    {
        _value = source._value;
        source._value = nullptr;
        return *this;
    }
};

int main()
{
    ExclusiveClass obj1;
    ExclusiveClass obj(obj1);
}