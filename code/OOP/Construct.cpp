// @Date: 2022.7.17
// @Episode: 25
// @Desciption: C++ 构造函数

#include <iostream>

class Entity
{
public:
    // Entity()
    // {
    //     std::cout << "Construcing" << std::endl;
    // }

    // if you dont want to use the default construct function
    // you can do this:
    Entity() = delete;


    static void Printer()
    {
        std::cout << "Printing" << std::endl;
    }
};


int main()
{
    // if you only call the static function from class, 
    // the construct function don't be called.
    // this case will output "Printing", but have no "Construcing".
    Entity::Printer();   



    // 移动构造
    // 复制构造


}