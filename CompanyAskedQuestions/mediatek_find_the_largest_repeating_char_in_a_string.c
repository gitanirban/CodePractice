#include <stdio.h>

int main() {
    const char* pString = "aabbbcccc";
    int charCounts[26] = { 0 }; // Assuming a-z characters

    // Count occurrences of each character
    for (const char* p = pString; *p != '\0'; ++p) {
        charCounts[(unsigned char)*p - 'a']++;
    }

    // Find the character with the maximum count
    char maxChar = '\0';
    int maxCount = 0;
    for (int i = 0; i < 26; ++i) {
        if (charCounts[i] > maxCount) {
            maxChar = (char)i + 'a';
            maxCount = charCounts[i];
        }
    }

    // Find the index of the last occurrence of the character
    int lastIndex = -1;
    for (int i = 0; pString[i] != '\0'; ++i) {
        if (pString[i] == maxChar) {
            lastIndex = i;
            break;
        }
    }

    printf("Index of the largest repeating character (%c): %d\n", maxChar, lastIndex);

    return 0;
}
