#include <iostream>
using namespace std;
class Vector2
{
private:
    float x{0.0};
    float y{0.0};

public:
    Vector2(float x, float y) : x(x), y(y)
    {
    }
    Vector2()
    {
        std::cout << "default" << std::endl;
    }
    Vector2(const Vector2 &other)
    {
        x = other.x;
        y = other.y;
    }

    Vector2 operator+(const float &t)
    {
        x += t;
        y += t;
    }

    Vector2 operator+(const Vector2 &other) const
    {

        return Vector2(this->x + other.x, this->y + other.y);
    }
    void print()
    {
        std::cout << "x:" << x << " "
                  << "y:" << y << std::endl;
    }

    friend ostream &operator<<(ostream &os, const Vector2 &other);
};

ostream &operator<<(ostream &os, const Vector2 &other)
{
    os << "x:" << other.x << " y:" << other.y;
    return os;
}

class Test
{
private:
    int id;
    string name;

public:
    Test() : id(0), name("")
    {
    }

    Test(int id, string name) : id(id), name(name)
    {
    }

    Test(const Test &rhs)
    {
        this->id = rhs.id;
        this->name = rhs.name;
    }

    const Test &operator=(const Test &other)
    {
        this->id = other.id;
        this->name = other.name;
        return *this;
    }
    bool operator==(const Test &t2) const
    {
        if ((this->id == t2.id) && (this->name == t2.name))
            return true;

        return false;
    }

    bool operator!=(const Test &t1) const
    {
        return !(*this == t1);
    }

    Test operator+(const Test &a)
    {
        return Test(a.id + this->id, a.name + this->name);
    }

    friend ostream &operator<<(ostream &out, const Test &rhs);

    ~Test()
    {
    }
};

ostream &operator<<(ostream &out, const Test &rhs)
{
    out << rhs.id << ":" << rhs.name;
    return out;
}
int main(int argv, char *argc[])
{
    Vector2 distance(2.0f, 3.0f);
    Vector2 distance2(4.0f, 5.0f);
    Vector2 totalDistance = distance + distance2;
    std::cout << distance2 << endl;

    Test test1(30, "yasser");
    Test test2(10, "nabila");

    if (test1 != test2)
    {
        cout << "Objects are not same " << endl;
    }

    Test test3(20, "yasser");
    test3 = test1 + test2 + test2;

    // cout << test3 << endl;

    // totalDistance.print();
}