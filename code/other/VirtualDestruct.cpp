// @Date: 2022.8.16
// @Episode: 68
// @Desciption: 虚拟析构函数

// 当我们处理多态的时候，虚拟析构非常重要

#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Construct Base!" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "Destruct Base!" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Construct Derived!" << std::endl;
    }

    ~Derived()
    {
        std::cout << "Destruct Derived!" << std::endl;
    }
};

int main()
{
    Base* base = new Base();
    delete base;

    std::cout << "=========================\n"; 
    Derived* derived = new Derived();
    delete derived;

    std::cout << "=========================\n"; 
    Base* obj = new Derived();
    delete obj;   // 如果父类析构没有virtual，会造成內存泄露，不会析构子类


}