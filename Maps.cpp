#include <map>
#include <iostream>

using namespace std;

class Person
{
private:
    int age;
    string name;

public:
    Person(int age = 0, string name = "") : age(age), name(name)
    {
    }

    Person(const Person &other)
    {
        age = other.age;
        name = other.name;
    }

    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }

    void print(void) const
    {
        cout << "name -" << name << " age -" << age << endl;
    }
};

int main()
{
    map<int, Person> mp;
    mp[1] = Person(10, "nabila");
    mp[2] = Person(15, "ariba");
    mp[3] = Person(20, "Rafai");
    for (map<int, Person>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        // it->second.print();
    }

    map<Person, int> mp2;
    mp2[Person(10, "Tatti")] = 10;
    mp2[Person(20, "poopz")] = 20;

    for (map<Person, int>::iterator it = mp2.begin(); it != mp2.end(); ++it)
    {
        it->first.print();
    }
}