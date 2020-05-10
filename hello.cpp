#include <iostream>
#include <memory>
#include <stdarg.h>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

void simpleargument(std::string firstArgument, ...)
{
    va_list ptr;
    int num;
    va_start(ptr, firstArgument);
    num = va_arg(ptr, int); // first  list 2nd start 3rd va_arg
    cout << num;
    va_end(ptr);
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
    int getI() { return i; }
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
bool isHappy(int n)
{
    int newNum = 0;
    while (1)
    {
        if (newNum >= INT8_MAX)
        {
            break;
        }

        for (; n != 0; n = n / 10)
        {
            int digit = n % 10;
            cout << digit << endl;
            newNum = newNum + (digit * digit);
            cout << newNum << endl;
        }

        if (newNum == 1)
        {
            return true;
        }
        else
        {
            n = newNum;
            newNum = 0;
        }
    }
    return false;
}

void xHexFormatter(std::string &test)
{
    for (int i = 0; i < test.length(); ++i)
    {
        if (i % 2 == 0)
        {
            test.insert(i, "\\x");
            i += 2;
        }
    }

    std::cout << "result " << test << std::endl;
}

int main()
{
    //const int &test1 = 3;
    // std::unique_ptr<test> f{new test};
    // std::string test = "123565:456775";
    // std::string firsthalf = test.substr(0, test.find(':'));
    // std::string secondhalf = test.substr(test.find(':') + 1, test.length() - test.find(':'));
    // cout << "firsthalf = " << firsthalf << endl;
    // cout << "secondhalf = " << secondhalf << endl;
    // takeOwnership(std::move(f)); //have to transfer ownership via move
    //std::string test = "3031514906104046202020202020202020202041435455414C495A41522050524543494F40405445524D494E414C202020203A204F4350303030303340434F442E20455354414220203A203030303032303132404553544143494F4E204C4F53204C41474152544F53404046454348412020203A2031382F30362F323031392031303A34343A323740434F4D50524F422E3A2030303035303838343440402020202020202020202020202A2A434F4D4255535449424C452A2A4050524F445543544F20202020202020202020202020202020202020202056414C4F52404741534F4C20434F525249454E54452E2E2E2E2E2E2E2E2E31322E3334352C303030404741534F4C2045585452412E2E2E2E2E2E2E2E2E2E2E2E2E31332E3536322C3030304044494553454C2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E31322E3334352C3030304044494553454C2053555052454D452E2E2E2E2E2E2E2E2E2E32302E3230302C30303040474E562E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E32302E3030302C3030304040404040402020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020";
    //std::string ans = test;

    //std::cout << isHappy(2) << std::endl;
    // for (int i = 0; i < test.length(); ++i)
    // {
    //     if (test[i] == ' ')
    //         continue;
    //     else
    //     {
    //         ans += test[i];
    //     }
    // }
    //wchar_t wchar = L'a';
    //std::cout << wchar << std::endl;

    // vector<int> t1 = {1, 2, 3, 4, 5};
    // for (int i = 0; i < t1.size(); ++i)
    // {
    //     std::cout << t1[i] << std::endl;
    // }

    // for (int val : t1)
    // {
    //     std::cout << val << endl;
    // }

    // for (vector<int>::iterator it = t1.begin(); it != t1.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }

    // std::unordered_map<std::string, int> test;
    // using scoremap = std::unordered_map<std::string, int>::iterator;
    // test["yasser"] = 1;
    // test["yolo"] = 2;
    // for (scoremap it = test.begin(); it != test.end(); ++it)
    // {
    //     auto &key = it->first;
    //     auto &value = it->second;
    //     cout << key << " " << value << endl;
    // }

    // for (std::unordered_map<std::string, int>::iterator it = test.begin(); it != test.end(); ++it)
    // {
    //     auto &key = it->first;
    //     auto &value = it->second;
    //     cout << key << " " << value << endl;
    // }

    // cout << endl;

    // for (auto kv : test)
    // {
    //     auto &key = kv.first;
    //     auto &value = kv.second;
    //     cout << key << " " << value << endl;
    // }
    // cout << endl;

    // for (auto [key, value] : test)
    // {
    //     cout << key << " " << value << endl;
    // }

    //std::cout << "after removing space " << ans << std::endl;
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
    std::cout << "testing empty string append" << endl;
    std::string tatti;
    tatti.append("goo");
    std::cout << "testing empty string append success " << tatti << endl;

    return 0;
}