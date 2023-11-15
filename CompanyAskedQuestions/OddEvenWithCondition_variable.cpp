// this is not a optimised solution from stack over flow/
// another example : https://gist.github.com/jmurudi/7a2fc49e855cb0b308d19f277c7e12b7

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int count = 1;
mutex m;
bool evenReady = true;
condition_variable cond;

void printEven()
{
    while (count < 10)
    {
        unique_lock<mutex> lock(m);
        cond.wait(lock, []
                  { return evenReady; });
        evenReady = false;

        cout << "Even Print " << count<<endl;
        count++;
        cond.notify_all();
    }
}

void printOdd()
{
    while (count < 10)
    {
        unique_lock<mutex> lock(m);
        cond.wait(lock, []
                  { return !evenReady; });
        evenReady = true;

        cout << "Odd Print " << count <<endl;
        count++;
        cond.notify_all();
    }
}

int main()
{
    thread t1(printOdd);
    thread t2(printEven);

    t1.join();
    t2.join();

}