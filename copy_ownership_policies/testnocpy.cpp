#include <iostream>
#include <stdlib.h>

class myClassa
{
    myClassa(const myClassa &);
    myClassa &operator=(const myClassa &);

public:
    myClassa() {}
};

class myClassb
{
public:
    myClassb(const myClassb &) = delete;
    myClassb &operator=(const myClassb &) = delete;
    myClassb() {}
};

int main()
{
    myClassa obja;
    myClassb objb(obja);
    /*
    myClassa cpy1(obja);
    myClassa cpy2 = obja;
    myClassb objb;
    myClassb cpyb1(objb);
    myClassb cpyb2 = objb;
*/
}