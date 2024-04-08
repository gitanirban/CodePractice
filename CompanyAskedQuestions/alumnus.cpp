
#include<bits/stdc++.h>
using namespace std;


#define SET_4BIT_NUMBERS(byte, num1, num2) \
  ((byte) |= ((num1 << 4) | (num2 & 0xF)))

// Store two 4 bit number in a byte.
int main2() {
    unsigned char byte = 0;
    int num1 = 3, num2 = 7;

    SET_4BIT_NUMBERS(byte, num1, num2);

    printf("Byte with two 4-bit numbers: 0x%02X\n", byte);

    return 0;
}

int main() {
    // Add code in the Missing part, to print a,b,c 
    char a[] = "Alumnus ";
    char b[] = "Software ";
    char c[] = "Ltd";

    int i;

    char** p = NULL; // Initialize as null pointer

    // Missing code start

    p = (char**)malloc(3 * sizeof(char*));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    p[0] = a;
    p[1] = b;
    p[2] = c;

    // Missing code end;

    for (i = 0; i < 3; i++) {

        printf("%s", p[i]);

    }

    // Free the allocated memory (important to prevent memory leaks)
    free(p);

    return 0;
}