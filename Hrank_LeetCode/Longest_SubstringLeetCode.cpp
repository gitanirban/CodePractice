// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// O(1) solution by me
// other solutions https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;
int lengthOfLongestSubstring(string str);

int const sz = 5;

int main()
{
    string str = "abcabcbb"; // abcabcbb dvdf bbbbb pwwkew
    cout << lengthOfLongestSubstring(str) << endl;
}

int lengthOfLongestSubstring(string str)
{
    int res = 0;
    int res_max = 0;
    unordered_set<char> visited_set;
    queue<char> visited_queue;

    const size_t sz = str.length();
    int i = 0;
    while (i < sz)
    {
        char c = str.at(i);
        if (visited_set.find(c) == visited_set.end())
        {
            visited_set.insert(c);
            visited_queue.push(c);
            res++;
            i++;
        }
        else if ((visited_set.find(c) != visited_set.end()))
        {
            if (res > res_max)
            {
                res_max = res;
            }
            visited_set.erase(visited_queue.front());
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
