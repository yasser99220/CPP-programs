#include <iostream>
#include <vector>
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
int sum(int N)
{
    if (N == 1)
        return 1;
    else
    {
        return N + sum(N - 1);
    }
}
int exponent(int m, int n)
{
    if (n == 0)
        return 1;
    else
    {
        return m * exponent(m, n - 1);
    }
}
int factorial(int N)
{
    if (N == 0 || N == 1)
        return 1;
    else
    {
        return N * factorial(N - 1);
    }
}
int optimizedExponent(int m, int n)
{
    if (n == 0)
        return 1;
    else if (!(n & 1)) // n is even
    {
        return optimizedExponent(m * m, n / 2);
    }
    else
    {
        return m * optimizedExponent(m * m, (n - 1) / 2);
    }
}
double taylor(int x, int n)
{
    static double p = 1, f = 1;

    if (n == 0)
        return 1;

    double r = taylor(x, n - 1);
    p = p * x;
    f = f * n;
    return r + (p / f);
}

int XorOfall(vector<int> &nums, int index)
{
    if (index == 0)
    {
        return nums[0];
    }
    return XorOfall(nums, index - 1) ^ nums[index];
}

int main()
{
    //cout << optimizedExponent(5, 3) << endl;
    vector<int> nums = {2, 5, 6};

    cout << XorOfall(nums, nums.size() - 1) << endl;

    //cout << sum3and5(1000) << endl;
}