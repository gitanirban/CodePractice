#include <stdio.h>
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

 typedef struct {
    int a;
    int b;
    int c;
}A;
int main() {
    printf("Hello, World!\n");
    printf("%d",OFFSETOF( A,c));
    return 0;
}
