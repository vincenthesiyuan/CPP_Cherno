// @Date: 2022.8.11
// @Episode: 59
// @Desciption: C++ lambda

// 构造一个延迟调用的函数

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


void ForEach(const std::vector<int>& array, const std::function<void(int)>& func)
{
    for (const int& num : array)
    {
        func(num);
    }
}

int main()
{
    // ########### case1 ###########
    std::vector<int> array = { 1, 2, 3, 5, 2, 3 };
    // 尝试去找到 value > 4 的值
    auto it = std::find_if(array.begin(), array.end(), [](int value) { return value > 4; });
    std::cout << *it << std::endl;


    // ########### case2 ###########
    // 尝试将外部变量注入到lambda表达式中实现 延迟调用
    // 善用 capture
    int a = 3;
    // ForEach(array, [=](int value) { std::cout << a + value << std::endl; });
    ForEach(array, [&](int value) mutable { a = 2; std::cout << a + value << std::endl; });
    std::cout << a << std::endl;



}