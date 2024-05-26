import unittest

def Find_Players_with_Zero_or_One_Losses(matches: list[list[int]]) -> list[list[int]]:
    res = list[list[int]]
    winners = set()
    losers = set()
    only_single_losers = set()

    for w, l in matches:
        winners.add(w)
        losers.add(l)
        only_multiple_losers_sz = len(only_single_losers)
        only_single_losers.add(l)
        only_multiple_losers_sz_after = len(only_single_losers)

        if only_multiple_losers_sz == only_multiple_losers_sz_after:
            only_single_losers.remove(l)

    only_winners = winners - losers

    return [list(only_winners), list(only_single_losers)]

class TestNumberOfLargestSquare(unittest.TestCase):
    def test_case_1(self):
        ip = [
            [1,3],
            [2,3],
            [3,6],
            [5,6],
            [5,7],
            [4,5],
            [4,8],
            [4,9],
            [10,4],
            [10,9]
        ]
        res = Find_Players_with_Zero_or_One_Losses(ip)
        self.assertEqual(res, [[1,2,10],[4,5,7,8]])

    def test_case_2(self):
        ip = [
            [1,2],
            [2,3],
            [3,4]
        ]
        res = Find_Players_with_Zero_or_One_Losses(ip)
        self.assertEqual(res, [[1], [2,3,4]])

    def test_case_3(self):
        ip = [
            [1,2],
            [2,3],
            [3,4],
            [4,5]
        ]
        res = Find_Players_with_Zero_or_One_Losses(ip)
        self.assertEqual(res, [[1], [2,3,4,5]])

    def test_case_4(self):
        ip = [
            [1,2],
            [2,3],
            [3,1]
        ]
        res = Find_Players_with_Zero_or_One_Losses(ip)
        self.assertEqual(res, [[], [1,2,3]])

    def test_case_5(self):
        ip = [
            [1,2],
            [1,3],
            [1,4]
        ]
        res = Find_Players_with_Zero_or_One_Losses(ip)
        self.assertEqual(res, [[1], [2,3,4]])

if __name__ == "__main__":
    unittest.main()
