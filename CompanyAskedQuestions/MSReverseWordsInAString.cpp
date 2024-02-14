#include <bits/stdc++.h>

using namespace std;
int main() {
    // you can write to stdout for debugging purposes, e.g.
    string s = "This is test.";
    // output: test. is this
    stack<string> stack;
    string word;

    for (int i = 0; i < (s.length()); i++) {

        if (s[i] != ' ') {
            word.append(s, i, 1);
        }
        else if (s[i] == ' ') {
            stack.push(word);
            word = "";
        }
    }
    stack.push(word);

    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}
