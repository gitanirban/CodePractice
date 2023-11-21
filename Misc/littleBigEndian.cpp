// little big endian
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    uint32_t value = 0x44332211;
    //                MSB    LSB

    uint8_t *pTtest = (uint8_t *)&value;

    printf("Data at lowest address: 0x%x\n", *pTtest);

    if (*pTtest == 0x11)
    {
        printf("Little endian: As lowest address has MSB\n");
        printf("Data: 0x44 0x33 0x33 0x22 0x11\n");
        printf("Add : 0x00 0x01 0x02 0x03 0x04\n");
    }
    else
        printf("Big endian");
}