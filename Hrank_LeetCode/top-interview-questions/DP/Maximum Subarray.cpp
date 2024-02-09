// Maximum Subarray
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], curSum = 0;

        for (auto n : nums) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += n;
            maxSub = max(maxSub, curSum);

        }

        return maxSub;
    }
};