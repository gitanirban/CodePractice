import unittest
from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        res = []

        def backTrack(openN, closedN):
            if openN == closedN == n:
                res.append("".join(stack))
                return

            if openN < n:
                stack.append("(")
                backTrack(openN + 1, closedN)
                stack.pop()
            if closedN < openN:
                stack.append(")")
                backTrack(openN, closedN + 1)
                stack.pop()

        backTrack(0, 0)
        return res

class TestSolution(unittest.TestCase):
    def setUp(self):
        self.sol = Solution()

    def test_generateParenthesis(self):
        self.assertEqual(self.sol.generateParenthesis(1), ["()"])
        self.assertEqual(self.sol.generateParenthesis(2), ["(())", "()()"])
        self.assertEqual(self.sol.generateParenthesis(3), ["((()))", "(()())", "(())()", "()(())", "()()()"])

if __name__ == "__main__":
    unittest.main()
