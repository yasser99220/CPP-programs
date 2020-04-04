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

int main()
{
    s_MemoryAllocated.printUsage();
    int *test = new int;
    //std::unique_ptr<int *> testunique = make_unique<int>;
    s_MemoryAllocated.printUsage();
}