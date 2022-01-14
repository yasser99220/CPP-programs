#include <iostream>
#include <typeinfo>
using namespace std;

template <class T, class S>
auto Test3(T t, S s) -> decltype(t + s)
{
    return t + s;
}

auto Test2(int T) -> decltype(T)
{
    return T;
}

auto Test()
{
    return 5;
}

int main()
{
    auto varInt = 7; // no need to specify the data type as it takes the data type during intialisation
    // cout << Test2(6) << endl;
    cout << Test3(2, 3) << endl;
    string value;
    cout << typeid(value).name() << endl; // name mangled string type
    decltype(value) dectypeVar = "tatti"; // declaration type
    cout << dectypeVar << endl;
    // this is exactly we do when we use auto and this helps to create a variable with same type as
    // previous variable.
}

namespace A
{

    int var = 10;
}
namespace B
{
    int cout = 5;
}
int main2()
{
    using namespace B;
    //
    std::cout << 2 % 1 << endl;
}
