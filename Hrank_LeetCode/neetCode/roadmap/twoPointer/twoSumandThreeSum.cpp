// two sum
// 1 indexed

#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] + nums[r] == target)
            return { l + 1, r + 1 };
        else if (nums[l] + nums[r] > target)
            r--;
        else if (nums[l] + nums[r] < target)
            l++;

    }

    return {};
}


vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (auto idx = 0U; idx < nums.size(); idx++) {
        if (idx > 0 and nums[idx] == nums[idx - 1])
            continue;

        int l = idx + 1, r = nums.size() - 1;
        while (l < r)
        {
            int threeSum = nums[l] + nums[r] + nums[idx];
            if (threeSum == 0) {
                res.push_back({ nums[idx] ,nums[l],  nums[r] });
                l++;
                while (nums[l] == nums[l - 1] and l < r)l++;
            }
            else if (threeSum > 0)
                r--;
            else if (threeSum < 0)
                l++;

        }
    }
    return res;
}

int main() {
    {
        vector<int> arr = { 2,7,11,15 };
        int target = 9;

        vector<int> res = { 1,2 };
        assert(res == twoSum(arr, target));
    }
    {
        vector<int> arr = { -1,0,1,2,-1,-4 };

        vector <vector<int>> res = { {-1,-1,2},
                                     {-1,0,1}
        };
        assert(res == threeSum(arr));
    }

    cout << endl << "success";
    return 0;
}