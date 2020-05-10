#include <iostream>
using namespace std;
int fib(int n, int *memo) // fibonacci series using DP and memoisation
{
    if (memo[n] != 0)
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
    int memo[6] = {0}; // size of array should be 1 more than n
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

int main()
{
    int memo[6] = {0}; // array to store the repeated results i.e memoisation

    cout << fib(5, memo) << endl;
    cout << fibBottomUp(5) << endl;
    std::cout << rowSumOddNumbers(3);
    return EXIT_SUCCESS;
}