// @Date: 2022.7.17
// @Episode: 30
// @Desciption: C++ 可见性

// 谁能看到它们，谁能调用它们，谁能使用它们
// public, private, protected

// 对于private, 只能"Only*"当前类中访问
// 除非与其声明为friend(友元), 其关键字声明的函数或类可以访问它friend类中的私有成员

// protected
// 其当前类和层次结构中所有子类中可以访问protected声明的成员

#include <iostream>

class Entity
{
protected:
    int X, Y;

public:
    Entity()
    {
        X = 0;
        Y = 1;
    }
};


class Player : public Entity
{
public:
    int p_X, p_Y;

    Player()
    {
        p_X = X + 1;
        p_Y=  Y + 2;
    }
};

class VIPPlayer : public Player
{
public:
    int v_X, v_Y;

    VIPPlayer()
    {
        v_X = X;
        v_Y = Y;
    }
};

class Other
{
public:
    int o_X, o_Y;

    Other()
    {
        o_X = 1;
        o_Y = 2;
    }

};

int main()
{
    // Entity e;
    // e.X = 2;    // protected成员，只能在类内或层次结构中的子类内访问
    // e.Y = 1;

    VIPPlayer* p = new VIPPlayer();
    std::cout << p->v_X << ", " << p->v_Y << std::endl;
    std::cout << p->p_X << ", " << p->p_Y << std::endl;

    VIPPlayer pp;
    std::cout << "VIPPlayer printing: " << std::endl;
    std::cout << pp.v_X << ", " << pp.v_Y << std::endl;
    std::cout << pp.p_X << ", " << pp.p_Y << std::endl;


    Other p1;
    std::cout << p1.o_X << ", " << p1.o_Y << std::endl;
}