// bin search 2d matrix
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int t = 0, b = matrix.size() - 1;
    int l = 0, r = matrix[0].size() - 1;
    bool row_fixed = matrix.size() == 1 ? true : false;

    while (t <= b and l <= r) {
        int row_mid = (t + b) / 2;
        int col_mid = (l + r) / 2;

        if (matrix[row_mid][col_mid] == target) { return true; }

        else if (target < matrix[row_mid][col_mid]) {
            if (target < matrix[row_mid][0])
            {
                b = row_mid - 1;
            }
            else {
                r = col_mid - 1;
            }
        }
        else if (target > matrix[row_mid][col_mid]) {

            if (target > matrix[row_mid][matrix[0].size() - 1])
            {
                t = row_mid + 1;
            }
            else {
                l = col_mid + 1;
            }


        }
    }
    return false;
}

int main() {
    {
        vector<vector<int >> matrix = {
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,60}
        };
        int target = 3;

        bool res = searchMatrix(matrix, target);

        assert(true == res);

    }
    {
        vector<vector<int >> matrix = {
            {1}
        };
        int target = 1;

        bool res = searchMatrix(matrix, target);

        assert(true == res);

    }

    {
        vector<vector<int >> matrix = {
            {1,3}
        };
        int target = 3;

        bool res = searchMatrix(matrix, target);

        assert(true == res);

    }

    {
        vector<vector<int >> matrix = {
                                        {1,3,5,7},
                                        {10,11,16,20},
                                        {23,30,34,50}
        };
        int target = 10;

        bool res = searchMatrix(matrix, target);

        assert(true == res);

    }
    {
        vector<vector<int >> matrix = {
                                {-10,-10},
                                {-9,-9},
                                {-8,-6},
                                {-4,-2},
                                {0,1},
                                {3,3},
                                {5,5},
                                {6,8}
        };
        int target = 0;

        bool res = searchMatrix(matrix, target);

        assert(true == res);

    }

    cout << "Success" << endl;
    return 0;
}