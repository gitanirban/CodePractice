#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

 // initial=abcd1234 , final=3412cdab 

void  foo_revByte(uint32_t *pInpOp32 )
{
    uint8_t itr,tmp;

    uint8_t *pInpOp8 = (uint8_t *)pInpOp32;

    uint8_t  len = sizeof (uint32_t);

    for(itr=0; itr < len / 2; itr++) {
        tmp = *(pInpOp8 + itr);
        *(pInpOp8 + itr ) = *(pInpOp8 + len - itr - 1);
        *(pInpOp8 + len - itr - 1)= tmp;
    }


}

int main(void)
{
    uint32_t a0;
    a0=0xABCD1234;
    foo_revByte(&a0);
    printf("%X\n",a0);

    return 0;
}
