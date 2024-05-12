#include <bits/stdc++.h>
using namespace std;

uint32_t setAllBitsAfterHighstSetMSB(uint32_t input) {
    if (input == 0) return 0;

    input |= input >> 1;
    input |= input >> 2;
    input |= input >> 4;
    input |= input >> 8;
    input |= input >> 16;

    return input;
}

bool ifSet(uint32_t input, uint32_t bitPos) {
    return input & (1 << bitPos);
}

uint32_t findMSbitBinSearch(uint32_t input) {
    int32_t res = -1, left = 0, right = (sizeof(uint32_t) * 8) - 1;

    while (right >= left) {
        int32_t mid = (left + right) / 2;
        if (ifSet(input, mid)) {
            res = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    for (auto idx = 1; idx < 1024; idx++) {
        auto res = setAllBitsAfterHighstSetMSB(idx);
        cout << idx << "\t" << res << "\t" << std::bitset<sizeof(res) * 8>(res) << endl;
    }
    cout << "end" << endl;

    return 0;
}
