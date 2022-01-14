#include <iostream>
#include <sstream> // stringstream
#include <iomanip> // IO Manipulation
using namespace std;

string prettyString(string productName, double price)
{
    stringstream sout;
    sout << "Product Name : " << productName << endl;
    sout << setprecision(2) << fixed;
    sout << "Product Price: " << price << endl;
    return sout.str();
}

void sliceString(string sliceMe)
{
    stringstream sin(sliceMe);
    string productName;
    double price;
    while (!sin.eof())
    {
        sin >> productName;
        sin >> price;
        cout << prettyString(productName, price) << endl;
    }
}

int main()
{
    // string productList = "Pepper 3.34 Watermelon 5.50 TV 345.69";
    // sliceString(productList);
    string test = "acb";
    stringstream ss;
    for (auto &x : test)
    {
        int t = x - 'a';
        ss << t;
    }

    cout << "ss.str() " << ss.str() << endl;
    int tint;
    while (!ss.eof())
    {
        ss >> tint;
    }

    cout << "ans " << tint << endl;
    // cout << prettyString("Tomato", 2.3) << endl;
    // cout << "Hello World!\n";
}
