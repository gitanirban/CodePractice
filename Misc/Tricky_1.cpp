//TRICKY QUESTION

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    foo();
    return 0;
}


void foo(void)

{

unsigned int a = 6;
int b = -20;
//((a+b) > 6) ? printf(“> 6”) : printf(“<= 6”);
unsigned int c = a + b;
if ((c) > 6)
    printf (" true");
}