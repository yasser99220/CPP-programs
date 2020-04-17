#include <iostream>
<<<<<<< HEAD
#include <memory>
=======
>>>>>>> 977e7aa94ba9117bd55f43a47e3d19caba405d2d
using namespace std;

struct test
{
    int i;
    int geti() { return i; }
};

std::unique_ptr<int> returnUnique(void)
{ // unique Ptr can be used as the return type compiler moves the ownership to other Ptr
    std::unique_ptr<int> tester{new int};
    return tester; // internally calls move for us
}
void takeOwnership(std::unique_ptr<test> tester)
{
    // have to call it with move as parameter
    // user tester
}
int main()
{
<<<<<<< HEAD

    std::unique_ptr<test> f{new test};

    takeOwnership(std::move(f)); //have to transfer ownership via move

    std::unique_ptr<int> test{new int};
    std::unique_ptr<int *> test2{new int *[5]};
    std::unique_ptr<int **> testdouble{new int **};
    auto f = std::move(test); // release ownership of f and transfer it to f

=======
>>>>>>> 977e7aa94ba9117bd55f43a47e3d19caba405d2d
    cout << "hello world" << endl;
    cout << " Thank you " << endl;
    return 0;
}
