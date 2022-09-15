// @Date: 2022.7.31
// @Episode: 55
// @Desciption: C++ 宏


// #：
// 预处理阶段
// 纯文本替换，其实没有什么东西是不能被替换的，因为是在编译之前

// NOTICE:
// 不要用太多C++特性
// 尤其是当我们进入更高级的特性时，会让第一次看我们代码的人比较难看懂
// 不要向每个人炫耀你懂所有的C++特性

#include <iostream>

#define PR_DEBUG 0

#define PRINT std::cout << "Hello" << std::endl
#define LOG(x) std::cout << x << std::endl


// #ifdef PR_DEBUG     // 这样写其实是一个不好的习惯，可以给其定义赋值，而不是只定义
#if PR_DEBUG == 1
#define LOG_debug(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG_debug(x)
#else
#define LOG_debug(x)
#endif

// 当我们定义PR_DEBUG等于1，有一个好处就是 我们只需要切换其值就能切换状态，而不需要删除定义

int main()
{
    PRINT;  // 替换成std::cout << "Hello" << std::endl，发生在预处理阶段

    // 尽量不要写上面这种代码
    // 如果PRINT定义在另一个文件里，其他人看的时候需要去找这到底是什么意思

    // ***************************************************
    // 可以写一些高效有用的，例如
    // case1
    LOG("Hello LOG");


    // case2
    // 当我们要在系统中做个日志系统
    // 在debug mode中在控制台打印很多信息
    // 但不想在release mode打印过多信息
    
    // 在VS编辑器中
    // 我们需要在两个模式下的预处理器(preprocessor)中做一个宏定义
    // 比如 PR_DEBUG和PR_RELEASE
    LOG_debug("Debugging");


    // 更多例子
    // 如操作字符串，插入很多内置的预定义符号
    // 你可以用反斜杠写多行宏定义
}