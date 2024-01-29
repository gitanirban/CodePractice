// valid sudoku 
// https://leetcode.com/problems/valid-sudoku/description/ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> cols;
        std::unordered_map<int, std::unordered_set<char>> rows;
        std::unordered_map<int, std::unordered_set<char>> squares;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                cout << (r / 3) * 3 + c / 3 << "\t";
                if (board[r][c] == '.') {
                    continue;
                }
                if (rows[r].count(board[r][c]) > 0 ||
                    cols[c].count(board[r][c]) > 0 ||
                    squares[(r / 3) * 3 + c / 3].count(board[r][c]) > 0) {
                    return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[(r / 3) * 3 + c / 3].insert(board[r][c]);
            }
            cout << endl;
        }

        return true;
    }
};

int main() {
    // Example usage:
    Solution sol;
    std::vector<std::vector<char>> sudokuBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool result = sol.isValidSudoku(sudokuBoard);
    std::cout << std::boolalpha << result << std::endl;

    return 0;
}
