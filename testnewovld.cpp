#include <stdlib.h>
#include <iostream>

class myClass
{
    int value;

public:
    myClass()
    {
        std::cout << "Constructor called\n";
    }
    ~myClass()
    {
        std::cout << "Destructor called\n";
    }
    void *operator new(size_t size)
    {
        void *p;
        std::cout << "Allocating " << size << " bytes\n";
        p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        std::cout << "Deallocating";
        free(p);
    }
};

int main()
{
    myClass *obj = new myClass();
    delete (obj);
}