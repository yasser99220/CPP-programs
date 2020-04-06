#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex> // to use regex in any string
using namespace std;

string RemoveVowel(string str)
{
    std::regex vowels("[aeiouAEIOU]");          // create a regex variable with value within the quotes and [] braces
    return std::regex_replace(str, vowels, ""); // regex replace takes 3 arguments 1st string regex vowel and the string to replace
}

int PairSum(vector<int> &arr, const int &sum)
{
    int count = 0, i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] > sum)
        {
            j--;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            count++;
            i++;
            j--;
        }
    }
    return count;
}
void FindMinMax(const vector<int> &arr)
{ // is num[i]>
    int max = arr[0], min = arr[0];

    for (auto x : arr)
    {
        if (min < x)
        {
            min = x;
        }
        else if (x > max)
        {
            max = x;
        }
    }
    cout << "min - " << min << " "
         << "max - " << max << endl;
}

int main()
{
    vector<int> test = {1, 2, 4, 5, 6, 8, 9, 10, 13, 15};

    cout << PairSum(test, 10) << endl;
    FindMinMax(test);
    string fieldData = "01QI @ EL VEHICULO NO ESTA ACTIVO &       ";
    uint64_t lengthOfDeclinedMessage = (fieldData.find("&") - fieldData.find("@")) - 1;
    string result = fieldData.substr(fieldData.find("@") + 1, lengthOfDeclinedMessage);
    cout << result << " index of @ " << fieldData.find("@") << "index of & " << fieldData.find("&") << "total Length of data - " << fieldData.length() << endl;
    string hexvalue = "3031514906104046202020202020202020202041435455414C495A41522050524543494F40405445524D494E414C202020203A204F4350303030303340434F442E20455354414220203A203030303032303132404553544143494F4E204C4F53204C41474152544F53404046454348412020203A2031382F30362F323031392031303A34343A323740434F4D50524F422E3A2030303035303838343440402020202020202020202020202A2A434F4D4255535449424C452A2A4050524F445543544F20202020202020202020202020202020202020202056414C4F52404741534F4C20434F525249454E54452E2E2E2E2E2E2E2E2E31322E3334352C303030404741534F4C2045585452412E2E2E2E2E2E2E2E2E2E2E2E2E31332E3536322C3030304044494553454C2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E31322E3334352C3030304044494553454C2053555052454D452E2E2E2E2E2E2E2E2E2E32302E3230302C30303040474E562E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E2E32302E3030302C3030304040404040402020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020";
    uint64_t length = hexvalue.length();
    for (int i = 0; i < hexvalue.length(); ++i)
    {
        if (i % 2 == 0)
        {
            hexvalue.insert(i, "\\x");
            i += 2;
        }
    }
    cout << hexvalue << endl;
    cout << "hello world" << endl;
    cout << " Thank you " << endl;
    return 0;
}
