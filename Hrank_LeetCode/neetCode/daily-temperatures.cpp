#include <bits/stdc++.h>
using namespace std;

std::vector<int> dailyTemp(std::vector<int>& temps) {
    std::vector<int> res(temps.size(), 0);
    std::stack<std::pair<int, int>> stack;

    for (int i = 0; i < temps.size(); i++) {
        while (!stack.empty() && temps[i] > stack.top().first) {
            res[stack.top().second] = i - stack.top().second;
            stack.pop();
        }
        stack.push({ temps[i], i });
    }

    return res;
}


int main() {

    std::vector<int> temps = { 73,74,75,71,69,72,76,73 };
    std::vector<int> op = { 1,1,4,2,1,1,0,0 };
    std::vector<int> res = dailyTemp(temps);
    assert(op == res);
    cout << "Success" << endl;
    return 0;
}



