#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int countWords(const char *input) {
    int count = 0;
    bool inWord = false; // Flag to track if currently in a word

    for (int i = 0; input[i] != '\0'; i++) {
        // Check if current character is a space or newline
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            inWord = false; // Not in a word anymore
        }
        // Check if current character is a letter
        else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            // If not already in a word, increment count
            if (!inWord) {
                count++;
                inWord = true; // Now in a word
            }
        }
    }
    return count;
}

int main() {
    // Test cases
    const char *tests[] = {
        "",                     // Empty string
        "Hello",                // Single word
        "   ",                  // Single space
        "  Hello  World  ",     // Multiple spaces
        " Hello World",         // Leading spaces
        "Hello World  ",        // Trailing spaces
        "Hello World",          // Spaces between words
        "Hello   World",        // Consecutive spaces between words
        "Mix of letters and spaces",    // Mix of letters and spaces
        "Hello, World!",        // Special characters
        NULL                    // End marker for the array
    };

    // Expected results for test cases
    const int expectedResults[] = {0, 1, 0, 2, 2, 2, 2, 2, 5, 2};

    // Run the tests
    for (int i = 0; tests[i] != NULL; i++) {
        int result = countWords(tests[i]);
        assert(result == expectedResults[i]);
    }

    printf("All tests passed successfully!\n");

    return 0;
}
