// @Date: 2022.7.26
// @Episode: 48
// @Desciption: C++ 动态数组（std::vector）的优化

/**
 * 优化的一个重要准则就是
 * 
 * 你要了解你的环境，意思是 - 事情是如何运作的，我该怎么做，应该会发生什么
 */ 


// 针对std::vector
// 我们需要知道复制是什么时候发生，为什么会发生

#include <iostream>
#include <vector>

struct Vector
{
    float x, y, z;

    Vector(float v_x, float v_y, float v_z)
        :x(v_x), y(v_y), z(v_z)
    {

    }

    Vector(const Vector& v)
        :x(v.x), y(v.y), z(v.z)
    {
        std::cout << "Copied" << std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream, Vector v)
{
    stream << v.x << ", " << v.y << ", " << v.z;
    return stream;
}

int main()
{
    std::vector<Vector> vertices;
    // vertices.push_back(Vector(1, 2, 3));
    // vertices.push_back(Vector(4, 2, 3));
    // vertices.push_back(Vector(5, 2, 3));

    // 这里的优化策略
    // 上面代码一共做了6次复制操作
    // 1是需要从main的栈区复制Vector到std::vector的內存中
    // 2是std::vector一共扩容了两次，两次都需要把原先的Vector再拷贝到新的內存空间中

    vertices.reserve(3);   // 我们可以告诉它 直接留出三块连续的Vector大小的內存空间，不需要每次都扩容
    vertices.emplace_back(1, 2, 3);
    vertices.emplace_back(4, 2, 3);
    vertices.emplace_back(5, 2, 3);
    

}