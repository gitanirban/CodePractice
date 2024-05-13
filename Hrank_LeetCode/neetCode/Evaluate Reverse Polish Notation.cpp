#include <bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    unordered_set<string> operands{ "+", "-", "/", "*" };
    vector<string> stack;
    for (auto s : tokens) {
        if (operands.count(s) and stack.size() >= 2U) {
            int a = stoi(stack.back());
            stack.pop_back();
            int b = stoi(stack.back());
            stack.pop_back();
            int res;
            switch (s[0])
            {
            case '+':
                res = a + b;
                break;
            case '-':
                res = b - a;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = b / a;
                break;
            default:
                break;
            }

            stack.push_back(to_string(res));
        }
        else {
            stack.push_back(s);
        }
    }

    return stoi(stack.back());


}

int main() {
    {
        vector<string> s = { "2","1","+","3","*" };
        int res = evalRPN(s);
        assert(res == 9);
    }
    {
        vector<string> s = { "4","13","5","/","+" };
        int res = evalRPN(s);
        assert(res == 6);
    }
    return 0;
}