#include <iostream>

class Student
{
private:
    int id{0};
    std::string name{"null"};

public:
    Student() = default;
    Student(const Student &st) = default;
    Student &operator=(const Student &st) = default;
    // Student &operator=(const Student &st) = delete;
};

int main()
{
    Student st;
    Student st2 = st;
    st2 = st;
}