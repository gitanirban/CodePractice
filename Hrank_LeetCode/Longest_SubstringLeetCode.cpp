// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// O(1) solution by me
// other solutions https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
int lengthOfLongestSubstringOptimisedEvenMore(const std::string& str);

int const sz = 5;

int main()
{
    string str = "abba"; // abcabcbb dvdf bbbbb pwwkew
    cout << lengthOfLongestSubstringOptimisedEvenMore(str) << endl;
}

int lengthOfLongestSubstringMy(const std::string& str)
{
    int res = 0;
    int res_max = 0;
    unordered_set<char> visited_set;
    queue<char> visited_queue;

    const size_t sz = str.length();
    int i = 0;
    while (i < sz)
    {
        char current_char = str.at(i);
        if (visited_set.find(current_char) == visited_set.end())
        {
            visited_set.insert(current_char);
            visited_queue.push(current_char);
            res++;
            i++;
        }
        else if ((visited_set.find(current_char) != visited_set.end()))
        {
            if (res > res_max)
            {
                res_max = res;
            }
            char del = visited_queue.front();
            visited_set.erase(del);
            visited_queue.pop();

            res = visited_set.size();
        }
    }

    if (res > res_max)
    {
        res_max = res;
    }

    return res_max;
}


int lengthOfLongestSubstringOptimised(const std::string& str) {
    int res_max = 0;
    int left = 0;
    std::unordered_set<char> visited_set;

    for (int right = 0; right < str.length(); ++right) {
        char c = str[right];
        while (visited_set.find(c) != visited_set.end()) {
            visited_set.erase(str[left]);
            ++left;
        }

        visited_set.insert(c);
        res_max = std::max(res_max, right - left + 1);
    }

    return res_max;
}


int lengthOfLongestSubstringOptimisedEvenMore(const std::string& s) {
    // https://youtu.be/GS9TyovoU4c?t=1786
    std::unordered_map<char, int> char_last_index;  // Map to store the last index of each character
    int max_length = 0;
    int start_of_current_substring = 0;

    for (int current_index = 0; current_index < s.length(); ++current_index) {
        char current_char = s[current_index];

        // If the current character is repeating within the current substring
        if (char_last_index.find(current_char) != char_last_index.end() &&
            char_last_index[current_char] >= start_of_current_substring) {
            // Update the start index to the next index after the last occurrence of the repeating character
            start_of_current_substring = char_last_index[current_char] + 1;
        }

        // Update the index of the current character in the map
        char_last_index[current_char] = current_index;

        // Update the maximum length if the current substring is longer
        max_length = std::max(max_length, current_index - start_of_current_substring + 1);
    }

    return max_length;
}


int lengthOfLongestSubstring_GPT(const std::string& str) {
    int n = str.length();
    int res = 0;
    int left = 0, right = 0;

    std::unordered_set<char> visited_set;

    while (right < n) {
        if (visited_set.find(str[right]) == visited_set.end()) {
            visited_set.insert(str[right]);
            res = std::max(res, right - left + 1);
            right++;
        } else {
            visited_set.erase(str[left]);
            left++;
        }
    }

    return res;
}