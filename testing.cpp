#include <iostream>
using namespace std;
int sum3and5(const int &upto)
{
    int sum = 0;
    for (int i = 1; i < upto; ++i)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            sum += i;
        }
    }
    return sum;
}
int main()
{
    cout << sum3and5(1000) << endl;
}