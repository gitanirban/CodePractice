#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxArea = 0;
    while (l < r) {
        int minHeight = min(height[l], height[r]);
        int currArea = minHeight * (r - l);
        maxArea = max(currArea, maxArea);
        if (height[l] < height[r]) {
            l++;
        }
        else {
            r--;
        }
    }
    return maxArea;
}

int main() {
    {
        vector <int>inp = { 1,8,6,2,5,4,8,3,7 };
        int res = maxArea(inp);
        assert(res == 49);
    }

    //  
    {
        vector <int>inp = { 2,3,4,5,18,17,6 };
        int res = maxArea(inp);
        assert(res == 17);
    }

    cout << endl << "success";
    return 0;
}