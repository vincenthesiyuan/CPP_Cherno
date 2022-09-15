// @Date: 2022.8.15
// @Episode: 63
// @Desciption: C++ 计时器

// 当你希望事情在特定时间发生
// 或者评估性能或做benchmark

// 几种计时器：
// 1 - C++ std::chrono
// 2 - 特定平台的系统api，例如win32 api的高精度计时器(QueryPerformanceCounter)



// 有很多profiler可以做性能分析
// 对于使用C++，一定是比较在意性能的
// 所以要习惯使用profiler或其他工具来进行性能测试等

#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::_V2::system_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        std::cout << "Starting ..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;

        std::cout << ms << "ms " << std::endl;
    }
    
};


void Function()
{
    Timer timer;
    for (int i = 0; i < 100; i++)
        std::cout << "Hello World\n";
}



int main()
{
    // using namespace std::literals::chrono_literals;

    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);
    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<float> duration = end - start;
    // std::cout << duration.count() << "s " << std::endl;

    // 我们不希望每次都这么写
    // 可以利用 类的生命周期   

    // #######################################
    // case2
    Function();
    
}