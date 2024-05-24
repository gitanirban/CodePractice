import unittest

def Max_Score_from_Removing_Stones(a: int, b: int, c: int) -> int:
    l = sorted([a, b, c])
    l = [x for x in l if x]
    res = 0
    while len(l) > 1:
        l[-2] -= 1
        l[-1] -= 1
        res += 1
        l = sorted(x for x in l if x)

    return res

class TestMaxScoreFromRemovingStones(unittest.TestCase):
    def test_case_1(self):
        a = 2
        b = 4
        c = 6
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 6)

    def test_case_2(self):
        a = 1
        b = 8
        c = 8
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 8)

    def test_case_3(self):
        a = 0
        b = 0
        c = 0
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 0)

    def test_case_4(self):
        a = 1
        b = 1
        c = 1
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 1)

    def test_case_5(self):
        a = 3
        b = 3
        c = 3
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 4)

    def test_case_6(self):
        a = 5
        b = 7
        c = 9
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 10)

    def test_case_7(self):
        a = 0
        b = 3
        c = 3
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 3)

    def test_case_8(self):
        a = 10
        b = 10
        c = 10
        res = Max_Score_from_Removing_Stones(a, b, c)
        self.assertEqual(res, 15)

if __name__ == "__main__":
    unittest.main()
