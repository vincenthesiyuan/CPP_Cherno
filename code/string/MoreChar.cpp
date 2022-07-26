// @Date: 2022.7.19
// @Episode: 33
// @Desciption: C++ 字符串字面量

#include <iostream>
#include <stdlib.h>
#include <string>


int main()
{
    using namespace std::string_literals;  // C++14新特性

    // inline std::string std::literals::string_literals::operator ""s(const char *__str, std::size_t __len)
    std::string ss_name = "Cherno"s + " Hello";  // "Cherno"后加s

    // 不转义
    // const char* test = R"(Line1
    //     Line2
    //     Line3)";

    // std::cout << test << std::endl;

    // const char* name = u8"Cherno";
    // char name1[7] = "Cherno";

    // const wchar_t* w_name = L"Cherno";
    // const char16_t* s_name = u"Cherno";    // utf-16
    // const char32_t* t_name = U"Cherno";    // utf-32

    // std::cout << name1 << std::endl;
    // std::cout << strlen(name1) << std::endl;

    char name[] = "Cherno";
    name[2] = 'A';   // 如果没写这句，上面的name会直接指向常量內存区的指针
    std::cout << *(name + 2) << std::endl;


}

