//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/
// explanation https://www.youtube.com/watch?v=DEJAZBq0FDA (py)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        uint32_t left = 1;
        for (uint32_t right = 1; right < nums.size(); right++) {
            if(nums[right] != nums[right -1]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};

int main() {

    Solution obj;
    vector<int> input{ 0,0,1,1,1,2 };
    cout << obj.removeDuplicates(input) << endl;

}