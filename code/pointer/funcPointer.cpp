// @Date: 2022.8.3
// @Episode: 58
// @Desciption: C++ 函数指针


#include <iostream>
#include <vector>

void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

void HelloWorld_2(int value)
{
    std::cout << "Hello World Value: " << value << std::endl;
}

// ################## case 2 ######################
void PrintValue(int value)
{
    std::cout << value << std::endl;
}

void ForEach(const std::vector<int>& array, void(*function)(int))
{
    for (const int num : array)
        function(num);
}



int main()
{
    auto function = HelloWorld;
    function();

    void(*func)() = HelloWorld;
    func();

    // Cherno更习惯的方式是使用 typedef 或者 using 来使用函数指针
    typedef void(*HelloWorldFunction)(int);    
    HelloWorldFunction func2 = HelloWorld_2;
    func2(2);
    func2(3);


    // ################## case 2 ######################
    std::cout << "case 2" << std::endl;
    
    // 非常酷，我们可以告诉一个函数让它做某些动作
    std::vector<int> array = { 1, 2, 3, 5 };
    ForEach(array, PrintValue); 

    // 其实我们可以使用lambda来代替PrintValue，不需要额外声明一个PrintValue函数
    // 用完即弃
    // 这里的[]称为 capture method，详情查看 https://en.cppreference.com/w/cpp/language/lambda#Lambda_capture
    ForEach(array, [](int value){ std::cout << value << std::endl; });


    // 还有很多关于函数指针的内容
    // 除了lambda
    // 还会有 标准库里的function, bind等等
    // 原始的C函数指针 void(* )()
    
} 