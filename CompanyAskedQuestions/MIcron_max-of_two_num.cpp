#include <iostream>
#include <cstdint>
using namespace std;
#include <iostream>

int max_of_two_numbers(int a, int b) {
    // Calculate the sign difference between a and b
    bool sign_diff = ((a - b) >> 31) & 1;

    // Use the sign difference to determine the maximum
    // If sign_diff is 0, then a is greater or equal, so return a
    // If sign_diff is 1, then b is greater, so return b
    return a - sign_diff * (a - b);
}

int main() {
    // Example usage:
    int result = max_of_two_numbers(99,1);
    std::cout << result << std::endl;  // Output: 8

    return 0;
}
