#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//T = O(n * k) for processing all strings, where n is the total number of strings and k is the maximum length of a string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto& s : strs) {
            string key = generateKey(s);
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (const auto& pair : mp) {
            res.push_back(pair.second);
        }
        return res;
    }

private:
    string generateKey(const string& s) {
        // Initialize an array to count the frequency of each character
        int count[26] = { 0 };
        // Count the frequency of each character in the string
        for (char c : s) {
            count[c - 'a']++;
        }
        // Generate a unique key based on the character frequency counts
        string key;
        for (int i = 0; i < 26; ++i) {
            key += to_string(count[i]); // Use "#" as a separator
        }
        return key;
    }
};

//Sorting each string s to generate the key takes O(klogk) time, where k is the length of the longest string.
//Inserting the string into the unordered map takes O(1) on average, assuming that the hash function distributes the keys uniformly.
//Therefore, the overall time complexity is O(n * klogk).

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& key : map) {
            res.push_back(key.second);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> result = sol.groupAnagrams(strs);
    cout << endl;
    for (const auto& group : result) {
        cout << "[";
        for (int i = 0; i < group.size(); ++i) {
            cout << group[i];
            if (i != group.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
