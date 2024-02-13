#include <iostream>
#include <cstdint>
#include <cstdio>   // Add this header for printf
#include <algorithm> // Add this header for swap
#include <cassert>

// initial=abcd1234 , final=3412cdab 
using namespace std;
void  foo_revByte(uint32_t* pInpOp32)
{
    uint8_t itr;

    uint8_t* pInpOp8 = (uint8_t*)pInpOp32;

    uint8_t  len = sizeof(uint32_t);

    for (itr = 0; itr < len / 2; itr++) {
        swap(pInpOp8[itr], pInpOp8[len - itr - 1]);
    }



}

int main(void)
{
    uint32_t a0;
    a0 = 0xABCD1234;
    foo_revByte(&a0);
    printf("%X\n", a0);

    // Test the result using assert
    assert(a0 == 0x3412CDAB);
    return 0;
}
