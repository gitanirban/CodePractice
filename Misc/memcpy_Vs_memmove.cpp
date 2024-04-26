 
 
 
 #include <stddef.h> /* for size_t */
#include <stdlib.h> /* for memcpy */

#include <stddef.h> /* size_t */
void* memcpy(void* dest, const void* src, size_t n)
{
    char* dp = dest;
    const char* sp = src;
    while (n--)
        *dp++ = *sp++;
    return dest;
}

void* memmove(void* dest, const void* src, size_t n)
{
    unsigned char tmp[n];
    memcpy(tmp, src, n);
    memcpy(dest, tmp, n);
    return dest;
}