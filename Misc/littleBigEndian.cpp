//little big endian
#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    cout << "Hello World!\n";
    uint32_t value = 0x01;
    uint8_t test = ~0;

    uint8_t* pTtest = (uint8_t*)&value;

    printf("%d", *pTtest);

    unsigned int i = 1;
    char* c = (char*)&i;
    if (*c)
        printf("Little endian");
    else
        printf("Big endian");
}