#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
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
                if (openBr == ')' and  brackets_stack.top() != '(') return false;
                if (openBr == '}' and brackets_stack.top() != '{') return false;
                if (openBr == ']' and brackets_stack.top() != '[') return false;
                brackets_stack.pop();
            }
        }
        if(brackets_stack.size() > 0) return false;
        return true;
    }
};