#include <iostream>
#include <fstream>
#include <optional> // demo usage of optional Data Type

std::optional<std::string> ReadFileAsString(std::string filePath)
{
    std::ifstream Inputstream(filePath);

    if (Inputstream)
    {
        std::string result; //read file here
        Inputstream.close();
        return result;
    }
}

int main()
{
    std::optional<std::string> Data = ReadFileAsString("data.txt");

    std::string value = Data.value_or("sorry");
    (void)value;
    if (Data.has_value()) // if(Data)
    {
        std::cout << "data read successfully \n";
    }
    else
    {
        std::cout << "data could not be read \n";
    }

    std::optional<int> count = Data.value_or(100); // give me the count variable value in the file or else give me 100
    std::cout << count;
    std::string &stringData = *Data; // can be accessed like normal string - Data->
    (void)stringData;
    return 0;
}