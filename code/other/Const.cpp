// @Date: 2022.7.22
// @Episode: 34
// @Desciption: C++ const

#include <iostream>

class Entity
{
private:
    int *x_M, *y_M;
    mutable int var;

public:
    // Entity()
    // {
    //     *x_M = 1;
    //     *y_M = 2;
    // }

    int* GetX() const
    {
        var = 2;    // mutable可以让这个变量在常量函数中修改
        return x_M;
    }
};


int main()
{
    int b = 10;
    const int* a = new int;   // 限制指针变量a本身的內存地址不变
    a = (int*)&b;             // 改变a的指向

    std::cout << *a << std::endl;

    int* const a1 = new int;   // 限制指针变量a指向的內存地址不变
    *a1 = 2;                   // 可以改变指向的地址中保存的数值


    // const 在类中的应用
    // 定义只读成员函数
    // 比如: int* GetX() const

    Entity e;    
    std::cout << e.GetX() << std::endl;

}