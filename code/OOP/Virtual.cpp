// @Date: 2022.7.17
// @Episode: 28
// @Desciption: C++虚函数

#include <iostream>
#include <string>

class Entity
{
public:
    virtual std::string GetName() { return "Entity"; }  // virtual function
};

class Player : public Entity
{
private:
    std::string Name;

public:
    Player(const std::string& name)
        : Name(name) {}

    // std::string GetName() override { return Name; }
};


// virtual function 引入了一种 dynamic dispatch(动态联编)
// 通过虚函数表来实现编译
// 其包含了基类所有虚函数的映射
// 将它们映射到正确的override函数

// 虚函数有一定的开销
// 有两种与虚函数相关的运行成本
// 1 - 需要额外的內存来存储虚函数表，这样我们可以分配到正确的函数。基类中会有一个成员指针指向虚函数表。
// 2 - 当我们调用虚函数时，需要遍历整个表来确定要映射到哪个函数，这是额外的性能损失。（嵌入式平台可能会注意）

// 实际上，其性能影响还是非常小的。



void PrintFunc(Entity* e)
{
    std::cout << e->GetName() << std::endl;
}


int main()
{
    Entity* e = new Entity();
    Player* player = new Player("Cherno");

    PrintFunc(e);
    PrintFunc(player);

    // Entity* e1 = player;
    // PrintFunc(e1);

}