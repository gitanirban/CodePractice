// Hack Sussex Coder's cup 2024
// Number of Rectangles that can form the largest Square.

/* inp = {  {5,8},
            {3,9},
            {5,12},
            {16,5}
}
    largest squares = { 5, 3, 5, 5}
    Output : Number of largest Sq = 3.
*/

#include <bits/stdc++.h>
using namespace std;

int NumberOfLargestSquare(vector<vector<int>> const& inp) {
    unordered_map<int, int> count;
    for (auto row : inp) {
        int minValue = min(row[0], row[1]);
        count[minValue]++;
    }

    int maxSize = 0;
    for (auto itr : count) {
        if (maxSize < itr.first)
            maxSize = itr.first;
    }

    return count[maxSize];
}

void runTests() {
    // Test case 1
    vector<vector<int>> inp1 = {
            {5,8},
            {3,9},
            {5,12},
            {16,5}
    };
    int res1 = NumberOfLargestSquare(inp1);
    assert(3 == res1);
    
    // Test case 2: Single rectangle
    vector<vector<int>> inp2 = {
            {4,4}
    };
    int res2 = NumberOfLargestSquare(inp2);
    assert(1 == res2);

    // Test case 3: All squares are the same
    vector<vector<int>> inp3 = {
            {2,2},
            {2,2},
            {2,2},
            {2,2}
    };
    int res3 = NumberOfLargestSquare(inp3);
    assert(4 == res3);

    // Test case 4: Different squares with one largest
    vector<vector<int>> inp4 = {
            {1,1},
            {2,2},
            {3,3},
            {4,4}
    };
    int res4 = NumberOfLargestSquare(inp4);
    assert(1 == res4);

    // Test case 5: No rectangles
    vector<vector<int>> inp5 = {};
    int res5 = NumberOfLargestSquare(inp5);
    assert(0 == res5);

    // Test case 6: Larger input with multiple largest squares
    vector<vector<int>> inp6 = {
            {8,10},
            {15,15},
            {20,25},
            {15,20},
            {10,10},
            {15,30}
    };
    int res6 = NumberOfLargestSquare(inp6);
    assert(1 == res6);

    // Test case 7: Mix of different and equal sizes
    vector<vector<int>> inp7 = {
            {5,5},
            {6,6},
            {6,8},
            {8,6},
            {7,9},
            {9,7}
    };
    int res7 = NumberOfLargestSquare(inp7);
    assert(2 == res7);
}

int main() {
    runTests();
    cout << "All test cases passed!" << endl;
    return 0;
}
