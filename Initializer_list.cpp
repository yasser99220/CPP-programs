#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class Test
{
public:
    Test(initializer_list<string> infos)
    {
        for (auto &x : infos)
        {
            info.push_back(x);
        }
    }

    void getInfo()
    {
        for (auto &x : info)
        {
            cout << x << endl;
        }
    }

private:
    vector<string> info;
};
int main()
{
    Test t{"yolo", "yasser", "nabila"};
    t.getInfo();
}