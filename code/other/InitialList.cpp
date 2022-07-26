// @Date: 2022.7.22
// @Episode: 36
// @Desciption: C++ 成员初始化列表


// 成员初始化列表不只是代码风格的区别
// 1 - 可以让构造函数更加清晰，不用写一堆初始化代码在构造函数中
// 2 - 可以避免成员类变量重复创建

#include <iostream>

class Example
{

public:
    Example()
    {
        std::cout << "new Example entity" << std::endl;
    }

    Example(int num)
    {
        std::cout << "new Example entity with "<< num << std::endl;
    }
};


class Entity
{
private:
    Example example;

public:
    // 这么初始化会 对Example类做了两次创建
    // Entity()
    // {
    //     example = Example(8);
    // }

    Entity()
        : example(Example(8))
    {

    }
};


int main()
{
    Entity e;
}