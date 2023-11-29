
#include <iostream>
#include <cstdint>
#include <bits/stdc++.h> 
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

    uint32_t input = 0xA;
    uint32_t result = input ^ EVEN_BIT_MASK;
    result &= (getNexthighestPower(input) - 1U);
    cout << result << endl;

    return 0;
}

int main_using_loop()
{
    uint8_t input = 0x0A;
    uint8_t len = log2(getNexthighestPower(input));
    for (uint8_t idx = 0; idx < len; idx++)
    {
        if(idx %2 == 0)
        {
            input |= (1 << idx);
        }
    }
    cout << unsigned(input) << endl;

return 0;
}
