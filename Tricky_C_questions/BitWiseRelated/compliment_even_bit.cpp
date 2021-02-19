// ConsoleApplication2_compliment_even_bit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdint>
using namespace std;
void complimentNthBit(uint8_t);
uint32_t data_32 = 0x1234;

int main()
{
    std::cout << "Before" <<endl;
    //printf("%b \n", data_32);
    printf("%x \n", data_32);
    uint8_t count = 0;
    while (count < 16) {
        if (count % 2 == 0)
        {
            complimentNthBit(count);
        }

        count++;
    }
    std::cout << "\n\n\nafter\n";
   // printf("%b \n", data_32);
    printf("%x \n", data_32);
}

void complimentNthBit(uint8_t N) {

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