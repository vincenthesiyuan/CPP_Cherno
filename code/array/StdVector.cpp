// @Date: 2022.7.26
// @Episode: 47
// @Desciption: C++ 动态数组

// 如果要调整vector大小，例如扩容
// 需要复制整段数据，重新分配到新的连续內存空间中

#include <iostream>
#include <vector>

struct Vector
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, Vector v)
{
    stream << v.x << ", " << v.y << ", " << v.z;
    return stream;
}

void Func(const std::vector<Vector>& v)   // 记得用引用
{}

int main()
{
    std::vector<Vector> vertices;
    vertices.push_back({ 1, 2, 3 });
    vertices.push_back({ 3, 2, 3 });

    // for (Vector v : vectices)    // 这么写会每次都做复制，要用引用
    for (const Vector& v : vertices)
    {
        std::cout << v << std::endl;
    }

    // 如果想全部清除
    // vertices.clear();

    // 如果想清除某个Vector
    vertices.erase(vertices.begin() + 1);
}