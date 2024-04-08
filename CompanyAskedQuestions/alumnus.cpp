
#include<bits/stdc++.h>
using namespace std;


#define SET_4BIT_NUMBERS(byte, num1, num2) \
  ((byte) |= ((num1 << 4) | (num2 & 0xF)))

int main() {
    unsigned char byte = 0;
    int num1 = 3, num2 = 7;

    SET_4BIT_NUMBERS(byte, num1, num2);

    printf("Byte with two 4-bit numbers: 0x%02X\n", byte);

    return 0;
}

int main() {

    char a[] = "Alumnus ";
    char b[] = "Software ";
    char c[] = "Ltd";

    int i;

    char** p = NULL; // Initialize as null pointer

    // Allocate memory for the array of character pointers
    p = (char**)malloc(3 * sizeof(char*));

    // Check for allocation failure
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign addresses of string arrays to elements of p allocated memory
    p[0] = a;
    p[1] = b;
    p[2] = c;

    for (i = 0; i < 3; i++) {

        printf("%s", p[i]);

    }

    // Free the allocated memory (important to prevent memory leaks)
    free(p);

    return 0;
}