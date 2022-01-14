#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;
typedef unsigned long long ull;

ull oddSum(ull start, ull stop)
{
    ull sum = 0;

    for (ull i = start; i <= stop; ++i)
    {
        if (i & 1)
        {
            sum += i;
        }
    }
    return sum;
}

ull evenSum(ull start, ull stop)
{
    ull sum = 0;

    for (ull i = start; i <= stop; ++i)
    {
        if (!(i & 1))
        {
            sum += i;
        }
    }
    return sum;
}

int main(int argv, char *argc[])
{
    ull start = 0;
    ull stop = 1900000000;
    auto startTime = high_resolution_clock::now();
    //cout << evenSum(start, stop) << endl;
    //cout << oddSum(start, stop) << endl;

    std::thread t1(evenSum, start, stop);
    std::thread t2(oddSum, start, stop);
    t1.join();
    t2.join();
    auto stopTime = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stopTime - startTime);
    cout << duration.count() / 1000000 << endl;
    return 0;
}
