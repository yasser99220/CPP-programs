// demonstrates the barebone implementation of unique Pointer and how move semantics works for uniquePtr

#include <iostream>
using namespace std;
template <typename T>
class myUnique
{
private:
    T *myUniquePtr{nullptr};

public:
    myUnique() = default; // default constructor
    myUnique(T *ptr) : myUniquePtr(ptr) {}
    ~myUnique()
    {
        delete myUniquePtr; // modern cpp lets you delete nullptr
    }

    myUnique(const myUnique &) = delete;           // delete copy constructor
    myUnique operator=(const myUnique &) = delete; // delete assignment operator

    //transfer ownership
    myUnique(const myUnique &&rhs) : myUniquePtr(rhs.myUniquePtr)
    {
        rhs.myUniquePtr = nullptr;
    }
};