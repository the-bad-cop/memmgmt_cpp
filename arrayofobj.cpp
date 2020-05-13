#include <iostream>
#include <stdlib.h>

class MyClass
{
    int _mymember;

public:
    MyClass()
    {
        std::cout << "Constructor is called\n";
    }

    ~MyClass()
    {
        std::cout << "Destructor is called\n";
    }

    void *operator new[](size_t size) //Aleays total size+ 8 bytes is used for allocation overhead
    {
        std::cout << "new: Allocating " << size << " bytes of memory" << n << std::endl;
        void *p = malloc(size);

        return p;
    }
    /*
    void *operator new[](size_t size, int t)
    {
        std::cout << "newer";
        void *n;
        return n;
    }
    */
    void operator delete[](void *p)
    {
        std::cout << "delete: Memory is freed again " << std::endl;
        free(p);
    }
};

int main()
{
    MyClass *p = new MyClass[3]();

    delete[] p;
}