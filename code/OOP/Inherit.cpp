// @Date: 2022.7.17
// @Episode: 27
// @Desciption: C++ 继承

#include <iostream>

class Entity
{
public:
    float X, Y;

    void Move(int x, int y)
    {
        X += x;
        Y += y;
    }
};

class Player : public Entity
{
public:
    const char* Name;

    // void setName(const char* name)
    // {
    //     Name = name;
    // }
};

int main()
{
    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;
}