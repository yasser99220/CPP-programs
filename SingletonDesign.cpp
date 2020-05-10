#include <iostream>
using namespace std;
class Singleton;
class Singleton
{
private:
    Singleton()
    {
        m_Value = 99;
    };
    static Singleton *instance;
    Singleton(const Singleton &) = delete;
    int m_Value;

public:
    ~Singleton()
    {
        cout << "destroyed " << endl;
    }
    int getValue()
    {
        return m_Value;
    }
    static Singleton *getInstance(void)
    {
        if (!instance)
            instance = new Singleton;
        return instance;
    }
};

Singleton *Singleton::instance = nullptr; // instantiate a static variable

int main()
{
    Singleton *obj = Singleton::getInstance();
    cout << hex;
    cout << "first obj call " << obj << " " << obj->getValue() << endl;
    obj = Singleton::getInstance();
    cout << "second obj call " << obj << " " << obj->getValue() << endl;

    return EXIT_SUCCESS;
}