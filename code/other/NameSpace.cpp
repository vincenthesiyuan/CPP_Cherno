// @Date: 2022.8.11
// @Episode: 60-61
// @Desciption: 
//    60. 为什么不用 using namespace std
//    61. C++ 的命名空间

// 容易产生误会
// 不要在头文件中使用 using namespace

// 不用的好处（指的是不用using 标准库namespace）
// 1 - 每次都能知道自己调用的函数或者变量是属于哪个命名空间的，增强可读性
// 2 - 不容易产生错误，如下例子

// 而对于namespace本身
// 主要使用的原因就是 避免在不同上下文中使用相同的符号而引起冲突

// 在C语言体系中，
// 没有namespace的概念，对于不同的库，比如OpenGL
// 定义init函数的命名规则一般为 glInit()
// 库名放在前面，使得不和其他init函数起冲突

// 当我们开始写一个库
// 全部的代码都会放在一个命名空间中，这里就可以随意去定义符号而不和其他库起冲突

#include <iostream>
#include <string>
#include <algorithm>


namespace apple
{
    void print(const std::string& text)
    {
        std::cout << text << std::endl; 
    }
}

namespace orange
{
    void print(const char* text)
    {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

using namespace apple;
using namespace orange;

int main()
{
    const char* text = "Hello";
    print(text);     // 这里会调用 orange::print()
    apple::print(text);

    // 也可以局部using命名空间的某一个符号
    // 尽量在一个小的范围使用 using namespace
    using apple::print;
    print(std::string("Nihao Apple"));
}