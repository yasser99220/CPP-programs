#include <iostream>
using namespace std;
template <typename T> // tempalate <class T>
void Print(T value)
{
    cout << value << endl;
}
template <typename T, int N>

class Array
{
private:
    T m_Array[N];

public:
    int getSize(void) const
    {
        return N;
    };
};

int main() // templates examples
{
    Print<int>(5);
    Print(5.5f);
    Print("hello ");
    Array<int, 5> array;
    cout << array.getSize();
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
template <class T>
class AddElements
{
    T element;

public:
    AddElements(T arg) { element = arg; }
    T add(T arg) { return arg + element; }
};
template <>
class AddElements<string>
{
    string element;

public:
    AddElements(string arg) { element = arg; }
    string concatenate(string s1)
    {
        return element.append(s1);
    }
};

/*Write the class AddElements here*/

int main()
{
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        string type;
        cin >> type;
        if (type == "float")
        {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int")
        {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string")
        {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
