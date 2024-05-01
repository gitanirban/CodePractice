#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;


mutex m;
condition_variable cond;
bool evenReady = true;

void printEven() {
    int count = 0;
    while (count < 10) {
        unique_lock<mutex> lock(m);
        cond.wait(lock, [] { return evenReady; });

        cout << "Even Print " << count << endl;
        count += 2;
        evenReady = false; // Toggle ready status for the next turn

        cond.notify_one(); // Notify the odd thread
    }
}

void printOdd() {
    int count = 1;
    while (count < 10) {
        unique_lock<mutex> lock(m);
        cond.wait(lock, [] { return !evenReady; });

        cout << "Odd Print " << count << endl;
        count += 2;

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
