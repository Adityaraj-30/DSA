#include <iostream>

#define LOG(x) std::cout << x << std::endl

int main()
{
    int var =8;
    int* ptr = &var;
    LOG(*ptr);
    *ptr = 10;
    LOG(var);
  
}

/*
& ---> Address of operator
* ---> Dereference of operator
*/