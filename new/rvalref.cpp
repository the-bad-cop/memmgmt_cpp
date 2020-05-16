#include <iostream>

void myFunction(int &&val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(std::move(j));

    myFunction(42);

    int k = 23;
    myFunction(j + k);
    // int &&l = j + k;
    // myFunction(l);
    return 0;
}