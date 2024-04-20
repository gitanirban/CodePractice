// Top k elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> uMap;

        for (auto& n : nums) {
            uMap[n]++;
        }

        map<int, vector<int>> oMap;
        for (auto pair : uMap) {
            oMap[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for (auto itr = oMap.begin(); k > 0 && itr != oMap.end(); itr++) {
            for (int& n : itr->second) {
                res.push_back(n);
                k--;

            }
        }

        return res;
    }
};


class SolutionNeetCode {
public:
    static std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        std::vector<std::vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n]++;
        }

        for (const auto& pair : count) {
            freq[pair.second].push_back(pair.first);
        }

        std::vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res; // In case k > nums.size()
    }
};


int main() {

    SolutionNeetCode s;

    vector<int > arr = { 1,1,1,2,2,3 };
    vector <int >res = { 1,2 };
    assert(s.topKFrequent(arr, 2) == res);

    vector<int > arr2 = { -1,-1 };
    vector <int >res2 = { -1 };
    assert(s.topKFrequent(arr2, 1) == res2);

    vector<int > arr3 = { 1, 2 };
    vector <int >res3 = { 1, 2 };
    assert(s.topKFrequent(arr3, 2) == res3);


    return 0;
}