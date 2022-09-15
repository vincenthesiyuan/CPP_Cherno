// @Date: 2022.8.2
// @Episode: 57
// @Desciption: C++ 静态数组

/**
 * 这里比较了 标准库里的静态数组std::array和C风格的静态数组
 * 
 * std::array支持
 *  .size()
 *  .sort()
 * 还有很多迭代器操作
 * 还有边界检查（C风格的静态数组没有），在DEBUG mode才有
 * 
 * 
 * 问题：
 *  std::vector是在堆上创建底层数据结构吗？
 * 
 */ 

#include <iostream>
#include <array>

template <typename T, unsigned long N>
void PrintArray(const std::array<T, N>& data)   // 当我们不知道静态数组的长度
{
    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << std::endl;
    }
}


int main()
{
    std::array<int, 5> data;   // data.size()实际上不存储一个size变量，调用size()是直接返回定义上的5
    data[0] = 1;
    data[1] = 2;
    data[2] = 2;
    data[3] = 2;
    data[4] = 2;

    PrintArray(data);

}