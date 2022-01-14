#include <iostream>
using namespace std;
int fib(int n, int *memo) // fibonacci series using DP and memoisation
{
    if (memo[n] != -1)
        return memo[n];
    int result = 0;

    if (n == 1 || n == 2)
        result = 1;
    else
    {
        result = fib(n - 1, memo) + fib(n - 2, memo);
        memo[n] = result;
        return result;
    }
    return result;
}

int fibBottomUp(const int n)
{
    int memo[6] = {-1}; // size of array should be 1 more than n
    memo[1] = 1;
    memo[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        memo[i] = memo[i - 2] + memo[i - 1];
    }

    return memo[n];
}

long long rowSumOddNumbers(unsigned n)
{
    if (n == 1)
        return 1;
    long long sum = 0;
    int start = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (i == n)
            {
                sum += start;
            }
            start += 2;
        }
    }
    return sum;
}

int fibNormal(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibNormal(n - 1) + fibNormal(n - 2);
}

void reverse(string &s) // 0 1 3 4 5 yasser
{
    if (s.empty())
        return;

    string rs = s.substr(1);
    reverse(rs);
    cout << s[0];
}

int main()
{
    int memo[6] = {-1}; // array to store the repeated results i.e memoisation
    string test = "yasser";
    reverse(test);
    //cout << fibBottomUp(5) << endl;
    // std::cout << fibNormal(5);
    return EXIT_SUCCESS;
}