#include <iostream>

enum ExampleChar : unsigned char
{
    CA = 5,  
    CB,    // 6
    CC,    // 7
};

// must be Integar
enum Example
{
    A,    // 0
    B,    // 1
    C,    // 2
};

// global variable
int a = 0;
int b = 6;
int c = 2;

int main()
{ 
    Example value = A;
    ExampleChar cvalue = CB;

    if (value == a) 
    {
        std::cout << "Int: " << value << std::endl;
    }

    if (cvalue == b) 
    {
        std::cout << "Unsigned Char: " << cvalue << std::endl;
    }
    
}