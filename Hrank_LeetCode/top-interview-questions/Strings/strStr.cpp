//strStr

// with tests with lamda

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(const string haystack, const string needle) {
        auto startPos = haystack.find(needle);
        if (startPos != string::npos)
            return startPos;
        return -1;
    }
};

int main1() {
    Solution obj;
    string haystack = "mississippi", needle = "issip";
    cout << obj.strStr(haystack, needle) << endl;
    return 0;
}


int main() {
    Solution obj;

    auto test = [&obj](const std::string& haystack, const std::string& needle, int expected) {
        int result = obj.strStr(haystack, needle);
        assert(result == expected);
        std::cout << "Test case: " << haystack << ", " << needle << " => " << result << " (Expected: " << expected << ")" << std::endl;
        };

    // Test cases
    test("mississippi", "issip", 4);
    test("sadbutsad", "sad", 0);

    // Additional test cases
    test("abcde", "", 0);
    test("abcdef", "xyz", -1);

    return 0;
}