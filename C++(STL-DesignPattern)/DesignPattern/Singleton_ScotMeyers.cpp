#include<bits/stdc++.h>
using namespace std;
class Singleton {

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    Singleton(Singleton const& arg) = delete;
    void operator = (Singleton const& arg) = delete;

private:
    Singleton() {
        cout << " Created " << endl;
    }

    ~Singleton() {
        cout << " Destroyed " << endl;

    }
};

int main() {
    vector<thread> threads;
    for (auto i = 0; i < 10; i++) {
        threads.push_back(thread([]() {Singleton::getInstance();}));
    }
    for (auto& thread : threads) {
        if (thread.joinable())
            thread.join();
    }
    return 0;
}