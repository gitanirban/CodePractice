// Merge Sorted Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;

        while (m and n)
        {
            auto n1 = nums1.begin();
            auto n2 = nums2.begin();

            if (*n1 < *n2) {
                res.push_back(*n1);
                nums1.erase(n1);
                m--;
            }
            else {
                res.push_back(*n2);
                nums2.erase(n2);
                n--;
            }
        }

        while (m) {
            auto n = nums1.begin();
            res.push_back(*n);
            nums1.erase(n);
            m--;
        }

        while (n) {
            auto n2 = nums2.begin();
            res.push_back(*n2);
            nums2.erase(n2);
            n--;
        }

        nums1 = res;
    }
};



int main() {

    Solution s;
    vector<int> nums1{ -1,-1,0,0,0,0 };
    vector<int> nums2{ -1,0 };
    s.merge(nums1, 4, nums2, 2);

    for (auto n : nums1)
        cout << n << "\t";

    return 0;
}

