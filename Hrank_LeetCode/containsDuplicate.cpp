//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset(nums.size());
        bool return_v = false;
        for (uint32_t i = 0; i < nums.size(); i++) {
            if (uset.find(nums[i]) == uset.end()) {
                uset.insert(nums[i]);
            }
            else {
                return_v = true;
            }
        }
        return return_v;
    }
};

int main() {
    Solution obj;
    vector<int> input{ 1,5,-2,-4,0 };
    cout << obj.containsDuplicate(input) << endl;

    return 0;
}

