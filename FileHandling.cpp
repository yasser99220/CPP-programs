#include <iostream>
#include <exception>
#include <fstream>
int main()
{
    std::ofstream output;
    std::string fileName = "demoFile.txt";
    try
    {
        output.open(fileName);
        if (output.is_open())
        {
            output << "Nabila";
            output << 123;
            output.close();
        }
        else
        {
            throw std::exception();
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}