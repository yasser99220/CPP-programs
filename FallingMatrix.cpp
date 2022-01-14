#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

const int width = 100;
const int flipsPerLine = 30;
const int sleepTime = 100;

int main()
{
    int i = 0, x = 0,
        srand(time(NULL));

    string chars = "1234567890qwertyuiopasdfghjklzxcvbnm,./';p[]!@%^*(()(%#@";
    int length = chars.length();
    int switches[width] = {0};

    system("Color 0A");
    while (true)
    {
        for (i = 0; i < width; i += 2)
        {
            if (switches[i])
            {
                cout << chars[rand() % length] << " ";
            }
            else
            {
                cout << " ";
            }
        }

        for (int i = 0; i < flipsPerLine; ++i)
        {
            x = rand() % width;
            switches[x] = !switches[x];
        }

        cout << endl;
        this_thread::sleep_for(chrono::milliseconds(sleepTime));
    }
    return EXIT_SUCCESS;
}