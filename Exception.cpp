#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

void ExceptionTesting(void)
{
    bool error = true;
    bool error1 = true;
    if (error)
    {
        cout << __func__ << endl;
        throw runtime_error("Primitive String Exception thrown");
    }
    else if (error1)
    {
        cout << "trying two throws of same argument type" << endl;
        throw string("2nd Primitive string Exception thrown");
    }
}

void wrapingExceptionTesting()
{
    ExceptionTesting();
}

class CanGoWrong
{
public:
    CanGoWrong()
    {
        char *pMemory = new char[99999999999999999]; // returning something from constructor as an exception
        (void)pMemory;
        delete[] pMemory;
    }
};

int main()
{
    try
    {
        CanGoWrong wrong;
    }
    catch (std::bad_alloc &e) // bad_alloc is derived from exception class
    {
        cout << " Exception caught : " << e.what() << endl;
    }
}

int main()
{
    try
    {
        wrapingExceptionTesting(); //ExceptionTesting();
    }
    catch (int e)
    {
        cout << "inside Int catch" << endl;
        cout << e << '\n';
    }
    catch (string &e)
    {
        cout << "inside string Exception catch" << endl;
        cout << e << '\n';
    }
    catch (const std::exception &e)
    {
        cout << "inside std::Exception catch" << endl;
        cout << e.what() << '\n';
    }

    cout << "still running " << endl;
}

////////////-----MY EXCEPTION CLASS ------/////////////

class MyException : public std::exception
{
public:
    virtual const char *what() const throw() // can list type of exception that can be thrown from my what func
    {
        return "MyExceptions what is called Exception occurred"; // overriding the base class what()
    }
};

class Test
{
public:
    void TestingMyException()
    {
        throw MyException(); // syntax used is like a func call but we are throwing/passing myException class
    }
};

int main()
{
    Test test;
    try
    {
        test.TestingMyException();
    }
    catch (const MyException &e) // NOTE: always catch derived exception first then base Exception in order to avoid any misbehavior due to polymorphism.
    {
        // exception has happened do what to needs to be done
        cout << e.what();
        cout << setprecision(17); // set floating point precision
    }
}

class Exception2 : public std::exception
{
    virtual const char *what() throw(std::bad_alloc) // cannot throw exception from this function throw(std::bad_alloc) meaning can only throw bad alloc exception
    {
        std::cout << "you fucked up ! " << endl;
    }
};

class Testing
{
public:
    Testing()
    {
        std::cout << "constructor";
    }
};

void testingExceptionSequence(void)
{
    bool error1 = true;
    if (error1)
        throw std::bad_alloc();

    bool error2 = false;
    if (error2)
        throw exception();
}

int main()
{
    try
    {
        testingExceptionSequence();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << endl; // this gets executed so avoid always set derived class first
    }
    catch (std::bad_alloc &e)
    {
        std::cout << e.what() << endl;
    }
}