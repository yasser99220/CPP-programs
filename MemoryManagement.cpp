#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <set>
#include <map>
using namespace std;

struct MemoryAllocated
{
    uint32_t totalAlloc;
    uint32_t totalFree;

    void printUsage(void)
    {
        cout << "memory used " << totalAlloc - totalFree;
    }
};

static struct MemoryAllocated s_MemoryAllocated = {0, 0};

void *operator new[](size_t t)
{
    s_MemoryAllocated.totalAlloc += t;
    cout << "memory allocated " << t;
    return malloc(t);
}

bool comparator(int x, int y)
{
    return x > y;
}

void operator delete(void *memory, size_t t)
{
    free(memory);
    s_MemoryAllocated.totalFree += t;
    cout << "freed memory" << t << endl;
}

void vectorDemo(void)
{
    vector<int> testvector = {5, 3, 2, 4, 1, 9};
    testvector.push_back(100);
    testvector.push_back(100);
    testvector.push_back(100);
    binary_search(testvector.begin(), testvector.end(), 2); // binary search

    sort(testvector.begin(), testvector.end()); // merge sort

    vector<int>::iterator it = lower_bound(testvector.begin(), testvector.end(), 100); // iterator to the index first occurrence of  >= target

    auto it1 = upper_bound(testvector.begin(), testvector.end(), 100); // iterator to the index first occurrence of >(strictly) target

    // it2 - it (upper - lower) will give no of occurrence of target

    sort(testvector.begin(), testvector.end(), comparator); // comparator function to decide he order of sort. x>y i.e descending order

    for (int &x : testvector)
    {
        ++x;
        cout << x << " ";
    }
    cout << endl;
}

void demoSets(void)
{
    set<int> t1; // sorted and inserted
    t1.insert(5);
    t1.insert(1);
    t1.insert(8);

    auto it = t1.find(4);
    t1.lower_bound(1); // already exposed
    t1.upper_bound(3);

    for (int x : t1)
        cout << x << " ";
}

void demoMAP(void)
{
    map<int, int> maps;
    maps[1] = 3;
    maps[2] = 4;
    maps[5] = 1;

    map<char, int> cmaps;
    string x = "mohammed yasser";

    for (char c : x)
        cmaps[c]++;

    cout << cmaps['a'] << " " << cmaps['m'];
}

typedef unsigned long long int ull;
#include <map>

map<ull, bool> PrimeMap;
bool isPrime(ull &num)
{
    if (PrimeMap[num])
    {
        return true;
    }

    if (num == 3 || num == 2)
        return true;

    for (ull i = 3; i <= num / 2; i += 2)
    {
        if (num % i == 0)
            return false;
    }

    PrimeMap[num] = true;
    return true;
}

void projectEuler9(ull num)
{
    // precompute all relevant prime numbers
    std::vector<ull> primes;
    // the only even prime
    primes.push_back(2);
    // now check all odd numbers for primality
    for (ull i = 3; i <= num; i += 2)
    {
        bool isPrime = true;
        for (auto p : primes)
        {
            // no larger prime factor possible ?
            if (p * p > i)
                break;

            // no prime number ?
            if (i % p == 0)
            {
                isPrime = false;
                break;
            }
        }

        // yes, we have a new prime
        if (isPrime)
            primes.push_back(i);
    }

    // prime numbers were found in ascending order,
    // let's add their value and store in a map such that
    // [prime number] => [sum of all prime numbers up to the current]
    // note: long long is required to avoid overflows
    std::map<unsigned int, unsigned long long> sums;
    unsigned long long sum = 0;
    for (auto p : primes)
    {
        sum += p;
        sums[p] = sum;
    }
    cout << sum;
}

using namespace std;
int main()
{
    projectEuler9(2000000);
    //cout << "ANDing integer 'a' with 'true' :" << a && true;
    return 0;
}

// int main()
// {
//     // s_MemoryAllocated.printUsage();
//     // int *test = new int;
//     // //std::unique_ptr<int *> testunique = make_unique<int>;
//     // s_MemoryAllocated.printUsage();
// }