// First Unique Character in a String

#include <bits/stdc++.h>
using namespace std;
class Solution1 {
public:
    int firstUniqChar(string s) {
        uint32_t freq[26] = {0,};
        for (auto idx = 0U; idx < s.size(); idx++) {
            ++freq[s[idx] - 'a'];
        }

        for (auto idx = 0U; idx < s.size(); idx++) {
            if (freq[s[idx] - 'a'] == 1)
                return idx;
        }

        return -1;

    }
};


int main() {
    string s = "loveleetcode";
    Solution1 obj;
    cout << obj.firstUniqChar(s) << endl;
    return 0;
}