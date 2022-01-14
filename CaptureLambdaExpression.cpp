#include <iostream>

class Test
{
public:
    Test() = default;
    void lambda()
    {
        auto plambda = [this]() // lambdas dont have access to variables
        {                       // they have their own scope
            a = 4;              // this captures the variables by ref
            b = 5;
        };
    }

private:
    int a{1};
    int b{2};
};

int main()
{
    int a = 1, b = 2, c = 3;

    [a]() mutable // mutable keyword allows to modify the copy of the variables
    { a = 5;
        std::cout << "poop " << std::endl; }();
    // all variables captured by value
    [=]()
    { std::cout << "poop " << a << " " << b << std::endl; }();

    // capture all variables by reference
    [&]()
    { c = 6;
    std::cout << "poop " << std::endl; }();

    // all are captured by ref but c is by value
    [=, &c]()
    { c = 5;
        std::cout << "poop " << std::endl; }();

    std::cout << c << std::endl;

    std::cout << (4 - 3) / 2 << "-Land" << std::endl;
}