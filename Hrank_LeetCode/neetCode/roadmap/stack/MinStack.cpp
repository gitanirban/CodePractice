#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int> _minStack;
    vector<int> _stack;
    MinStack() { }

    void push(int val) {
        _stack.push_back(val);
        int currentMin = _minStack.size() ? _minStack.back() : val;
        int mini = min(val, currentMin);
        _minStack.push_back(mini);
    }
    void pop() {
        _stack.pop_back();
        _minStack.pop_back();
    }

    int top() {
        return _stack.back();
    }

    int getMin() {
        return _minStack.back();
    }
};

int main() {
    {
        MinStack minStack;
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        assert(minStack.top() == -3);
        assert(minStack.getMin() == -3);
        minStack.pop();
        assert(minStack.getMin() == -2);
        assert(minStack.top() == 0);
    }
    {
        MinStack minStack;
        minStack.push(2);
        minStack.push(0);
        minStack.push(3);
        minStack.push(0);
        minStack.pop();
        minStack.pop();
        minStack.pop();

        assert(minStack.top() == 2);
        assert(minStack.getMin() == 2);
    }
    return 0;
}