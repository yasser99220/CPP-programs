#include <iostream>
#include <list>

using namespace std;

int main(int argv, char *argc[])
{
    list<int> nums;    // linked List
    nums.push_back(1); // add element at the end
    nums.push_back(2);
    nums.push_back(3);
    nums.push_front(1234);
    for (list<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << endl;
    }
    auto it = nums.begin();

    it = nums.erase(it);   // erase causes to auto increment so it points to next element;
    nums.insert(it, 5678); // will insert number in between
}