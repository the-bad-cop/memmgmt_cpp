#include <iostream>

class raiClass
{
    int *_ptr;

public:
    raiClass(int *p = NULL) : _ptr(p) {}
    ~raiClass()
    {
        std::cout << "resource: " << *_ptr << " deallocated\n";
        delete _ptr;
    }
    int &operator*() { return *_ptr; }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < 5; i++)
    {
        // int *e = new int(i);
        raiClass e(new int(8));
        std::cout << "Dividing " << *e << " with " << a[i] << " = " << *e / a[i] << std::endl;
        // delete e;
    }
}