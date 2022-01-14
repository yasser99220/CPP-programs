#include <iostream>
#include <functional>
#include <string>

class St
{
public:
    void func(void (*lambda)())
    {
        lambda();
    }
    void divide(double (*div)(double a, double b))
    {
        std::cout << div(9, 3);
    }
};

void test(std::function<bool(std::string &)> t) // standard functions.
{                                               // will accept functors, function pointers , and lambdas.
    std::string str = "yoo";
    std::cout << t(str);
}

int main()
{

    auto testing = [](std::string &st) -> bool
    {
        return st.size() == 3;
    };
    test(testing);

    auto lambda = []()
    { std::cout << "hello" << std::endl; };
    St s;
    s.func([]()
           { std::cout << "hello" << std::endl; });

    auto result = [lambda](double a, double b) mutable -> double
    {
        lambda();
        if (b == 0)
            return 0;
        return a / b;
    };

    std::cout << result(10.0, 5.0) << "\n";

    s.divide(result);
}