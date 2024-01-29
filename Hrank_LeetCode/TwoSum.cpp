#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();

    // Find the complement
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return { i, numMap[complement] };
        }
        numMap[nums[i]] = i;

    }

    return {}; // No solution found
}

int main() {

    vector<int> arr = { 2,7,11,15 };
    int target = 9;

    vector<int> res = twoSum(arr, target);
    for (auto i : res)
    {
        cout << i << "\t";
    }

    return 0;
}
