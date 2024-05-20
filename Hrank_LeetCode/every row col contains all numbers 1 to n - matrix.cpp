// check every row and col contains all numbers 1 to n
// given n x n matrix

// Hack Sussex Coder's cup 2024

#include<bits/stdc++.h>
using namespace std;


#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidMatrix_(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Check if matrix is n x n
    for (const auto& row : matrix) {
        if (row.size() != n) return false;
    }

    // Check rows
    for (int i = 0; i < n; ++i) {
        std::unordered_set<int> rowSet;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] < 1 || matrix[i][j] > n || !rowSet.insert(matrix[i][j]).second) {
                return false;
            }
        }
    }

    // Check columns
    for (int j = 0; j < n; ++j) {
        std::unordered_set<int> colSet;
        for (int i = 0; i < n; ++i) {
            if (matrix[i][j] < 1 || matrix[i][j] > n || !colSet.insert(matrix[i][j]).second) {
                return false;
            }
        }
    }

    return true;
}

int main_() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {3, 1, 2},
        {2, 3, 1}
    };

    if (isValidMatrix_(matrix)) {
        std::cout << "The matrix is valid.\n";
    }
    else {
        std::cout << "The matrix is invalid.\n";
    }
    return 0;
}


bool isValidMatrix(vector<vector<int>> inp) {
    size_t sz = inp.size();
    unordered_set<int> ref;

    for (auto idx = 1; idx <= sz; idx++) {
        ref.insert(idx);
    }

    for (auto r : inp) {
        unordered_set<int> row(r.begin(), r.end());
        if (ref != row)
            return false;
    }
    return true;
}

int main() {
    vector<vector<int>> inp = {
                                {1,2,3},
                                {3,1,2},
                                {2,3,1},
    };
    assert(true == isValidMatrix(inp));
    return 0;
}