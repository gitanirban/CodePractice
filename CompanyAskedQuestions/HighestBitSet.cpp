#include<bits/stdc++.h>
using namespace std;

 
bool ifSet(uint32_t input, uint32_t mask) {
    return input & (1 << mask);
}
 
uint32_t binSearch(uint32_t input, uint32_t left, uint32_t right) {
    int32_t res = -1;  

    while (right > left) {
        uint32_t mid = ((right + left) / 2);
        // check mid
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
    assert(binSearch(8, 0, 31) == floor(log2(8)));
    assert(binSearch(9, 0, 31) == floor(log2(9)));
    //  assert(binSearch(32, 0, 31) == floor(log2(32)));
    assert(binSearch(2, 0, 31) == floor(log2(2)));
    //  assert(binSearch(256, 0, 31) == floor(log2(256)));


    return 0;
}
