#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

int count = 1;
mutex m;
condition_variable cond;
bool evenReady = true;

void printEven() {
    while (count < 10) {
        unique_lock<mutex> lock(m);
        cond.wait(lock, [] { return evenReady; });

        cout << "Even Print " << count << endl;
        count++;
        evenReady = false; // Toggle ready status for the next turn

        cond.notify_one(); // Notify the odd thread
    }
}

void printOdd() {
    while (count < 10) {
        unique_lock<mutex> lock(m);
        cond.wait(lock, [] { return !evenReady; });

        cout << "Odd Print " << count << endl;
        count++;
        evenReady = true; // Toggle ready status for the next turn

        cond.notify_one(); // Notify the even thread
    }
}

int main() {
    thread t1(printOdd);
    thread t2(printEven);

    t1.join();
    t2.join();

    return 0;
}
