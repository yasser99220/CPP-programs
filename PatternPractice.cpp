
#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;
int m1()
{
    int l = 5;
    int b = 3;
    cin >> l >> b;

    for (int j = 0; j < b - 1; ++j)
    {
        for (int i = 0; i < l; ++i)
        {
            cout << "* ";
        }
        cout << endl;
    }
    // * * * * *
    // * * * * *
    // * * * * *
    return 0;
}

int m2() // hollow rectangle
{
    int l = 5;
    int b = 3;

    for (int i = 1; i <= b; ++i) // 0 1 2
    {
        for (int j = 1; j <= l; ++j) // 0 1 2 3 4
        {
            if ((i == 1) || (i == b)) // for top upper and lower bounds
            {
                cout << "* ";
                continue;
            }

            if ((j == 1) || (j == l))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int m3() // half pyramid
{
    int r = 5;
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int m4() // inverted half pyramid
{
    int l = 6;

    for (int j = l; j >= 1; --j) // 5 4 3 2 1
    {
        for (int i = j; i >= 1; --i) // i = 5 j = 5 4 3 2 1  i = 4 j = 4 3 2 1
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int m5() // hollow inverted half pyramid
{
    int l = 6;

    for (int i = l; i >= 1; --i) // 6 5 4 3 2 1
    {
        for (int j = i; j >= 1; --j) // 6
        {
            if (i == l) // for upper first line
            {
                cout << "* ";
                continue;
            }

            if (j == i || j == 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }

        cout << endl;
    }
}

int m6() // full pyramid
{
    int l = 6;

    for (int i = 1; i <= l; ++i) // for new lines // 1 2 3 4 5 6
    {
        for (int j = l - i; j >= 1; --j) // for spaces // 5 4 3 2 1
        {
            cout << " ";
        }

        for (int k = 1; k <= i; ++k) // 1 2 3 4 5 6
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int m7() // full inverted Pyramid
{
    int l = 6;

    for (int i = 1; i <= l; ++i) // for the lines // 1 2 3 4 5 6
    {
        for (int j = 1; j < i; ++j) // for spaces 0 1 2 3 4 5
        {
            cout << " ";
        }

        for (int k = l - i + 1; k >= 1; --k) // for stars // 6 5 4 3 2 1
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int m8() // full hollow pyramid
{
    int l = 7;

    for (int i = 1; i <= l; ++i) // - 1 2 3 4 5 6
    {
        for (int j = l - i; j >= 1; --j) // for spaces times 6 - 1 = 5 6 - 2 = 4  4 3 2 1 0 times
        {
            cout << " ";
        }

        for (int k = 1; k <= i; ++k) // times - for the stars 1 2 3 4 5 6
        {

            if ((k == 1 || k == i) && (i != l)) // for first and last print *
            {
                cout << "* ";
            }
            else if (i != l)
            {
                cout << "  ";
            }

            if (i == l)
            {
                for (int m = 1; m <= l; ++m) // for last line print all *
                {
                    cout << "* ";
                }
                break;
            }
        }
        cout << endl;
    }
}

// number patten facePrep - # 3.1

int m10()
{
    int l = 5;
    for (int i = 1; i <= l; ++i) // each line 1 2 3 4 5 6
    {
        for (int j = 1; j <= i; ++j) // numbers in each line 1 2 3 4 5
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//number pattern facePrep - #3.2
int m11()
{
    int l = 5;

    for (int i = 0; i < l; ++i) // 0 1 2 3 4
    {
        for (int j = 1; j <= (l - i); ++j) // times 5 4 3 2 1
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

//Face Prep 3.3 hollow half pyramid

int m12()
{
    int l = 5;

    for (int i = 1; i <= l; ++i) // loop for lines  1 2 3 4 5
    {
        for (int j = 1; j <= i; ++j) // loop for printing numbers  times 1 2 3 4 5
        {
            if (j == 1 && i != l) // for first 1 in each line
            {
                cout << j << " ";
            }
            else if (j == i && i != l) // for last word in each line 1 2 3 4 5
            {
                cout << j << " ";
            }
            else if (i != l)
            {
                cout << "  ";
            }

            if (i == l)
                cout << j << " ";
        }
        cout << endl;
    }
}

//number pattern full 3.4 full pyramid
int m13()
{
    int l = 5;
    int lead = l + 3; // 8
    int leadsec = 0;
    for (int i = 1; i <= l; ++i) // for each new line 1 2 3 4 5
    {
        for (int j = lead; j >= 1; --j) // for spaces times 8 6 4 2 0
        {
            cout << " ";
        }

        lead -= 2;

        int start = i;

        for (int k = 1; k <= i; ++k) // for each row times just increase the start and start = i (row no) times 1 2 3 4 5
        {
            cout << start++ << " ";
        }
        leadsec = (i * 2) - 2; // 0 2 4 6 8
        if (leadsec)           // dont do anything for i = 1
        {
            for (int k = i - 1; k >= 1; --k) // i [2 3 4 5]times 1 2 3 4 k [1 2 3 4]
            {
                cout << leadsec << " ";
                leadsec--;
            }
        }

        if (!(i == l))
            cout << endl;
    }
}

//FacePrep 3.5 hollow half pyramid
int m14()
{
    int l = 5;

    for (int i = 1; i <= l; ++i) // number of lines 1 2 3 4 5
    {
        for (int j = l - i; j >= 1; --j) // spaces 4 3 2 1 0x times i [1 2 3 4 5] j times [4 3 2 1]
        {
            cout << " "; // only spaces [4 3 2 1] times
        }

        for (int k = 1; k <= i; k++) // 1 2 3 4 5
        {
            if (k == 1 || k == i || i == l)
                cout << k << " ";
            else
                cout << "  ";
        }
        if (i != l) // dont add unnecessary new line at the end
            cout << endl;
    }
}

// 3.6 hollow inverted half pyramid
int m15()
{
    int l = 5;

    for (int i = 1; i <= l; ++i) // for each new lines [1 2 3 4 5]
    {
        int start = i;
        for (int j = l - i + 1; j >= 1; --j, ++start) // [5 4 3 2 1] times
        {
            if ((j == (l - i + 1)) || (j == 1) || (i == 1)) // print only for i = 1 first and last iteration of j
                cout << start << " ";
            else
            {
                cout << "  ";
            }
        }
        if (i != l) // dont print last endl not required
            cout << endl;
    }
}

//4.1 FacePrep Palindromic pyramid
int m16()
{
    int l = 5;

    for (int i = 1; i <= l; ++i) // for each new line i[1 2 3 4 5 ]
    {
        int start = 0;
        for (int j = 1; j <= ((2 * i) - 1); ++j) // no of times we need to print digit  times [1 3 5 7 9] [1 3 5 7 9]
        {
            if (j <= (i * 2) / 2) // increase till middle then decrease
            {                     //  j times  [1 3 5 7 9] start [1 -- ]
                start++;
            }
            else
            {
                start--;
            }
            cout << start << " ";
        }
        if (i != l) // dont add endl at last not required.
            cout << endl;
    }
}

// Face Prep 4.2 Palindromic Alphabet Pyramid
int m17()
{
    int l = 5;

    for (int i = 1; i <= l; ++i) // for each new line 1 2 3 4 5
    {
        char c = 'A' - 1;
        for (int j = 1; j <= (i * 2) - 1; ++j) // for each letter Printing times [1 3 5 7 9] res times [1 3 5 7 9]
        {
            if (j <= i)
            {
                c++;
            }
            else
            {
                c--;
            }
            cout << c << " ";
        }
        if (i != l) // last endl not required
            cout << endl;
    }
}

// Face Prep 4.3 Palindromic Alphabet full Pyramid
int m18()
{
    int l = 5;
    int space = 8;
    for (int i = 1; i <= l; ++i) // for each new line 1 2 3 4 5
    {
        char c = 'A' - 1;

        for (int k = 1; k <= space; ++k) // for spaces times  [1 2 3 4 5] [7 5 3 2 0] res // []
        {
            cout << " ";
        }
        space -= 2;
        for (int j = 1; j <= (i * 2) - 1; ++j) // for each letter Printing times [1 3 5 7 9] res times [1 3 5 7 9]
        {
            if (j <= i)
            {
                c++;
            }
            else
            {
                c--;
            }
            cout << c << " ";
        }
        if (i != l) // last endl not required
            cout << endl;
    }
}
//FacePrep - 5. 1 full diamond *
int m19()
{
    int l = 5;
    for (int i = 1; i <= l; i++) // for upper half line
    {
        for (int j = l - i; j >= 1; --j) // for spaces [4 3 2 1]
        {
            cout << " ";
        }
        for (int k = 1; k <= i; ++k) // for stars [1 2 3 4 5]
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i <= l; ++i) // for lower half each line 1 2 3 4 5
    {
        for (int j = 0; j < i - 1; ++j) // spaces 0 1 2 3 4 res times [ 0 1 2 3 4 ]
        {
            cout << " ";
        }
        for (int k = l - i; k >= 0; k--) // times [5 4 3 2 1 ]
        {
            cout << "* ";
        }
        if (i != l)
            cout << endl;
    }
}
//largest among 3
int m20()
{
    int x, y, z;
    cin >> x >> y >> z;
    int ans;
    if (x > y && x > z)
    {
        ans = x;
    }
    else if (z >= y)
    {
        ans = z;
    }
    else
    {
        ans = y;
    }
    cout << endl;
    cout << ans << endl;
}

#pragma pack(push, 1)
struct person
{
    char name[50];
    int age;
    double weight;
};
#pragma pack(pop)

int m21()
{
    string fileName = "test.bin";
    person p1 = {"File", 1, 99.99};

    double A;
    cin >> A;
    double B;
    cin >> B;
    double C;
    cin >> C;
    std::cout << showbase << std::hex << left << nouppercase << (long)A << std::endl;
    std::cout << setw(15) << right << setfill('_') << fixed << showpos << setprecision(2) << B << endl;
    cout << uppercase << fixed << setprecision(9) << scientific << noshowbase << noshowpos << C << endl;

    fstream outputFile;
    outputFile.open(fileName, ios::binary | ios::out);
    if (outputFile.is_open())
    {
        outputFile.write((char *)&p1, sizeof(person));
    }
    else
    {
        cout << "Unable to open file " << fileName << endl;
    }
    outputFile.close();

    person p2 = {};

    fstream inputFile;
    inputFile.open(fileName, ios::binary | ios::in);

    if (inputFile.is_open())
    {
        inputFile.read((char *)&p2, sizeof(person));
        cout << p2.age << " " << p2.name << " " << p2.weight << endl;
    }
    else
    {
        cout << "File not readable " << fileName << endl;
    }
    inputFile.close();
    return 0;
}
// pattern Face prep  4.3
int m22()
{
    int l = 2;

    for (int i = l; i >= 1; --i) // for each new line [ 5 4 3 2 1 ]
    {
        for (int j = 1; j <= (i * 2) - 2; ++j) // for spaces times [8 6 4 2 0] res [8 6 4 2 0] times
        {
            cout << " ";
        }
        int num = 0;
        int count = ((l - i) * 2) + 1;
        for (int k = ((l - i) * 2) + 1; k >= 1; --k) // number times [1 3 5 7 9] res [1 3 5 7 9]
        {
            if (k >= ((count + 1) / 2))
            {
                cout << ++num << " ";
            }
            else
            {
                cout << --num << " ";
            }
        }

        if (i != 1) // dont print extra new line at end
        {
            cout << endl;
        }
    }
}

//face prep Hollow diamond 5.2
int m23()
{
    int l = 3;
    while (l < 20)
    {
        for (int i = 1; i < l; ++i) // for upper half each new line [1 2 3 4]
        {
            for (int j = l - i; j > 1; j--) // for spaces times [3 2 1 0]  [4 3 2 - 3 2 - 2 - 0] 3 , 2 , 1 , 0
            {
                cout << " ";
            }

            for (int k = (i * 2) - 1; k >= 1; k--) // printing stars times [1 3 5 7 ] [1 3 5 7]
            {
                if (k == ((i * 2) - 1) || (k == 1))
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }

        for (int i = 1; i < l; ++i) // for lower half each new line [1 2 3 4]
        {
            for (int w = i - 1; w > 0; --w) // for spaces [0 1 2 3] [0 1 2 3]
            {
                cout << " ";
            }

            for (int x = ((l - i) * 2) - 1; x >= 1; --x) // for * [7 5 3 1] [7 5 3 1]
            {
                if (x == (((l - i) * 2) - 1) || x == 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        l++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
    }
    return 0;
}

// face prep half diamond 5.3

int m24()
{
    int l = 8;

    for (int i = 1; i <= l; i++) // for upper 5
    {
        for (int j = 1; j <= i; j++) // times [1 2 3 4 5]
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i < l; ++i) // lower half 4 i [1 2 3 4]
    {
        for (int j = l - 1; j >= i; j--) // 4 3 2 1  [4 3 2 1]
        {
            cout << "* ";
        }
        if ((i + 1) != l)
            cout << endl;
    }
    return EXIT_SUCCESS;
}

int m25()
{
    int l = 5;
    for (int i = 1; i < l; ++i) // new line [1 2 3 4]
    {
        for (int j = 1; j < (i * 2); ++j) // no if times it needs to printed [1 3 5 7] true [1 3 5 7]
        {
            if (!(j & 1))
            {
                cout << "*";
            }
            else
            {
                cout << i;
            }
        }
        cout << endl;
    }

    for (int i = l - 1; i >= 1; i--) // for new line  4 3 2 1
    {
        for (int j = (i * 2) - 1; j >= 1; j--) // for each char [7 5 3 1]
        {
            if (!(j & 1))
            {
                cout << "*";
            }
            else
            {
                cout << i;
            }
        }
        cout << endl;
    }
}

int m26()
{
    int n = 5;

    cout << "*" << endl;

    for (int i = 1; i <= n; ++i)
    {
        int c = 0;
        for (int j = 1; j < (i * 2); j++)
        {
            if (j == 1)
            {
                cout << "* ";
            }

            if (j <= i)
            {
                cout << ++c << " ";
            }
            else
            {
                cout << --c << " ";
            }
            if ((j + 1) == (i * 2)) // last iteration
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--) // 2,1
    {
        int c = 0;
        for (int j = (i * 2) - 1; j >= 1; j--) // [3 2 1] [1]
        {
            if (j == ((i * 2) - 1))
            {
                cout << "* ";
            }

            if (j >= i)
            {
                cout << ++c << " ";
            }
            else
            {
                cout << --c << " ";
            }

            if (j == 1) // last iteration
                cout << "* ";
        }
        cout << endl;
    }

    cout << "* ";
}
int m27()
{
    int n = 7;
    int count = 1;
    for (int i = 1; i <= n; ++i) // 1 2 3 4 5 6 7
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << count++ << " ";
        }

        if (i != n)
            cout << endl;
    }
}

typedef unsigned long long ull;
ull smallestMultiple(void)
{
    ull num = 21;
    while (num)
    {
        bool invalidnum = false;
        for (int i = 2; i <= 20; i++)
        {
            if ((num % i) != 0)
            {
                invalidnum = true;
                break;
            }
        }

        if (invalidnum)
            num++;
        else
        {
            return num;
        }
    }
}

// Faceprep Pascal Triangle:

void Pascal(int n)
{
    for (int i = 0; i < n; i++) // 0 1 2 3 4
    {
        for (int j = n - i; j >= 1; j--) // times [4 3 2 1 0]
        {
            cout << " ";
        }

        int den = 1;
        int toPrint = 1;
        int num = i;
        for (int k = 0; k <= i; k++) // times [1 2 3 4 5]
        {
            cout << toPrint << " ";
            toPrint = toPrint * num;
            toPrint = toPrint / den;
            num--;
            den++;
        }
        cout << endl;
    }
}

// FacePrep pattern Practice Pascal Triangle

void pascal2(void)
{
    int l = 5; // no of rows

    for (int i = 1; i <= l; ++i) // 1 2 3 4 5 for each new line
    {
        for (int j = l - 1; j >= i; j--) // 4 3 2 1 0
        {
            cout << " ";
        }

        int coef = 1;

        for (int k = 1; k <= i; k++)
        {
            cout << coef << " ";
            coef = coef * (i - k) / k;
        }
        if (i != l)
            cout << endl;
    }
}

// Faceprep Hollow Diamond Inscribed in a Rectangle

int m28()
{
    int l = 9;
    for (int i = 0; i < l; ++i) // 0 1 2 3 4 for new line
    {
        for (int j = l; j > i; --j) // times [5 4 3 2 1] for each row
        {
            cout << "*";
        }

        for (int k = 1; k <= 2 * i; k++) // 0 2 4 6 8 for spaces
        {
            cout << " ";
        }

        for (int j = l; j > i; --j) // times [5 4 3 2 1] for each row
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= l; ++i) // 1 2 3 4 5 for each new line
    {
        for (int j = 1; j <= i; ++j) // times [1 2 3 4 5] lower left half
        {
            cout << "*";
        }

        for (int k = (l - i) * 2; k >= 1; k--) // 8 6 4 2 0 times for spaces
        {
            cout << " ";
        }

        for (int j = 1; j <= i; ++j) // 1 2 3 4 5
        {
            cout << "*";
        }

        if (i != l)
            cout << endl;
    }
}
int main()
{
    pascal2();
}
