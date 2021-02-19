//https://www.hackerrank.com/challenges/flipping-bits/problem?h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>
void complimentNthBit(uint16_t N);
using namespace std;
uint32_t data_32 =0;

// Complete the flippingBits function below.
long flippingBits(long n) {
    data_32 = n; 
    uint16_t count = 0;
    while (count < 32) {
        complimentNthBit(count);
        count++;
    }
    return data_32;
}
void complimentNthBit(uint16_t N)
{
    // check if bit is set or not
    bool mask = data_32 & (1 << N);

    //toggle the bit
    if (mask == false)
    {
        //set
        uint32_t maskToSet = (!mask) << N;
        data_32 = data_32 | maskToSet;
    }
    else
    {  
        //reset
        uint32_t maskToSet = ~(mask << N);
        data_32 = data_32 & maskToSet;
    }
}