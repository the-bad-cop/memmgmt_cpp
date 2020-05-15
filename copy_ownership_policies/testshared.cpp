#include <stdlib.h>
#include <iostream>

class SharedPolicy
{
    int *_value;
    static int count;

public:
    SharedPolicy(int);
    ~SharedPolicy();
    SharedPolicy(SharedPolicy &source);
};

int SharedPolicy::count = 0;

SharedPolicy::SharedPolicy(int n)
{
    _value = new int;
    *_value = n;
    ++count;
    std::cout << "\nAllocated at : " << _value;
}

SharedPolicy::~SharedPolicy()
{
    --count;
    if (count == 0)
    {
        delete _value;
        std::cout << "\nFreed at : " << _value;
    }
    else
    {
        std::cout << "\nInstance " << count << "goes out of scope having address " << this;
    }
}

SharedPolicy::SharedPolicy(SharedPolicy &source)
{
    ++count;
    _value = source._value;
    std::cout << "\nCount:" << count << "instances to resource at :" << _value << " with value: " << *_value;
}

int main()
{
    SharedPolicy sp(3);
    SharedPolicy cpy(sp);
    SharedPolicy cpy2(cpy);
}