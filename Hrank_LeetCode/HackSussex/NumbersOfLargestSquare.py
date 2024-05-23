import unittest

def number_of_largest_square_(inp):
    count = {}
    for row in inp:
        min_value = min(row)
        count[min_value] = count.get(min_value, 0) + 1

    max_size = max(count.keys(), default=0)
    return count.get(max_size, 0)

def number_of_largest_square(rectangles: list[list[int]]) -> int:
    if len(rectangles) is 0:
        return 0

    squares = list(map(min, rectangles))
    highest = max(squares)
    square_filtered = [ i for i in squares if i == highest]

    return len(square_filtered)

class TestNumberOfLargestSquare(unittest.TestCase):
    def test_case_1(self):
        inp = [
            [5, 8],
            [3, 9],
            [5, 12],
            [16, 5]
        ]
        res = number_of_largest_square(inp)
        self.assertEqual(res, 3)
    
    def test_case_2(self):
        inp = [
            [4, 4]
        ]
        res = number_of_largest_square(inp)
        self.assertEqual(res, 1)

    def test_case_3(self):
        inp = [
            [2, 2],
            [2, 2],
            [2, 2],
            [2, 2]
        ]
        res = number_of_largest_square(inp)
        self.assertEqual(res, 4)

    def test_case_4(self):
        inp = [
            [1, 1],
            [2, 2],
            [3, 3],
            [4, 4]
        ]
        res = number_of_largest_square(inp)
        self.assertEqual(res, 1)

    def test_case_5(self):
        inp = []
        res = number_of_largest_square(inp)
        self.assertEqual(res, 0)

    def test_case_6(self):
        inp = [
            [8, 10],
            [15, 15],
            [20, 25],
            [15, 20],
            [10, 10],
            [15, 30]
        ]
        res = number_of_largest_square(inp)
        self.assertEqual(res, 1)

    def test_case_7(self):
        inp = [
            [5, 5],
            [6, 6],
            [6, 8],
            [8, 6],
            [7, 9],
            [9, 7]
        ]
        res = number_of_largest_square(inp)
        self.assertEqual(res, 2)

if __name__ == "__main__":
    unittest.main()
