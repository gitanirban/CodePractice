// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (uint32_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) { profit += prices[i] - prices[i-1]; }
        }
        return profit;
    }

};

int main() {
    Solution obj;
    vector<int> input{ 7,1,5,3,6,4 };
    cout << obj.maxProfit(input) << endl;
    return 0;
}