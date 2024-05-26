
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <gtest/gtest.h>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::stack<char> stack;
        backTrack(res, stack, 0, 0, n);
        return res;
    }

private:
    void backTrack(std::vector<std::string>& res, std::stack<char>& stack, int openN, int closedN, int n) {
        if (openN == closedN && openN == n) {
            std::string temp;
            while (!stack.empty()) {
                temp = stack.top() + temp;
                stack.pop();
            }
            res.push_back(temp);
            return;
        }

        if (openN < n) {
            stack.push('(');
            backTrack(res, stack, openN + 1, closedN, n);
            stack.pop();
        }
        if (closedN < openN) {
            stack.push(')');
            backTrack(res, stack, openN, closedN + 1, n);
            stack.pop();
        }
    }
};

class TestSolution : public ::testing::Test {
protected:
    void SetUp() override {
        sol = new Solution();
    }

    void TearDown() override {
        delete sol;
    }

    Solution* sol;
};

TEST_F(TestSolution, generateParenthesis) {
    EXPECT_EQ(sol->generateParenthesis(1), std::vector<std::string>({"()"}));
    EXPECT_EQ(sol->generateParenthesis(2), std::vector<std::string>({"(())", "()()"}));
    EXPECT_EQ(sol->generateParenthesis(3), std::vector<std::string>({"((()))", "(()())", "(())()", "()(())", "()()()"}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

