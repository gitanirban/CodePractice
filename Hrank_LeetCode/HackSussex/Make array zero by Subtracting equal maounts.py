import unittest

def Make_array_zero_by_Subtracting_equal_Amounts_not_toptimised(nums: list[int]) -> int:
    res = 0
    nums.sort()
    nums = [x for x in nums if x]

    while len(nums):
        nums = [x - nums[0] for x in nums]
        nums = [x for x in nums if x]
        res += 1
    return res

def Make_array_zero_by_Subtracting_equal_Amounts(nums: list[int]) -> int:
    unique_non_zero_elements = {num for num in nums if num != 0}
    return len(unique_non_zero_elements)


class TestMakeArrayZero(unittest.TestCase):
    def test_case_1(self):
        inp = [1, 5, 0, 3, 5]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 3)

    def test_case_2(self):
        inp = [0, 0, 0, 0]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 0)

    def test_case_3(self):
        inp = [4, 4, 4, 4]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 1)

    def test_case_4(self):
        inp = [1, 2, 3, 4, 5]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 5)

    def test_case_5(self):
        inp = [10, 20, 30, 40, 50]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 5)

    def test_case_6(self):
        inp = [1]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 1)

    def test_case_7(self):
        inp = [0, 1, 0, 1, 0, 1]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 1)

    def test_case_8(self):
        inp = [100, 200, 300]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 3)

    def test_case_9(self):
        inp = [5, 5, 5, 0, 0, 0, 5]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 1)

    def test_case_10(self):
        inp = [0]
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 0)

    def test_case_11(self):
        inp = []
        res = Make_array_zero_by_Subtracting_equal_Amounts(inp)
        self.assertEqual(res, 0)

if __name__ == "__main__":
    unittest.main()
