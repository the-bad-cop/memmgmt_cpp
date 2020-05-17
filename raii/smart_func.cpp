#include <iostream>
#include <memory>
class MyClass
{
    int _val;

public:
    MyClass(int n) : _val(n) {}
    ~MyClass() { std::cout << "\nDestrucutor called\n"; }
    void printVal() { std::cout << "\nManaged object :" << this << "  Value :" << _val << std::endl; }
};

void f(std::unique_ptr<MyClass> ptr)
{
    std::cout << "Unique_ptr: " << &ptr;
    ptr->printVal();
}
//the adress of the object in heap is same in both the outputs but the handle has been changed
int main() //now the function contains the handle and the handle in the main is disqualified
{
    std::unique_ptr<MyClass> uptr = std::make_unique<MyClass>(9);
    // std::unique_ptr<MyClass> uptr(new MyClass(9));
    std::cout << "Unique_ptr: " << &uptr << std::endl;
    uptr->printVal();
    f(std::move(uptr));
    // f(uptr);
    if (uptr) //the uptr is not valid anymore as smartptr adhere with move semantics internally
    {         //the handle is only transferred
        std::cout << "Uptr after f :" << &uptr << std::endl;
    }
}

/*
The basic idea of a unique_ptr is that there exists only a single instance of it.
 This is why it can’t be copied to a local function but needs to be moved instead with the function std::move.
  The code example on the right illustrates the principle of transferring the object managed by the unique pointer uniquePtr into
   a function f.

The class MyClass has a private object _member and a public function printVal() 
which prints the address of the managed object (this) as well as the member value to the console.
 In main, an instance of MyClass is created by the factory function make_unique() and assigned to a unique pointer
  instance uniquePtr for management. Then, the pointer instance is moved into the function f using move semantics.
   As we have not overloaded the move constructor or move assignment operator in MyClass, the compiler is using the default 
   implementation. In f, the address of the copied / moved unique pointer ptr is printed and the function printVal() is called on it. 
   When the path of execution returns to main(), the program checks for the validity of uniquePtr and, if valid, calls
    the function printVal() on it again. Here is the console output of the program:


unique_ptr 0x7ffeefbff710, managed object 0x100300060 with val = 23

unique_ptr 0x7ffeefbff6f0, managed object 0x100300060 with val = 23
The output nicely illustrates the copy / move operation. Note that the address 
of unique_ptr differs between the two calls while the address of the managed object as
 well as of the value are identical. This is consistent with the inner workings of the move constructor,
  which we overloaded in a previous section. The copy-by-value behavior of f() creates a new instance of the 
  unique pointer but then switches the address of the managed MyClass instance from source to destination
  . After the move is complete, we can still use the variable uniquePtr in main but it now is only an empty 
  shell which does not contain an object to manage.
  */