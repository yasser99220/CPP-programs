#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
#include <math.h>
#include <set>
using namespace std;

/** Bullet is the base Prototype */
class Bullet
{
protected:
    string _bulletName;
    float _speed;
    float _firePower;
    float _damagePower;
    float _direction;

public:
    Bullet() {}
    Bullet(string bulletName, float speed, float firePower, float damagePower)
        : _bulletName(bulletName), _speed(speed), _firePower(firePower), _damagePower(damagePower)
    {
    }
    virtual ~Bullet() {}
    virtual unique_ptr<Bullet> clone() = 0;
    void fire(float direction)
    {
        _direction = direction;

        cout << "Name        : " << _bulletName << endl
             << "Speed       : " << _speed << endl
             << "FirePower   : " << _firePower << endl
             << "DamagePower : " << _damagePower << endl
             << "Direction   : " << _direction << endl
             << endl;
    }
};

/** SimpleBullet is a Concrete Prototype */
class SimpleBullet : public Bullet
{

public:
    SimpleBullet(string bulletName, float speed, float firePower, float damagePower) : Bullet(bulletName, speed, firePower, damagePower)
    {
    }

    unique_ptr<Bullet> clone() override
    {
        return make_unique<SimpleBullet>(*this);
    }
};

/** GoodBullet is the Concrete Prototype */
class GoodBullet : public Bullet
{

public:
    GoodBullet(string bulletName, float speed, float firePower, float damagePower)
        : Bullet(bulletName, speed, firePower, damagePower)
    {
    }

    unique_ptr<Bullet> clone() override
    {
        return std::make_unique<GoodBullet>(*this);
    }
};

/** Opaque Bullet type, avoids exposing concrete implementations */
enum BulletType
{
    SIMPLE,
    GOOD
};

/** BulletFactory is the client */
class BulletFactory
{
private:
    unordered_map<BulletType, unique_ptr<Bullet>, hash<int>> m_Bullets;

public:
    BulletFactory()
    {
        m_Bullets[SIMPLE] = make_unique<SimpleBullet>("Simple Bullet", 50, 75, 75);
        m_Bullets[GOOD] = make_unique<GoodBullet>("Good Bullet", 75, 100, 100);
    }

    unique_ptr<Bullet> createBullet(BulletType BulletType)
    {
        return m_Bullets[BulletType]->clone();
    }
};

unsigned long long fibEvenSum(unsigned long long end)
{
    unsigned long long sum = 2;
    unsigned long long fir = 1;
    unsigned long long sec = 2;

    while (sec < end)
    {
        auto t = sec;
        sec = fir + sec;
        fir = t;

        if ((sec < end) && !(sec & 1))
        {
            sum += sec;
        }
    }

    return sum;
}
typedef unsigned long long ull;

bool checkprime(ull nums)
{
    ull i = 3;

    if (nums % 2 == 0)
        return false;

    for (; i < sqrt(nums); i += 2)
    {
        if ((nums % i) == 0) // found a factor other than 1 and nums
        {
            cout << "NOT PRIME" << endl;
            return false; // not prime
        }
    }

    cout << "PRIME" << endl;
    return true;
}

ull LargestPrime(ull num)
{
    ull primefactor = 2;
    ull largestprimefactor = 1;
    while (primefactor < sqrt(num))
    {
        //cout << "RAndi  primefactor" << primefactor << endl;
        if ((num % primefactor) == 0) // is a factor
        {
            if (checkprime(primefactor)) // is a prime factor
            {
                largestprimefactor = primefactor;
                cout << "chutya found largestprimefactor" << largestprimefactor << endl;
            }
        }
        primefactor++;
    }

    return largestprimefactor;
}
void repPi(string str)
{
    if (str.length() == 0)
        return;

    string rem;

    if ((str.length() >= 2) && ((str[0] == 'P') && (str[1] == 'i')))
    {
        cout << "3.14";
        rem = str.substr(2);
    }
    else
    {
        cout << str[0];
        rem = str.substr(1);
    }

    repPi(rem);
}
typedef unsigned long long ull;
bool isPalindrome(ull num)
{
    ull numcopy = num;
    ull revnum = 0;
    while (num)
    {
        ull digit = num % (ull)10;
        revnum = (revnum * (ull)10) + digit;
        num /= 10;
    }

    //cout << "isPalindrome"
    // << "revnum-" << revnum << "numcopy-" << numcopy << endl;

    if (revnum == numcopy)
        return true;

    return false;
}

ull largestpalindrome(void)
{
    ull n1 = 999;
    ull n2 = 999;
    set<ull> palinArray;
    while (n2 >= 100)
    {
        n1 = 999;
        while (n1 >= 100)
        {
            ull temp = n1 * n2;
            //cout << "n1-" << n1 << " temp-" << temp << endl;
            if (isPalindrome(temp))
            {
                palinArray.insert(temp);
                break;
            }
            n1--;
        }
        n2--;
    }

    return *(--palinArray.end());
}

void removeDup(string s)
{
    if (s.length() == 1)
    {
        cout << s[0];
        return;
    }

    string res = s.substr(1);

    if (res[0] != s[0])
    {
        cout << s[0];
    }
    removeDup(res);
}

string removeXToEnd(string s)
{
    int xt = 0;
    int xcount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != 'x')
        {
            s[xt] = s[i];
            xt++;
        }
        else
        {
            xcount++;
        }
    }
    int xcopy = xcount;

    while (xcopy)
    {
        s.pop_back();
        xcopy--;
    }

    while (xcount)
    {
        s.push_back('x');
        xcount--;
    }
    return s;
}

string Rd(string s)
{
    if (s.empty())
        return "";

    char ch = s[0];

    string res = Rd(s.substr(1));
    if (ch == res[0])
        return res;

    return ch + res;
}

int main()
{
    //BulletFactory bulletFactory;
    //cout << fibEvenSum(4000000);
    //cout << LargestPrime(600851475143);
    //repPi("Pi");
    //cout << largestpalindrome() << endl;
    //cout << Rd("abccccd");

    cout << removeXToEnd("abxcxde") << endl;
    // auto Bullet = bulletFactory.createBullet(SIMPLE);
    // Bullet->fire(90);

    // Bullet = bulletFactory.createBullet(GOOD);
    // Bullet->fire(100);
}