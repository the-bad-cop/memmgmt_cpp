#include <iostream>
void Sum(int &&i)
{
    std::cout << i;
}
int main()
{
    int m = 1;
    int n = 2;
    Sum(5);
    // Sum(m); //error
    Sum(std::move(m)); //use std::move to convert l to rvalue
    Sum(m + n);
}