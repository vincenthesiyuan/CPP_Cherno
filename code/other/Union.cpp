// @Date: 2022.8.15
// @Episode: 67
// @Desciption: 联合体


// 通常Union都是匿名使用
// 但是匿名Union不能有成员函数

#include <iostream>

struct Union
{
    union
    {
        float x;
        int y;
    };
    
};

// =============== case2 =================

struct Vector2
{
    float x, y;

    // Vector2& GetX()
    // {
    //     return *(Vector2*)&x;
    // }
    
};

struct Vector4
{
    union
    {
        struct
        {
            float x, y, h, w;
        };
        
        struct
        {
            Vector2 a, b;
        };
        
    };
    
};

void PrintVector(const Vector2& vector)
{
    std::cout << vector.x << ", " << vector.y << std::endl;
}


int main()
{
    // Union u;
    // u.y = 2;
    // std::cout << *(int*)&u.x << ", " << u.y << std::endl;

    Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };
    PrintVector(vector.a);
    PrintVector(vector.b);

    std::cout << "===============" << std::endl;

    vector.h = 500.0f;
    PrintVector(vector.a);
    PrintVector(vector.b);



}
