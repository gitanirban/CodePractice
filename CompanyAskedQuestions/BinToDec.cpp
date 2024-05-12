// BIN to Dec

#include <bits/stdc++.h>
using namespace std;


uint32_t binToDec(string const& rInp) {
    uint32_t res = 0U;
    int sz = rInp.size() - 1;
    for (int idx = sz, exp = 0U; idx >= 0; idx--, exp++) {
        uint32_t bit = rInp[idx] - '0';
        res += bit * pow(2, exp);
    }
    return res;
}
string decToBin(uint32_t inp) {
    string res = "";
    while (inp) {
        res.push_back((inp & 1) ? '1' : '0');
        inp >>= 1;
    }

    reverse(res.begin(), res.end());
    return res;
}
int main() {

    assert(binToDec("100") == 4);
    assert(decToBin(4) == "100");
    return 0;
}
