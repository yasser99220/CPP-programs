#include <iostream>
#include <memory>
#include <stdarg.h>
using namespace std;

void simpleargument(std::string firstArgument, ...)
{
    va_list ptr;
    int num;
    va_start(ptr, firstArgument);
    num = va_arg(ptr, int); // first  list 2nd start 3rd va_arg
    num = va_arg(ptr, int);
    cout << num;
}

#include <array>
#include <string>

int points(const std::array<std::string, 10> &games)
{
    int pointsum = 0;
    for (auto x : games)
    {
        if (x[0] > x[2])
        {
            pointsum += 3;
        }
        else if (x[0] == x[2])
        {
            pointsum += 1;
        }
    }

    return pointsum;
}

void fileDetails(void)
{
    cout << "file lines   " << __LINE__ << endl;
    cout << "file data    " << __DATE__ << endl;
    cout << "file time    " << __TIME__ << endl;
    cout << "file name    " << __FILE__ << endl;
}
struct test
{
    int i;
    int geti() { return i; }
};

std::unique_ptr<int> returnUnique(void)
{ // unique Ptr can be used as the return type compiler moves the ownership to other Ptr
    std::unique_ptr<int> tester{new int};
    return tester; // internally calls move for us
}
void takeOwnership(std::unique_ptr<test> tester)
{
    // have to call it with move as parameter
    // user tester
}

void sharedPointer()
{
    std::shared_ptr<int> shareOwner = std::make_shared<int>(5); //here control block is used to track ownership with ref count
    {
        std::shared_ptr<int> owner2 = shareOwner;
        std::shared_ptr<int> owner3 = std::shared_ptr<int>{new int}; // not preferred
    }
}
int nextWithSameBitSetCount(const int &num)
{
    int bitcount = 0;
    int bitcountfornum = 0;
    for (int i = 0; i < 32; ++i)
    {
        if (num >> i & 1)
        {
            bitcountfornum++;
        }
    }
    int fromNum = num + 1;
    while (1)
    {
        for (int i = 0; i < 32; ++i)
        {
            if ((fromNum >> i) & 1)
            {
                bitcount++;
            }
        }
        if (bitcountfornum == bitcount)
        {
            return fromNum;
        }
        else
        {
            fromNum++;
            bitcount = 0;
        }
    }
}

int main()
{
    // std::unique_ptr<test> f{new test};
    // std::string test = "123565:456775";
    // std::string firsthalf = test.substr(0, test.find(':'));
    // std::string secondhalf = test.substr(test.find(':') + 1, test.length() - test.find(':'));
    // cout << "firsthalf = " << firsthalf << endl;
    // cout << "secondhalf = " << secondhalf << endl;
    // takeOwnership(std::move(f)); //have to transfer ownership via move
    std::string test = "30 31 51 49 06 10 40 46 20 20 20 20 20 20 20 20 20 20 20 41 43 54 55 41 4c 49 5a 41 52 20 50 52 45 43 49 4f 40 40 54 45 52 4d 49 4e 41 4c 20 20 20 20 3a 20 4f 43 50 30 30 30 30 33 40 43 4f 44 2e 20 45 53 54 41 42 20 20 3a 20 30 30 30 30 32 30 31 32 40 45 53 54 41 43 49 4f 4e 20 4c 4f 53 20 4c 41 47 41 52 54 4f 53 40 40 46 45 43 48 41 20 20 20 3a 20 31 38 2f 30 36 2f 32 30 31 39 20 31 30 3a 34 34 3a 32 37 40 43 4f 4d 50 52 4f 42 2e 3a 20 30 30 30 35 30 38 38 34 34 40 40 20 20 20 20 20 20 20 20 20 20 20 20 2a 2a 43 4f 4d 42 55 53 54 49 42 4c 45 2a 2a 40 50 52 4f 44 55 43 54 4f 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 56 41 4c 4f 52 40 47 41 53 4f 4c 20 43 4f 52 52 49 45 4e 54 45 2e 2e 2e 2e 2e 2e 2e 2e 2e 31 32 2e 30 30 30 2c 30 30 30 40 47 41 53 4f 4c 20 45 58 54 52 41 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 31 2e 35 36 32 2c 30 30 30 40 44 49 45 53 45 4c 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 31 2e 33 34 35 2c 30 30 30 40 44 49 45 53 45 4c 20 53 55 50 52 45 4d 45 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 32 35 2e 32 30 30 2c 30 30 30 40 47 4e 56 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 2e 32 30 2e 30 30 30 2c 30 30 30 40 40 40 40 40 40 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20 20";
    std::string ans;
    for (int i = 0; i < test.length(); ++i)
    {
        if (test[i] == ' ')
            continue;
        else
        {
            ans += test[i];
        }
    }
    std::cout << "after removing space " << ans << std::endl;

    std::string result;
    for (int i = 0, j = 0; i < ans.length(); ++i, j++)
    {
        if (i % 2 == 0)
        {
            result += "\\x";
            j += 2;
        }

        result += ans[i];
    }

    std::cout << "result " << result << std::endl;
    // std::string test = "GASOL CORRIENTE.........12.345,000";
    // test = test.substr(test.rfind("..") + 2);
    // cout << test << endl;
    // std::unique_ptr<int> test{new int};
    // std::unique_ptr<int *> test2{new int *[5]};
    // std::unique_ptr<int **> testdouble{new int **};
    // auto f = std::move(test); // release ownership of f and transfer it to f
    //cout << nextWithSameBitSetCount(2);
    //fileDetails();
    //cout << "hello world" << endl;
    //cout << " Thank you " << endl;
    return 0;
}