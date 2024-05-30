// 3. Longest Substring Without Repeating Characters
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string const& inp) {
    size_t l = 0, r = 1, sz = inp.size(), maxV = 0;
    unordered_set<char> charSet{ inp[0] };
    if (sz == 1) return 1;
    while (r < sz) {
        if (charSet.count(inp[r]) == 0) {
            charSet.insert(inp[r]);
            maxV = max(maxV, charSet.size());
            r++;
        }
        else {
            while (charSet.count(inp[r]) > 0)
            {
                charSet.erase(inp[l]);
                l++;
            }
        }
    }

    return maxV;
}

int main() {
    {
        string inp = "abcabcbb";
        size_t res = lengthOfLongestSubstring(inp);
        assert(3 == res);
    }
    cout << "success" << endl;
    return 0;
}