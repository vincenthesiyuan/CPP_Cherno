// @Date: 2022.7.19
// @Episode: 31
// @Desciption: C++ 数组

/**
 * 本质上，数组就是一段连续的內存空间
 * 
 * Tips:
 *     如果你想返回一个数组，而这个数组是在函数中创建的，
 *     你需要考虑用 new关键字。
 * 
 * 间接寻址：
 *     你有一个指针，这个指针帮你指向一块內存块（比如数组）
 *     这有时候可能会导致 內存碎片、缓存丢失等。(Entity case)
 *     
 * 我们应该在栈上创建数组来避免间接寻址，因为这种內存跳跃会影响性能
 * 
 * 
 */

#include <iostream>
#include <array>

class Entity
{
public:
    int entityExample[5];

    // -------------------
    // static constexpr int size = 5;
    static const int size = 5; 
    int entityExample2[size];

    // -------------------
    // C++11 内置数组
    // std::array
    // 有边界检测、记录数组大小

    // 比原始数组会开销大一些，因为会做边界检查和保存数组大小。
    // 若比较要求安全性，推荐使用。
    // 高手还是会习惯自己维护原始数组，因为性能考虑。
    std::array<int, 5> entityExample3;


   Entity()
    {
        for (int i = 0; i < 5; i++)
        {
            entityExample[i] = 2;
        }
    }
};





void Printer(const int* Array, int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << *(Array + i) << std::endl;
    }
}


int main()
{
    int example[5];
    
    for (int i = 0; i < 5; i++)
    {
        example[i] = 2;
    }

    int* ptr = example;     // int类型指针，后面加的是 int字节大小的偏移量
    *(ptr + 2) = 3;

    *(int*)((char*)ptr + 8) = 1;  // 转成char类型指针，其偏移量8为 字节

    Printer(ptr, 5);

}