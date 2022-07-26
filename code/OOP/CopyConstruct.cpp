// @Date: 2022.7.24
// @Episode: 45
// @Desciption: C++ 拷贝构造

// 理解它是如何工作的
// 如何避免让它工作

// 理解什么时候想去复制
// 什么时候不想复制

#include <iostream>
#include <string.h>

// 这里写一个字符串类
// 使其有复制性
class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];     // 记得用完要delete，不然会內存泄露
        mempcpy(m_Buffer, string, m_Size + 1);    
    }

    String(const String& other)  // 拷贝构造，参数为当前类的引用，深拷贝
        : m_Size(other.m_Size)
    {
        std::cout << "Copied String" << std::endl;
        // memcpy(this, &other, sizeof(String));
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }

    ~String()
    {
        delete[] m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

void PrintFunc(const String& string)
{
    std::cout << string << std::endl;
}

/** 理解深浅拷贝
 */ 


int main()
{
    String s("Cherno");
    String b = s;

    b[2] = 'B';
    // std::cout << s << std::endl;
    // std::cout << b << std::endl;
    PrintFunc(b);
    PrintFunc(s);
}