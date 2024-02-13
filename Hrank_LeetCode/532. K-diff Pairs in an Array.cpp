#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findPairs(const vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int res = 0;

        for (auto n : nums) {
            map[n]++;
        }

        for (auto m : map) {
            if (k == 0) {
                if (m.second > 1)
                    res++;
            }
            else {
                if (map.find(m.first + k) != map.end())
                {
                    res++;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> input1{ 3,1,4,1,5 };
    assert(s.findPairs(input1, 2) == 2);


    vector<int> input2{ 1,2,3,4,5 };
    assert(s.findPairs(input2, 1) == 4);

    assert(s.findPairs({ 1,3,1,5,4 }, 0) == 1);

    assert(s.findPairs({ 1,1,1,1,1 }, 0) == 1);

    s.findPairs({ 1,1,1,2,2 }, 0);
    return 0;
}