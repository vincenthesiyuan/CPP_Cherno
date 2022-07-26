// @Date: 2022.7.23
// @Episode: 42
// @Desciption: C++ this

#include <iostream>

class Entity
{
private:
    int x, y, z;

public:
    void Set(const int& x, const int& y)
    {
        this->x = x;
        this->y = y;

        // 做逆向引用
        Entity& e = *this;
        e.z = this->x + this->y;
    }

    int GetZ() const
    {
        return this->z;
    }
};

void Printer(const Entity& e)
{
    std::cout << e.GetZ() << std::endl;
}

int main()
{
    Entity e;
    e.Set(1, 2);

    Printer(e);
}