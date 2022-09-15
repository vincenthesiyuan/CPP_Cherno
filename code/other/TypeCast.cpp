// @Date: 2022.8.15
// @Episode: 66
// @Desciption: 类型双关

// 简单来说
// 当你拥有一段內存，你可以当作不同类型的內存对待
// 我们需要做的就是将该类型作为指针，然后将其转换为另一个类型的指针
// 然后再解引用

#include <iostream>

struct Position
{
    int x, y;
};

int main()
{
    Position e = {5, 8};
    // int* position = (int*)&e;
    // std::cout << position[0] << ", " << *(position + 1) << std::endl;

    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;
}
