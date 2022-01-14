#include <iostream>
using namespace std;
class base
{
public:
    base()
    {
        cout << "base constructor" << endl;
    }
    virtual ~base()
    {
        cout << "base destructor" << endl;
    }
};

class derivelevel1 : public base
{
public:
    derivelevel1()
    {
        cout << "derivelevel1 constructor" << endl;
    }

    ~derivelevel1()
    {
        cout << "derivelevel1 destructor" << endl;
    }
};

class derivelevel2 : public derivelevel1
{
public:
    derivelevel2()
    {
        cout << "derivelevel2 constructor" << endl;
    }

    ~derivelevel2()
    {
        cout << "derivelevel2 destructor" << endl;
    }
};

int main()
{

    string s = "The Daily Byte";
    int j = s.length() - 1;
    for (int i = 0; i < j; ++i, --j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    cout << s << endl;

    //base *bp = new derivelevel2();
    //delete bp;
    return 0;
}