#include <iostream>
#include <fstream>
using namespace std;
int main(int argv, char *argc[])
{
    std::string fileName = argc[1];
    std::fstream inFile;
    inFile.open(fileName, std::ios::out);
    if (inFile.is_open())
    {
        while (!inFile.eof()) // while(inFile) will also work because fstream class has overloaded operator
        {
            std::string line;
            getline(inFile, line);
            std::cout << line << std::endl;
        }
        inFile.close();
    }
    else
    {
        std::cout << "File not found." << fileName << std::endl;
    }

    return 0;
}