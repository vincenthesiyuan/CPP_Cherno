// @Date: 2022.7.31
// @Episode: 56
// @Desciption: C++ auto关键字


// 几个auto合适的应用场景
// 1 - 非常长的复合类型名
// 2 - foreach loop

#include <iostream>
#include <vector>

class Example
{
private:
    int x, y;

public:
    Example(int e_x, int e_y)
        :x(e_x), y(e_y) { }

    int GetX() const
    {
        return x;
    }

    int GetY() const 
    {
        return y;
    }
};

std::ostream& operator<<(std::ostream& stream, Example e)
{
    stream << e.GetX() << ", " << e.GetY();
    return stream;
}

int main()
{
    std::vector<Example> ExampleVec;
    ExampleVec.reserve(3);

    ExampleVec.emplace_back(1, 2);
    ExampleVec.emplace_back(2, 2);
    ExampleVec.emplace_back(3, 2);

    for (const auto& e : ExampleVec)
    {
        std::cout << e << std::endl;
    }
    
    
}