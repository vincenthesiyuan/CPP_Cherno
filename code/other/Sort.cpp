// @Date: 2022.8.15
// @Episode: 65
// @Desciption: C++ 排序

// 数据结构决定了存储方式

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> array = { 2, 3, 1, 6, 5 };
    // std::sort(array.begin(), array.end(), std::greater<int>());
    std::sort(array.begin(), array.end(), [](int a, int b){
        if (a == 1) return false;
        if (b == 1) return true;
        return a < b;
    });  // 这里发comp function的具体细节可以看 cppreference

    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << std::endl;
    }
}