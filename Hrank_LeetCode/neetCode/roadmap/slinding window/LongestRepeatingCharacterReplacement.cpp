//424. Longest Repeating Character Replacement
#include<bits/stdc++.h>
using namespace std;


int findLengthOfMostFreqUsedChar(unordered_map<char, int>const& inp) {
    int maxV = 0;
    for (auto item : inp) {
        maxV = max(item.second, maxV);
    }
    return maxV;
}

int characterReplacement(string s, int k) {

    size_t l = 0, r = 0, sz = s.size(), maxV = 0;
    unordered_map<char, int> count;

    if (sz == 1) return 1;

    while (r < sz) {
        count[s[r]]++;
        int mostFreqCharLen = findLengthOfMostFreqUsedChar(count);
        if (r - l + 1 - mostFreqCharLen <= k) {
            maxV = max(r - l + 1, maxV);
            r++;
        }
        else {
            count[s[l]]--;
            l++;
            r++;
        }
    }
    return maxV;
}


int main() {
    {
        string inp = "ABAB";
        int k = 2;
        size_t res = characterReplacement(inp, k);
        assert(4 == res);
    }
    {
        string inp = "AABABBA";
        int k = 1;
        size_t res = characterReplacement(inp, k);
        assert(4 == res);
    }
    return 0;
}