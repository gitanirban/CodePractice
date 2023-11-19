// C++ program to Count set
// bits in an integer

// one cpu instruction to solve the problem : https://vaibhavsagar.com/blog/2019/09/08/popcount/
// https://stackoverflow.com/questions/109023/count-the-number-of-set-bits-in-a-32-bit-integer

#include <iostream>
#include <cstdint>

using namespace std;

unsigned int bits_counter_v4(unsigned int x) {
    // count bits of each 2-bit chunk
    x  = x - ((x >> 1) & 0x55555555);
    // count bits of each 4-bit chunk
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    // count bits of each 8-bit chunk
    x = x + (x >> 4);
    // mask out junk
    x &= 0xF0F0F0F;
    // add all four 8-bit chunks
    return (x * 0x01010101) >> 24;
}

/* Program to test function countSetBits */
int main()
{
    cout << bits_counter_v4(0xF) << endl; 
    return 0;
}
