//Longest Common Prefix

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string res = "";

        if (strs.empty()) {
            return res;
        }

        for (size_t i = 0; i < strs[0].length(); i++) {
            for (const std::string& s : strs) {
                if (i == s.length() or s[i] != strs[0][i])
                    return res;
            }
            res += strs[0][i];
        }

        return res;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> input = { "flower", "flow", "flight" };
    std::string result = solution.longestCommonPrefix(input);
    std::cout << "Longest Common Prefix: " << result << std::endl;

    return 0;
}


int main1() {

    Solution s;
    vector<string> strs = { "flower","flow","flight" };
    s.longestCommonPrefix(strs);
    return 0;
}