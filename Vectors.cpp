#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    vector<int> v2(5, 1);
    v.begin();
    v.end();
    v.push_back(1);
    v.pop_back();
    v.front();
    v.reserve(5);
    v.resize(100);
    v.clear();
    v.capacity();

    vector<vector<int>> v2(4, vector<int>(4, 0)); // 4 x 4 matrix

    // for (int i = 0; i < v2.size(); i++)
    // {
    //     for (int j = 0; j < v2[i].size(); ++j)
    //     {
    //         cout << v2[i][j] << " "; // why error ?
    //     }
    //     cout << endl;
    // }
}