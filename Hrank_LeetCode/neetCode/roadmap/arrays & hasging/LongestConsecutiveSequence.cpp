#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0;
        int max_count = 0;

        sort(nums.begin(), nums.end());
        for (auto idx = 1; idx < nums.size(); idx++) {
            if (nums[idx - 1] + 1 == nums[idx]) {
                count++;
            }
            else {
                max_count = max(count, max_count);
                count = 0;
            }
            max_count = max(count, max_count);
        }
        return nums.size() == 0 ? 0 : max_count + 1;
    }
};

int main() {
    Solution s;
    {
        vector<int> input = { 100,4,200,1,3,2 };
        assert(s.longestConsecutive(input) == 4);
    }
    {
        vector<int> input = { 0,3,7,2,5,8,4,6,0,1 };
        assert(s.longestConsecutive(input) == 9);
    }
    {
        vector<int> input = { 1,2,0,1 };
        assert(s.longestConsecutive(input) == 3);
    }
    return 0;
}