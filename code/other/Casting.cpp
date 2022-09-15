// @Date: 2022.9.15
// @Episode: 69
// @Desciption: 类型转换

// 这里讨论强制类型转换

#include <iostream>

int main()
{
    // C style casting
    double value = 5.23;
    double a = (int)value + 5.2;  // truncate to 10

    // C++ style casting
    // 主要有：static_cast, reinterpret_cast, dynamic_cast, const_cast
    // 实际上 static_cast 是语法糖
    // 会做额外的事情使得你的代码慢下来，（一些检查）
    // reinterpret_cast的意思是 把这段內存重新解释成别的东西
    // const_cast 移除或者添加变量的const限定

    // 好处是： 可以帮助我们减少强制转换犯错误，也利用我们代码阅读
    // 阅读代码时可以搜索哪里做了类型转换

    double b = static_cast<int>(value) + 5.2;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    // dynamic_cast与运行时类型信息RTTI(runtime type information)紧密联系
    // 是在运行时做检查
    // 可以很好地知道转换是否成功

    // C++ style casting可以让你的代码更加可靠
    

}