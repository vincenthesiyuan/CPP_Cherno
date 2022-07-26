// @Date: 2022.7.26
// @Episode: 4
// @Desciption: C++ 箭头操作符

#include <iostream>

class Entity
{
private:
    int x;

public:
    Entity() { }

    Entity(int m_x)
        :x(m_x) { }
    
    void PrintEntity()
    {
        std::cout << "Entity x value: " << x << std::endl;
    }
    
    void PrintEntity() const
    {
        std::cout << "const Entity x value: " << x << std::endl;
    }
};

class ScopePointer
{
private:
    Entity* m_Obj;

public:
    ScopePointer(Entity* entity)
        :m_Obj(entity) { }

    ~ScopePointer()
    {
        delete m_Obj;
    }

    Entity* operator->()
    {
        return m_Obj;
    }

    const Entity* operator->() const
    {
        return m_Obj;
    }
};

struct Vector3
{
    float x, y, z;
};



int main()
{
    // *************** case 1 *********************
    ScopePointer e = new Entity();
    e->PrintEntity();

    // *************** case 2 *********************
    // 你可以利用箭头操作符来取得內存的偏移量
    // int offset = (int)&((Vector3*)nullptr)->x;  // fail, but i dont understand
    // std::cout << offset << std::endl;


}
