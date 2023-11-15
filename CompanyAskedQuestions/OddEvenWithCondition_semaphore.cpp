//C++20 required for semaphore

#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>
#include <chrono>
#include <iostream>
#include <semaphore>
#include <thread>

using namespace std;

int g_count = 1;

binary_semaphore signalOdd{1}, signalEven{0};

void printEven() {
    while (g_count < 10) {

        signalEven.acquire();
        cout << "Even Print " << g_count << endl;
        g_count++;
        signalOdd.release();
    }
}

void printOdd() {
    while (g_count < 10) {

        signalOdd.acquire();
        cout << "Odd Print " << g_count << endl;
        g_count++;
        signalEven.release();
    }
}

int main() {
    thread t1(printOdd);
    thread t2(printEven);

    t1.join();
    t2.join();
}