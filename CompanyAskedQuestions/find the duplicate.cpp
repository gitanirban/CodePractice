#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include <cassert>
#include <cstring>
using namespace std;

int findDup(vector<int>& ar) {

    unordered_map< int, int> map;
    for (auto& n : ar) {
        map[n]++;
    }
    for (auto& key : map) {
        if (key.second > 1) {
            return key.first;
        }
    }
    return 0;

}

int main() {

    vector<int> a = { 1,2,3,4 ,5 ,6 , 7, 8,9,3 };
    int res = findDup(a);
    cout << "hello" << endl;
    cout << res << endl;
    assert(res == 3);
    return 0;
}
