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

class Solution {
public:
    bool containsDuplicateBetter(vector<int>& nums) {
        unordered_set<int> uset(nums.size());
        bool return_v = false;
        for (uint32_t i = 0; i < nums.size(); i++) {
            if (uset.find(nums[i]) != uset.end()) 
                return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};

// Find the single number 
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto i : nums) {
            res ^= i;
        }
        return res;
    }
};

//  Intersection of Two Arrays II
class Solution3 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> nums2Map;
        vector<int> res;
        for (auto n : nums2) {
            nums2Map[n]++;
        }
        for (auto n : nums1) {
            auto current = nums2Map.find(n);
            if (--nums2Map[n] >= 0) {
                res.push_back(n);
            }
        }
        return res;
    }
};

class Solution4 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0) {
            if (digits[i] == 9) { digits[i] = 0; }
            else { digits[i]++; return digits; }

            i--;
        }
        digits.insert(digits.begin(), 1);
        return digits;

    }
};
class Solution5 {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};

class Solution6 {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};
