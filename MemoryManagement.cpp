#include <iostream>
#include <memory>
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

void operator delete(void *memory, size_t t)
{
    free(memory);
    s_MemoryAllocated.totalFree += t;
    cout << "freed memory" << t << endl;
}

int main()
{
    s_MemoryAllocated.printUsage();
    int *test = new int;
    s_MemoryAllocated.printUsage();
}