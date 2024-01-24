// https://leetcode.com/problems/merge-intervals/
// Explanation https://www.youtube.com/watch?v=ex7MWy8TMdM (python)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end() /*,std::less<vector<int>>()*/);

        vector<vector<int>> mergedResult{ intervals[0] };

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= mergedResult.back()[1])
                mergedResult.back()[1] = max(mergedResult.back()[1], intervals[i][1]);

            else mergedResult.push_back(intervals[i]);
        }
        return mergedResult;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> intervals1 = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vector<vector<int>> result1 = solution.merge(intervals1);
    cout << "Example 1 Output: ";
    for (const auto& interval : result1) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> intervals2 = { {1, 4}, {4, 5} };
    vector<vector<int>> result2 = solution.merge(intervals2);
    cout << "Example 2 Output: ";
    for (const auto& interval : result2) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}