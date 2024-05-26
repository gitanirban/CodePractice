# Max number of words can be typed with broken keyboard

import unittest

def Max_number_of_words_can_be_typed_with_broken_keyboard(text: str, brokenLetters:str) ->int:
    words = text.split()
    valid_words = set(words)
    for word in words:
        for char in brokenLetters:
            if char in word:
              valid_words.discard(word)
    return len(valid_words)

class TestNumberOfLargestSquare(unittest.TestCase):
    def test_case_1(self):
        inp = "hello world"
        broken = "ad"
        res = Max_number_of_words_can_be_typed_with_broken_keyboard(inp, broken)
        self.assertEqual(res, 1)


if __name__ == "__main__":
    unittest.main()

