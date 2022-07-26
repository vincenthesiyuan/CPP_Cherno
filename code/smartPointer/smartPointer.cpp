// @Date: 2022.7.24
// @Episode: 44
// @Desciption: C++ 智能指针

#include <iostream>
#include <memory>

// unique_ptr
// 作用域智能指针，超过作用域自动销毁
// 你不能复制unique_ptr，是唯一的
// 如果你复制了两个unique_ptr （1，2），这两个指针同时指向一个內存空间
// 如果2被销毁了，这个內存空间就会释放，另一个指针指向一段內存泄露的內存空间

class Entity
{
private:
    int x;
public:
    Entity()
    {
        this->x = 2;
        std::cout << "create Entity" << std::endl;
    }

    int GetX()
    {
        return this->x;
    }

    ~Entity()
    {
        std::cout << "destroy Entity" << std::endl;
    }
};

int main()
{
    {
        std::unique_ptr<Entity> e(new Entity());
        // 你不能
        // std::unique_ptr<Entity> e = new Entity();
        // 因为 unique_ptr构造函数是 explicit   

        // 更好的方式
        // 如果构造函数碰巧抛出异常，他会稍微安全一些
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
        std::cout << entity->GetX() << std::endl;
        
        // 你不能复制你的unique_ptr
        // std::unique_ptr<Entity> e0 = e;

        // 如果你想共享你的指针
        // 请用shared_ptr
    }

    {
        // shared_ptr在不同的编译器中会有不同的动作
        // 但实际上都是使用 引用计数
        // make_shared除了帮助做 new Entity, 还会开辟一段小內存空间用于做控制器（做引用计数）
        // make_shared
        std::shared_ptr<Entity> se;
        {
            std::shared_ptr<Entity> se1 = std::make_shared<Entity>();
            se = se1;
        }

        // weak_ptr
        // 你可以shared你的指针
        // 但他不会做引用计数
        // 你可以去询问weak_ptr还是否有效

        // 先考虑unique_ptr
        // 需要share，再考虑shared_ptr
    }
}