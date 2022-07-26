// @Date: 2022.7.17
// @Episode: 29
// @Desciption: C++ 纯虚函数

#include <iostream>
#include <string>

class Printable
{
public:
    virtual std::string GetClassName() = 0;   // 纯虚函数
};

class Entity : public Printable
{
public:
    std::string GetClassName() override { return "Entity"; }
};


int main()
{
    Entity* e = new Entity();
    std::cout << e->GetClassName() << std::endl;
}
