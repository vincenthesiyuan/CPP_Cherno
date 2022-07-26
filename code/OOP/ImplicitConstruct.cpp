// @Date: 2022.7.22
// @Episode: 40
// @Desciption: C++ 隐式转换和explicit关键字


#include <iostream>
#include <string>


class Entity
{
private:
    std::string e_Name;
    int e_Age;
public:
    Entity(const std::string& name)
        : e_Name(name), e_Age(-1) 
    {
        std::cout << e_Name << ", " << e_Age << std::endl;
    }
    
    Entity(const int& age)
        : e_Name("Unknown"), e_Age(age)
    {
        std::cout << e_Name << ", " << e_Age << std::endl;
    }

    // 可以用explict关键字来声明构造函数
    // 用于禁用构造函数的隐式转换
};

void PrintEntity(const Entity& e) {}

int main()
{
    // C++ 会自动做一次隐式转换
    PrintEntity(22);

    // PrintEntity("Hello");  // fail
    // 因为"Hello"是 const char*, 不是std::string
    // 这里需要先转换成 std::string，然后再转换成Entity(const std::string&)
    // 用了两次转换，所以不work

    Entity a = 23;

    // 尽量避免使用
}