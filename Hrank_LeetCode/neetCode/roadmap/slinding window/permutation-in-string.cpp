#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) return false;

    unordered_map<char, int> s1Map;
    unordered_map<char, int> s2Map;

    for (char c : s1) {
        s1Map[c]++;
    }

    // Initialize the window with the first s1.length() characters of s2
    for (size_t i = 0; i < s1.length(); i++) {
        s2Map[s2[i]]++;
    }

    // Sliding window
    size_t l = 0, r = s1.length() - 1;

    while (r < s2.length()) {
        if (s1Map == s2Map) return true;

        // Move window right
        r++;
        if (r < s2.length()) {
            s2Map[s2[r]]++;
            s2Map[s2[l]]--;
            if (s2Map[s2[l]] == 0) {
                s2Map.erase(s2[l]);
            }
            l++;
        }
    }
    return false;
}

int main() {
    // Example test cases
    {
        string s1 = "ab", s2 = "eidbaooo";
        bool res = checkInclusion(s1, s2);
        assert(true == res);
    }
    {
        string s1 = "adc", s2 = "dcda";
        bool res = checkInclusion(s1, s2);
        assert(true == res);
    }
    {
        string s1 = "dinitrophenylhydrazine", s2 = "acetylphenylhydrazine";
        bool res = checkInclusion(s1, s2);
        assert(false == res);
    }
    return 0;
}
