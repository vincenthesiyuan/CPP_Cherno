// @Date: 2022.7.22
// @Episode: 39
// @Desciption: C++ new关键字

#include <iostream>
#include <string>

class Entity
{
private:
    int x_M, y_M;
    std::string check;

public:
    Entity()
    { 
    }

    Entity(std::string c)
        : x_M(1), y_M(2), check(c)
    {
    }

    int GetX() const
    {
        return x_M;
    }
};


int main()
{
    std::string c = "Hello";
    Entity* e = new Entity;

    int* b = new int[20];  // 20*4 bytes

    // 你需要手动释放內存
    delete e;
    delete[] b;

    // 也有很多自动化的策略
    // 如:
    // 1 - 基于作用域的指针
    // 2 - 引用计数


    // 还有一种new操作叫  placement new
    
}