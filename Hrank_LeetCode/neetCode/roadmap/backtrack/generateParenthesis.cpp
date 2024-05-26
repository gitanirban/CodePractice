#include<bits/stdc++.h>
using namespace std;

void generateParenthesisHelper(vector<string>& result, string current, int open, int close, int max) {
    if (current.size() == max * 2) {
        result.push_back(current);
        return;
    }

    if (open < max) {
        generateParenthesisHelper(result, current + "(", open + 1, close, max);
    }
    if (close < open) {
        generateParenthesisHelper(result, current + ")", open, close + 1, max);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(result, "", 0, 0, n);
    return result;
}



int main() {
    //  assert(generateParenthesis(1) == std::vector<std::string>({ "()" }));
    assert(generateParenthesis(2) == std::vector<std::string>({ "(())", "()()" }));
    // assert(generateParenthesis(3) == std::vector<std::string>({"((()))", "(()())", "(())()", "()(())", "()()()"}));

    return 0;
}
