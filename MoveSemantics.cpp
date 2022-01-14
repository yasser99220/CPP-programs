#include <iostream>
#include <string.h>
#include <memory>
using std::cout;
using std::endl;
using std::string;
class String
{
private:
    char *m_Data{nullptr};
    uint32_t m_Size{0};

public:
    String() = default;
    String(const char *data)
    {
        cout << "Parameterized constructor Called !" << endl;
        m_Size = strlen(data);
        m_Data = new char[m_Size];
        memcpy(m_Data, data, m_Size);
    }
    ~String()
    {
        cout << "String Destroyed!!" << endl;
        delete[] m_Data;
    }

    String(const String &other)
    {
        cout << "Copy constructor called ! " << endl;
        m_Size = other.m_Size; // do i need to delete here before
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String &operator=(const String &other)
    {
        cout << "Normal assignment operator called!" << endl;
        delete[] m_Data;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
        return *this;
    }

    String &operator=(String &&other) noexcept
    {
        cout << "Move assignment operator called!" << endl;
        if (this != &other)
        {
            delete[] m_Data;
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);

            other.m_Data = nullptr; // after stealing the resource make the other object to a valid state
            other.m_Size = 0;       // otherwise when it goes out of scope it will delete the data and cause misbehavior
        }

        return *this;
    }

    String(String &&other) noexcept
    {
        cout << "move constructor called !" << endl;
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    void print()
    {
        for (int i = 0; i < m_Size; i++)
        {
            cout << m_Data[i];
        }
        cout << endl;
    }
};

class Entity
{
public:
    void PrintString()
    {
        str.print();
    }
    Entity() = default;

    Entity(const String &st) : str(st)
    {
        cout << "parameterized constructor for Entity called !" << endl;
    }

    Entity(String &&st) : str(std::move(st))
    {
        cout << "Move Constructor called for entity!" << endl;
    }

    ~Entity()
    {
        cout << "Entity destroyed " << endl;
    }

private:
    String str;
};

void printFullName(string &name)
{
    cout << name << endl;
}

void printFullName(string &&name)
{
    cout << name << endl;
}

int main()
{
    int i = 0;
    int val = i;
    int &Refval = i;
    int &&refRval = 10;
    string firstname = "Yasser";
    string lastname = "Mohammed";
    string fullname = firstname + lastname;
    // printFullName("Nabila");
    // printFullName(firstname + lastname);

    String Apple("Apple");
    String Dest;
    Dest = std::move(Apple);
    Apple.print();
    Dest.print();
}