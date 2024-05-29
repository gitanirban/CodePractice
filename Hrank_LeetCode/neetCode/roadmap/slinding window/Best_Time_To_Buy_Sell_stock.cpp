// 121. Best Time to Buy and Sell Stock
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    size_t l = 0, r = 1;
    size_t len = prices.size();
    int maxP = 0;
    while (r < len) {
        if (prices[r] > prices[l]) {
            maxP = max(maxP, prices[r] - prices[l]);
        }
        else {
            l = r;
        }
        r++;
    }
    return maxP;
}

int main() {
    {
        vector<int> prices = { 7,1,5,3,6,4 };
        int res = maxProfit(prices);
        assert(5 == res);
    }
    {
        vector<int> prices = { 2,4,1 };
        int res = maxProfit(prices);
        assert(2 == res);
    }

    {
        vector<int> prices = { 3,3 };
        int res = maxProfit(prices);
        assert(0 == res);
    }
    {
        vector<int> prices = { 7,2,4,1 };
        int res = maxProfit(prices);
        assert(2 == res);
    }
    return 0;
}