// https://www.lintcode.com/problem/659/description

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    static string encode(vector<string>& strs) {
        string res;
        for (auto& s : strs) {
            res.append(to_string(s.size()));
            res.append("#");
            res.append(s);
        }
        return res;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    static vector<string> decode(string& str) {
        vector<string> res;
        for (int start = 0; start < (str.length()); ) {
            uint32_t indexOfSize = start;
            while (str[indexOfSize] != '#') indexOfSize++;
            size_t size = stoi(str.substr(start, indexOfSize));
            res.push_back(str.substr(indexOfSize + 1, size));
            start += size + sizeof('#') + 1;
        }

        return res;
    }
};


int main() {
    vector<string> input = { "lint","code","love","you" };
    string encoded = Solution::encode(input);

    vector<string> output = Solution::decode(encoded);
    assert(input == output);

    return 0;
}