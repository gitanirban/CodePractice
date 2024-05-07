/*
    @brief Using Divide and Conquer algorithm to find the Highest Bit set(Most Significant Bit) of a 32 bit number.

    The function findMSbitBinSearch(uint32_t input) uses Binary Search alogrithm to find the set MSBit.

    @param  `input` has to be supplied with setting all the bits after the `Set` Most Significant bit (MSSB).
            As Binary Search requires a Sorted Array, in this case, we have to pre-set the right side of the `Set` Most Significant Bit.
*/

#include<bits/stdc++.h>
using namespace std;

uint32_t setAllBitsAfterHighstSetMSB(uint32_t input) {
    if (input == 1) return 1;

    uint32_t res = input - 1;
    res |= res >> 1;
    res |= res >> 2;
    res |= res >> 4;
    res |= res >> 8;
    res |= res >> 16;

    return res < input ? (res | res + 1) : res;

}
bool ifSet(uint32_t input, uint32_t bitPos) {
    return input & (1 << (bitPos));
}

uint32_t findMSbitBinSearch(uint32_t input) {
    int32_t res = 0, left = 0, right = (sizeof(uint32_t) * 8) - 1U;

    while (right >= left - 1 and right >= 0) {
        if (ifSet(input, right)) {
            return right;
        }
        else {
            int32_t mid = ((right + left) / 2);
            if (ifSet(input, mid)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return res;
}

int main() {
    for (auto idx = 1; idx < 1024;idx++) {
        assert(findMSbitBinSearch(setAllBitsAfterHighstSetMSB(idx)) == floor(log2(idx)));
    }

    return 0;
}
