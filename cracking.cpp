//
//
//1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns true if all characters of str are
// unique.
// Assumptions : (1) str contains only characters
//                   from 'a' to 'z'
//               (2) integers are stored using 32
//                   bits
bool areChractersUnique(string str)
{
    int checker = 0;

    for (int i = 0; i < str.length(); ++i)
    {
        int val = str[i] - 'a';

        if ((checker & (1 << val)) > 0) // if value is already set
            return false;

        checker = 1 << val | checker;
    }

    // An integer to store presence/absence
    // of 26 characters using its 32 bits.
    // int checker = 0;

    // for (int i = 0; i < str.length(); ++i)
    // {
    //     int val = (str[i] - 'a');

    //     // If bit corresponding to current
    //     // character is already set
    //     if ((checker & (1 << val)) > 0)
    //         return false;

    //     // set bit in checker
    //     checker |= (1 << val);
    // }

    // return true;
}

// 1.3 URLify: Write a method to replace all spaces in a string with '%2e: You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: if implementing in Java, please use a character array so that you can
// perform this operation in place.)
// EXAMPLE
// Input: "Mr John Smith JJ, 13
// Output: "Mr%2eJohn%2eSmith"

// - Project Euler 6 - //
//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

//What is the 10 001st prime number?
typedef unsigned long long ull;
bool isPrime(ull num)
{
    if ((num & 1) == 0)
    {
        return false;
    }

    for (ull i = 3; i <= num / 2; ++i)
    {
        if ((num % i) == 0)
        {
            return false;
        }
    }

    return true;
}

ull NthprimeNumber()
{
    int counter = 1;
    ull start = 2;
    while (counter <= 10000)
    {
        if (isPrime(start))
        {
            counter++;
        }
        start++;
    }
    return --start;
}

void URLify(string &s)
{
    int j = s.length() - 1;
    int i = 14; // true length

    while (i >= 0)
    {
        if (s[i] != ' ')
        {
            s[j] = s[i];
            j--;
        }
        else
        {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 3;
        }
        i--;
    }

    cout << s << endl;
}
typedef unsigned long long ull;

ull getDigitproduct(string s)
{
    ull product = 1;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '0')
            return 0;
        product = product * (s[i] - '0');
        ++i;
    }
    //cout << "product = " << product << endl;
    return product;
}

ull euler8(string s)
{
    ull result = 1;
    int i = 0; // starting index
    string t = s.substr(i, 13);
    ull firstproduct = getDigitproduct(t);

    while (i <= (s.length() - 13))
    {
        string t = s.substr(i, 13);
        //cout << "t = " << t << endl;
        ull curproduct = getDigitproduct(t);
        result = max(result, curproduct);
        i++;
    }

    return result;
}

ull euler6(void)
{
    ull sumofsqr = 0;
    ull sqrofsum = 0; //sum of n =  n(n+1)/2 and sum of square = n(n+1)(2n+1)/6
    for (int i = 1; i <= 100; ++i)
    {
        sumofsqr = sumofsqr + (i * i);
        sqrofsum += i;
    }

    sqrofsum = sqrofsum * sqrofsum;
    return sqrofsum - sumofsqr;
}

int findTriplet(int &a, int &b)
{
    if (((a * a) > 1000) || ((b * b) > 1000))
        return 0;

    int c = sqrt((a * a) + (b * b));
    //cout << "a=" << a << " b=" << b << " c=" << c << endl;
    return a * b * c;
}
// Driver code
int main()
{
    const int MaxPerimeter = 1000;

    // scan all pairs a<b
    for (int a = 1; a < MaxPerimeter; a++)
        for (int b = a; b < MaxPerimeter; b++)
        {
            // find c
            int c2 = a * a + b * b;
            // approximate square root as integer
            int c = sqrt(c2);
            // was it the correct square root ?
            if (c * c != c2)
                continue;

            // check summing condition
            int sum = a + b + c;
            if (sum > MaxPerimeter)
                break;
            if (sum == MaxPerimeter)
            {
                cout << a * b * c << endl;
            }

            // better solution than before ?
        }

    cout << "tatti" << endl;
    //cout << euler8("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450") << endl;
    //string s = " Mr John Yasser      ";
    //URLify(s);
    // if (areChractersUnique(s))
    //     cout << "Yes";
    // else
    //     cout << "No";
    return 0;
}