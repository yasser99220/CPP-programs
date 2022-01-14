// demonstrates the barebone implementation of unique Pointer and how move semantics works for uniquePtr

#include <iostream>
#include <memory>
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
class Test
{
public:
    Test()
    {
        std::cout << "Test Created " << std::endl;
    }
    ~Test()
    {
        std::cout << "Test Destroyed " << std::endl;
    }
};
// int main(int argv, char *argc[])
// {
//     std::unique_ptr<Test> testPtr = std::make_unique<Test>();
//     std::shared_ptr<Test> testShrdPtr = std::make_shared<Test>();
//     std::weak_ptr<Test> testWeakPtr = std::make_shared<Test>();
//     return 0;
// }
main()
{
    char g[] = "geeksforgeeks"; // geeksforgeeks
    printf("%s", g + g[6] - g[8]);
}
