#include <iostream>
#include <memory>
int main()
{
    std::shared_ptr<int> sptr(new int(5));
    std::weak_ptr<int> wptr = sptr;
    sptr.reset(new int);
    if (wptr.expired() == true)
    {
        std::cout << "Hello";
    }
}