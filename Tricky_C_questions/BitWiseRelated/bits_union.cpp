#include <iostream>
#include <cstdint>

using namespace std;

union TestBits {
    struct {
        uint8_t b0: 1;
        uint8_t b1: 1;
        uint8_t b2: 1;
        uint8_t b3: 1;
        uint8_t b4: 1;
        uint8_t b5: 1;
        uint8_t b6: 1;
        uint8_t b7: 1;
    } bits;
    uint8_t byte;
};

int main() {
    volatile TestBits v1 = {};

    v1.bits.b1 = true;
    v1.bits.b3 = true;

    cout << static_cast<unsigned>(v1.byte) << endl;

    return 0;
}