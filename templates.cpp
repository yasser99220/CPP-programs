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
}