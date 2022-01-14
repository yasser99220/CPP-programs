#include <map>
#include <iostream>

using namespace std;

int main()
{
    multimap<int, string> mmap;
    mmap.insert(make_pair(10, "Nabila"));
    mmap.insert({10, "Yasser"}); // cant use subscript operator
    mmap.insert({20, "mummy"});
    mmap.insert({30, "mummy2"});

    for (multimap<int, string>::iterator it = mmap.begin(); it != mmap.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> range = mmap.equal_range(10);
    for (multimap<int, string>::iterator it = range.first; it != range.second; ++it)
    {
        cout << "range-" << it->first << " " << it->second << endl;
    }
}