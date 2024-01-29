//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

// Beats 50 % of other solutions, Check back again to improve time 

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> result(nums.size());
        for (uint32_t i = 0; i < nums.size(); i++) {
            result[(k + i) % nums.size()] = nums[i];
        }
        nums = move(result); // move is taking more time/ why ?
    }
};

int main() {
    Solution obj;
    vector<int> input{ 1,2,3,4,5,6,7 };
    obj.rotate(input, 3);
    for (auto num : input) {
        cout << num << "\t";
    }
    return 0;
}