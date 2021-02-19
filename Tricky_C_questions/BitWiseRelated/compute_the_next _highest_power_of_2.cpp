#include <iostream>

using namespace std;

int main()
{


    unsigned int v = 3; // compute the next highest power of 2 of 32-bit v

v--;
v |= v >> 1;
v |= v >> 2;
v |= v >> 4;
v |= v >> 8;
v |= v >> 16;
v++;

    cout << "output\t" << v<< endl;
    return 0;
}