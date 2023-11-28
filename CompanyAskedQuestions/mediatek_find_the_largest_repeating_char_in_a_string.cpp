#include <iostream>
#include <bits/stdc++.h>

// find the index of the largest repeating char

using namespace std;

char const* pString = "aabbbcccc";
map<int, int, greater<int>> myMap;

int main() {

    int max = 0;
    uint8_t len = strlen((char const*)pString);

    for (int itr = 0; itr <= len; itr++) {
        if (*(pString + itr) == *(pString + itr + 1)) {
            // increment max
            max++;
        }
        else {
            //reset max and store
            myMap.insert(make_pair(max + 1, itr - (max)));
            max = 0;
        }
    }


    auto it = myMap.begin();
    printf("result : %d", (*it).second);
    return 0;
}
