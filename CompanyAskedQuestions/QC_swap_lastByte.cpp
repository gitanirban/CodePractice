// Q SWAP LAST BYTE

#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    uint32_t val = 0x12345678;
    uint32_t F_word = val & 0xFFFF0000;
    uint32_t S_word = val & 0xFFFF;
    uint32_t res;
   // printf("%x\n",S_word);

    S_word = ((S_word <<8) & 0xFFFF) |  ((S_word >>8));

    S_word = S_word | F_word;

  //  printf("%x\n",val);

    //printf("%x\n",F_word);
    printf("%x\n",S_word);


    return 0;
}