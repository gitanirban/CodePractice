
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> left_product(n);
        vector<int> right_product(n);
        left_product[0] = 1;
        for (int idx = 1; idx < n; idx++) {
            left_product[idx] = left_product[idx - 1] * nums[idx - 1];
        }

        right_product[n - 1] = 1;
        for (int idx = n - 2; idx >= 0; idx--) {
            right_product[idx] = right_product[idx + 1] * nums[idx + 1];
        }

        for (int idx = 0; idx < n; idx++) {
            ans[idx] = left_product[idx] * right_product[idx];
        }

        return ans;
    }
};
                                                                         
int main() {
    vector<int > arr = { 1,2,3,4 };

    vector<int> res = { 24,12,8,6 };
    Solution s;
    assert(res == s.productExceptSelf(arr));
    cout << "success" << endl;
    return 0;
}