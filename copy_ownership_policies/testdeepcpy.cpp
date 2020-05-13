#include <stdlib.h>
#include <iostream>

class DeepCopy
{
    int *_value;

public:
    DeepCopy(int n)
    {
        // _value=(int*)malloc(sizeof(int));
        _value = new int;
        *_value = n;
        std::cout << "Allocated " << *_value << "at: " << _value;
    }
    ~DeepCopy()
    {
        delete _value;
        std::cout << "\nDeallocated at: " << _value;
    }
    DeepCopy(DeepCopy &source)
    {
        _value = new int;
        *_value = *source._value;
        std::cout << "\nAllocted " << *_value << " inside at: " << _value;
    }
    DeepCopy &operator=(DeepCopy &source)
    {
        _value = new int;
        *_value = *source._value;
        return *this;
    }
};
int main()
{
    DeepCopy d(8);
    DeepCopy cpy(d);
}