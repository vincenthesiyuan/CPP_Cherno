// @Date: 2022.7.29
// @Episode: 53
// @Desciption: C++ 模板

/**
 * 模板有点像 宏
 * 
 * 模板允许你定义一个可以根据你的用途进行编译的模板
 * 你可以让编译器为你写代码（基于你给编译器的规则）
 * 
 * 
 * 
 * 
 */ 

#include <iostream>
#include <string>

class Entity
{
private:
    int m_X;

public:
    Entity(int x)
        :m_X(x) { }
    
    int GetX()
    {
        return m_X;
    }
    
};

std::ostream& operator<<(std::ostream& stream, Entity& e)
{
    stream << e.GetX();
    return stream;
}

// ********** template cases **********

template <typename T>
void Printer(T value)   // 这个函数只用在调用的时候才会被真正的创建
{
    std::cout << value << std::endl;
}

template <typename T, int N>
class Array
{
private:
    T array[N];

public:
    int GetSize() const { return N; }
};


// ********** template cases **********


int main()
{
    // Entity e(9);
    // Printer(5);
    // Printer<int>(6);
    // Printer("Hello");
    // Printer(5.5f);
    // Printer(e);

    Array<std::string, 10> a;
    std::cout << a.GetSize() << std::endl;

}