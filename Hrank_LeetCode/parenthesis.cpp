#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(std::string s) {
        vector<char> stack;
        unordered_map<char, char> openMap{ { ')','('}, { '}','{'}, { ']','['} };

        for (auto c : s)
        {
            if (openMap.find(c) != openMap.end())
                if (stack.size() and stack.back() == openMap[c]) stack.pop_back();
                else
                    return false;

            else
                stack.push_back(c);
        }

        return stack.size() == 0;
    }
};


class Solution2 {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets_stack;
        for (size_t i = 0; i < s.size(); i++)
        {
            char openBr = s[i];
            if (openBr == '(' or openBr == '{' or openBr == '[')
                brackets_stack.push(openBr);
            else {
                if (brackets_stack.size() == 0) return false;
                if (openBr == ')' and brackets_stack.top() != '(') return false;
                if (openBr == '}' and brackets_stack.top() != '{') return false;
                if (openBr == ']' and brackets_stack.top() != '[') return false;
                brackets_stack.pop();
            }
        }
        if (brackets_stack.size() > 0) return false;
        return true;
    }
};
int main() {
    Solution obj;

    string s = "]";

    cout << obj.isValid(s);

    return 0;
}