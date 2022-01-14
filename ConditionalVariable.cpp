#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m;
int balance = 0;

void addMoney(int money)
{
    std::lock_guard<mutex> lg(m); // locks the mutex and unlocks it when its out of scope
    balance += money;
    cout << "Money Added successful Balance = " << balance << endl;
    cv.notify_one(); // notify waiting threads to continue ->
    //mutex unlocked as it is out of scope
}

void withDrawMoney(int money)
{
    unique_lock<mutex> ul(m);
    cv.wait(ul, []
            { return balance != 0 ? true : false; });
    balance -= money;
    cout << "Money withdraw successful Balance = " << balance << endl;
}

int main()
{
    thread t1(withDrawMoney, 500);
    this_thread::sleep_for(std::chrono::seconds(3));
    thread t2(addMoney, 500);
    t1.join();
    t2.join();
    return EXIT_SUCCESS;
}