#include <iostream>
#include <cstdint>
using namespace std;
// reset the first bit(0), toggle the 2nd bit(1th), and set the 4th bit(3rd).
int main()
{
    cout << "Hello world!" << endl;

    uint32_t value = 0b0001;
    int pos = 1;
    uint32_t res=0;
    //set
    res = value | (1<<pos); // 0b0011;
    printf("%d\n",res);


    //reset
    pos = 0;
    res = value & ~(1<<pos); // 0b000;
    printf("%d\n",res);


    //toggle
    pos = 0;

    res = value ^ (1<<pos); // 0b000;
    printf("%d\n",res);

    //toggle
    value = 0b0000;
    res = value ^ (1<<pos); // 0b000;
    printf("%d\n",res);

    return 0;
}
