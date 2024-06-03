#include <iostream>
#include <cstdint>

using namespace std;

class test {
private:
    int var;

    public:
    test() : var(7) {}

    void operator ++()
    {
        var = var + var * var - var;
    }
    void fun() {
        cout << var << endl;
    }
};

int main() {
    test t;
    ++t;
    t.fun();
    return 0;
}