#include <iostream>
#include <exception>
#include <fstream>
#pragma pack(push, 1)
struct TestingPadding
{
    char ch;
    int i;
};
#pragma pack(pop)

int main()
{
    std::fstream binaryFile;
    binaryFile.open("test.bin", std::ios::out | std::ios::binary);
    TestingPadding tstruct;
    tstruct.ch = 'A';
    tstruct.i = 786;

    if (binaryFile.is_open())
    {
        binaryFile.write((char *)&tstruct, sizeof(tstruct));
        binaryFile.close();
    }
    else
    {
        std::cout << "Unable to open File " << std::endl;
    }

    TestingPadding st2;
    std::fstream binStream;
    binStream.open("test.bin", std::ios::in | std::ios::binary);
    if (binStream.is_open())
    {
        binStream.read((char *)&st2, sizeof(st2));
        std::cout << st2.ch << " " << st2.i << std::endl;
        binStream.close();
    }
    else
    {
        std::cout << "Cannot Open file for reading" << std::endl;
    }

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