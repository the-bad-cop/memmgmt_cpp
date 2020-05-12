#include <stdlib.h>
#include <iostream>

class myClass
{
private:
    int *_value;

public:
    myClass(int n)
    {
        std::cout << "Allocating::";
        _value = (int *)malloc(sizeof(int));
        *_value = n;
    }
    void setValue(int n)
    {
        *_value = n;
    }
    void getValue()
    {
        std::cout << "Value is:" << *_value;
    }
    ~myClass()
    {
        free(_value);
    }
};

int main()
{
    myClass obj(2);
    // obj.setValue(5);
    obj.getValue();
    obj.~myClass();
}