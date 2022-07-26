#include <iostream>

// global
// int s_Variable = 5;

// extern
extern int s_Variable;

struct Entity
{
    int x, y;   // default public

    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

void Function()
{
    static int i = 1;
    std::cout << i << std::endl;
    i++;
}

int main()
{
    // std::cout << s_Variable << std::endl;
    // Entity e;
    // e.x = 1;
    // e.y = 2;

    // Entity e1 = {5, 8};

    // e.Print();
    // e1.Print();
    
    Function();
    Function();
    Function();
    Function();
    Function();

}

