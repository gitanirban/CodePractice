// find the max repeating substring
#include<bits/stdc++.h>
using namespace std;

string maxRepeatingSubstring(string const& rInp) {
    string resMax;
    unordered_set<string> set;
    size_t sz = rInp.size();
    for (auto i = 0; i < sz; i++) {
        for (auto j = 1; j <= sz - i; j++) {
            string subStr = rInp.substr(i, j);
            if (set.count(subStr) and subStr.size() > resMax.size()) {
                resMax = subStr;
            }
            else {
                set.insert(subStr);
            }
        }
    }
    return resMax;
}

int main() {

    assert( maxRepeatingSubstring("abcdab") == "ab");
    assert( maxRepeatingSubstring("abcda") == "a");
    assert( maxRepeatingSubstring("abcdabcd") == "abcd");

    
    return 0;
}