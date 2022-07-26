// @Date: 2022.7.22
// @Episode: 35
// @Desciption: C++ mutable

// 应用场景
// 1 - 用在类中的const方法
// 2 - 用在 lambda语句中

#include <iostream>

int main()
{
    int x = 6;
    auto f = [&]()
    {
        // int y = x;
        // y++;
        x++;
        // std::cout << y << std::endl;
        std::cout << x << std::endl;
    };
    
    f();
    std::cout << x << std::endl;

    auto m = [=]() mutable
    {
        x++;
        std::cout << x << std::endl;
    };

    m();


}