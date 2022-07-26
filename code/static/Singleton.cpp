#include <iostream>

// class Singleton
// {
// private:
//     static Singleton* s_Instance;

// public:
//     static Singleton& Get() {
//         return *s_Instance;
//     }

//     void Hello() { std::cout << "Hello" << std::endl; }
// };

// Singleton* Singleton::s_Instance = nullptr;

class Singleton
{
public:
    static Singleton& Get()
    {
        static Singleton s_Instance;
        return s_Instance;
    }

    void Hello() { std::cout << "Hello" << std::endl; }
};

int main()
{
    Singleton::Get().Hello();
}