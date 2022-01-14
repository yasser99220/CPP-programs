#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Good morning,

Today's Byte

This question is asked by Facebook. Given a string, return whether or not it forms a palindrome ignoring case and non-alphabetical characters.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"level", return true
"algorithm", return false
"A man, a plan, a canal: Panama.", return true
Thanks,
The Daily Byte
*/
bool isPalindrome1(int argv, const char *argc[])
{
    const string input = "A man, a plan, a canal: Panama.";
    string parsedInput;

    for (int i = 0; i < input.length(); ++i) // make lower case and remove preps
    {
        if (input[i] >= 'A' && input[i] <= 'Z') // A-Z
        {
            parsedInput.push_back(input[i] + 32);
        }
        else if ((input[i] >= '1' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'z'))
        {
            parsedInput.push_back(input[i]);
        }
    }
    cout << "Parsed Input :" << parsedInput << endl;
    string reverseStr(parsedInput);
    reverse(reverseStr.begin(), reverseStr.end());
    cout << "Reverse Parsed Input :" << parsedInput << endl;
    if (!reverseStr.compare(parsedInput))
    {
        return true;
    }
    return false;
}

/* This question is asked by Amazon. Given a string representing the sequence of moves a robot vacuum makes, return whether or not it will return to its original position. The string will only contain L, R, U, and D characters, representing left, right, up, and down respectively.

Ex: Given the following strings...

"LR", return true
"URURD", return false
"RUULLDRD", return true*/

int vaccumCleaner(int argc, char *argv[])
{
    string s("RUULLDRD");
    map<char, int> hash;
    for (const auto &x : s)
    {
        hash[x] += 1;
    }

    if ((hash['L'] == hash['R']) && hash['U'] == hash['D'])
    {
        cout << "true" << endl;
        return EXIT_SUCCESS;
    }

    cout << "false" << endl;
    return EXIT_FAILURE;
}
int arraySum(vector<int> test, int index) // 5 4 32 1
{
    if (index == (test.size() - 1))
        return test[index];

    cout << test[index] << endl;

    return test[index] + arraySum(test, index + 1);
}

int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fib(n - 1) + fib(n - 2);
}
/*
Good morning,

Today's Byte

This question is asked by Facebook. Given a string and the ability to delete at most one character, return whether or not it can form a palindrome.
Note: a palindrome is a sequence of characters that reads the same forwards and backwards.

Ex: Given the following strings...

"abcba", return true
"foobof", return true (remove the first 'o', the second 'o', or 'b')
"abccab", return false
Thanks,
The Daily Byte
*/

bool isPalindrome(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
        }

        i++;
        j--;
    }
    return true;
}

int sumDigit(int n)
{
    if (n == 0)
        return 0;

    return (n % 10) + sumDigit(n / 10);
}

void printStringReverseOrder(string &s, int index)
{
    if (index == s.length())
        return;

    printStringReverseOrder(s, index + 1);
    cout << s[index];
}

void printStringReverseOrder(string &s)
{
    printStringReverseOrder(s, 0);
}

/*
This question is asked by Google. Given an array of integers, return whether or not two numbers sum to a given target, k.
Note: you may not sum a number with itself.

Ex: Given the following...

[1, 3, 8, 2], k = 10, return true (8 + 2)
[3, 9, 13, 7], k = 8, return false
[4, 2, 6, 5, 2], k = 4, return true (2 + 2)
Thanks,
The Daily Byte
*/
bool isSum(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end()); // nlogn
    int j = nums.size() - 1;
    for (int i = 0; i < j;)
    {
        if ((nums[i] + nums[j]) == k)
            return true;
        else if ((nums[i] + nums[j]) < k)
        {
            i++;
        }
        else if ((nums[i] + nums[j]) > k)
        {
            j--;
        }
    }
    return false;
}

bool isSumOptimized(vector<int> nums, int k)
{
    map<int, int> hash; // hash map

    for (int i = 0; i < nums.size(); ++i)
    {
        cout << "find:" << k - nums[i] << endl;
        if (hash.end() != hash.find(k - nums[i]))
        {
            return true;
        }
        hash[nums[i]] += 1; // populate map
    }

    return false;
}

// a^3 + b^3 = c^3 + d^3
void solve(int N)
{

    unordered_map<long long int, vector<pair<int, int>>> umap;

    for (int i = 0; i <= N; i++)
        for (int j = i; j <= N; j++)
        {
            long long int tmp = i * 1LL * i * 1LL * i + j * 1LL * j * 1LL * j;
            umap[tmp].push_back({i, j});
        }

    for (auto it : umap)
    {
        if (it.second.size() == 1)
            continue;
        for (auto x : it.second)
            cout << "(" << x.first << "," << x.second << ")"
                 << " ";
        cout << endl;
    }
}
/*This question is asked by Amazon. Given a string representing your stones and another string representing a list of jewels, return the number of stones that you have that are also jewels.

Ex: Given the following jewels and stones...

jewels = "abc", stones = "ac", return 2
jewels = "Af", stones = "AaaddfFf", return 3
jewels = "AYOPD", stones = "ayopd", return 0
Thanks,
The Daily Byte*/

int isJewel(const string &jewel, const string &stone)
{
    int result = 0;
    map<char, int> jewelHash;
    for (auto &x : jewel)
    {
        jewelHash[x]++;
    }

    for (auto &x : stone)
    {
        if (jewelHash[x])
            result++;
    }
    return result;
}

/*
This is a Facebook interview question.
They ask for the intersection, which has a trivial solution using a hash or a set.

Then they ask you to solve it under these constraints:
O(n) time and O(1) space (the resulting array of intersections is not taken into consideration).
You are told the lists are sorted.

Cases to take into consideration include:
duplicates, negative values, single value lists, 0's, and empty list arguments.
Other considerations might include
sparse arrays.

function intersections(l1, l2) {
    l1.sort((a, b) => a - b) // assume sorted
    l2.sort((a, b) => a - b) // assume sorted
    const intersections = []
    let l = 0, r = 0;
    while ((l2[l] && l1[r]) !== undefined) {
       const left = l1[r], right = l2[l];
        if (right === left) {
            intersections.push(right)
            while (left === l1[r]) r++;
            while (right === l2[l]) l++;
            continue;
        }
        if (right > left) while (left === l1[r]) r++;
         else while (right === l2[l]) l++;
        
    }
    return intersections;
}
*/

int main()
{

    //cout << sumDigit(123) << endl;
    // string temp = "Yasser";
    // printStringReverseOrder(temp);
    //vector<int> input = {1, 2, 3, 4, 5};
    //cout << fib(7) << endl;
    //cout << arraySum(input, 0) << endl;
    //vector<int> test = {1, 3, 8, 2};
    //cout << isSumOptimized(test, 10) << endl;
    cout << isJewel("abc", "ac") << endl;
}