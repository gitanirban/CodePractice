
// Find the pairs from 2 given arrays which can sum to a given number k.

// Input: Array A = [6, 4, 1, 3, 8]
// Input: Array B = [4, 7, 1, 3, 6, 2]
// Input: k = 10

// Output: [6, 4] [4, 6] [3, 7] [8, 2]

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> ip1 = { 6, 4, 1, 3, 8 };
    vector<int> ip2 = { 4, 7, 1, 3, 6, 2 };
    int k = 10;
    vector<vector<int>> res(4);

    unordered_set<int > ip2Set = { ip2.begin(), ip2.end() };
    auto row = 0;
    for (auto n : ip1) {
        if (ip2Set.count(k - n)) {
            res[row].push_back(n);
            res[row].push_back(k - n);
            row++;
        }
    }

    vector<vector<int>> test = {
        {6,4},
        {4,6},
        {3,7},
        {8,2}
    };

    assert(res == test);

    return 0;
}