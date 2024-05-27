//704. Binary Search
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target) { return mid; }
        else if (nums[mid] > target) { r = mid - 1; }
        else if (nums[mid] < target) { l = mid + 1; }
    }

    if (nums.size() == 1 and target == nums[0])
    {
        return 0;
    }
    return -1;
}
int main() {
    {
        vector<int> inp = { -1,0,3,5,9,12 };
        int target = 9;
        int res = search(inp, target);
        assert(4 == res);

    }
    {
        vector<int> inp = { 5 };
        int target = 5;
        int res = search(inp, target);
        assert(0 == res);
    }
        {
        vector<int> inp = { 2,5 };
        int target = 5;
        int res = search(inp, target);
        assert(1 == res);
    }
    cout << "Success" << endl;

    return 0;
}