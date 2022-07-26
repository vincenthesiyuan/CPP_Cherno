// @Date: 2022.7.19
// @Episode: 32
// @Desciption: C++ 字符串

// std::string
// BasicString模板类的模板特化

// Wstring 宽字符

#include <iostream>
#include <string>

void PrintString(const std::string& name)   // 字符串只读，做操作时最好 const修饰，记得传引用
{
    std::cout << name << ", Hello" << std::endl;
}

int main()
{
    const char* name = "Cherno";    // "Cherno" 双引号中的实际上是一个 const char*
    std::cout << name << std::endl;

    std::string s_name = "Cherno";
    // std::string s_name = "Cherno" + "Hello";    fail
    // 因为你不能把两个 const char* 指针加起来
    // 但std::string可以
    s_name += "Hello";
    std::cout << s_name << std::endl;

    PrintString(s_name);

}