#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A constructor called";
    }
    ~A()
    {
        std::cout << "A destructor called";
    }
};

class B: public A
{
    public:
        B()
        {
            std::cout << "B constructor called";
        }
        ~B()
        {
            std::cout << "B destructor called";
        }
};

int main()
{
    A newA;
    B newB;
}