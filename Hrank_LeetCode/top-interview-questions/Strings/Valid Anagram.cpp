// Valid Anagram
#include<bits/stdc++.h>
#include<cstdint>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, uint32_t> map_s;
        unordered_map<char, uint32_t> map_t;

        if (s.size() != t.size())
            return false;

        for (uint32_t idx = 0; idx < t.size(); idx++) {
            ++map_s[s[idx]];
            ++map_t[t[idx]];
        }
        return (map_s==map_t);
    }
};

int main() {
    Solution obj;
    string s = "rat";
    string t = "car";
    cout << obj.isAnagram(s, t) << endl;
    return 0;
}