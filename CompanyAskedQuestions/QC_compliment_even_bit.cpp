// ConsoleApplication2_compliment_even_bit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdint>
using namespace std;

uint32_t getNexthighestPower(uint32_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

int main()
{
    const uint64_t EVEN_BIT_MASK = 0x55'55'55'55'55;

    uint32_t input = 0;
    uint32_t result = input ^ EVEN_BIT_MASK;
    result &= (getNexthighestPower(input) - 1U);
    cout << result << endl;
}