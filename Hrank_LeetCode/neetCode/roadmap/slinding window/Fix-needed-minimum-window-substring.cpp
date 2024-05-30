// needs fix 
// 76 minimum-window-substring

#include <bits/stdc++.h>
using namespace std;

bool isSuperset(const std::unordered_multiset<char>& superset, const std::unordered_multiset<char>& subset) {
    for (const char& element : subset) { // Corrected type to char
        if (superset.find(element) == superset.end()) {
            return false; // If any element of subset is not in superset
        }
    }
    return true; // All elements of subset are in superset
}

string minWindow(string s, string t) {
    if (t.length() > s.length()) return "";

    unordered_multiset<char> sSet;
    unordered_multiset<char> tSet;
    map<int, pair<int, int>> res;

    for (char c : t) {
        tSet.insert(c);
    }

    // Initialize the window with the first t.length() characters of s
    for (size_t i = 0; i < t.length(); i++) {
        sSet.insert(s[i]);
    }

    // Sliding window
    size_t l = 0, r = t.length() - 1;
    size_t minV = 0;

    while (r < s.length() && l < s.length()) { // Corrected the condition to &&
        if (sSet == tSet) { res[0] = make_pair(l, r); }
        if (isSuperset(sSet, tSet)) {
            res[r - l + 1] = make_pair(l, r);

            auto it = sSet.find(s[l]);
            if (it != sSet.end()) {
                sSet.erase(it);
            }
            l++;

        }
        else {
            if (++r < s.length()) {
                sSet.insert(s[r]);
            }
        }
    }

    if (!res.empty()) {
        auto it = res.begin();
        string resStr = { s.begin() + it->second.first, s.begin() + it->second.second + 1 }; // Adjusted to include the end character
        return resStr;
    }
    return "";
}

int main() {
    // {
    //     string s = "ADOBECODEBANC", t = "ABC";
    //     string res = minWindow(s, t);
    //     assert("BANC" == res);
    // }
    // {
    //     string s = "aa", t = "aa";
    //     string res = minWindow(s, t);
    //     assert("aa" == res);
    // }
    { 
        string s = "bbaa", t = "aba";
        string res = minWindow(s, t);
        assert("baa" == res);
    }
    return 0;
}
