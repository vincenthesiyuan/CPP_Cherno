// @Date: 2022.7.23
// @Episode: 43
// @Desciption: C++ 栈作用域生存期

#include <iostream>

class Entity
{
private:
    int x;
public:
    Entity()
    {
        this->x = 2;
        std::cout << "create Entity" << std::endl;
    }

    int GetX()
    {
        return this->x;
    }

    ~Entity()
    {
        std::cout << "destroy Entity" << std::endl;
    }

};


class ScopedPointer
{
private:
    Entity* m_Ptr;

public:
    ScopedPointer(Entity* ptr)
        : m_Ptr(ptr) { }
    
    ~ScopedPointer()
    {
        delete m_Ptr;
    }
};


int main()
{
    {
        ScopedPointer e = new Entity();  // 隐式转换  
    }

    {
        Entity* e1 = new Entity();
        std::cout << e1->GetX() << std::endl;
    }
}