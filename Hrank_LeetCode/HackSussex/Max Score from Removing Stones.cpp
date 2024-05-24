// Max_Score_from_Removing_Stones
#include<bits/stdc++.h>
using namespace std;

int Max_Score_from_Removing_Stones(int a, int b, int c) {
    int res = 0;
    vector<int> arr = { a,b,c };
    sort(arr.begin(), arr.end());
    while (arr[arr.size() - 1] and arr[arr.size() - 2]) {
        arr[arr.size() - 1]--;
        arr[arr.size() - 2]--;
        res++;

        if (arr[0] > arr[2]) swap(arr[0], arr[2]);
        if (arr[0] > arr[1]) swap(arr[0], arr[1]);

    }

    return res;
}

int main() {

    assert(Max_Score_from_Removing_Stones(2, 4, 6) == 6);
    assert(Max_Score_from_Removing_Stones(1, 8, 8) == 8);
    assert(Max_Score_from_Removing_Stones(0, 0, 0) == 0);
    assert(Max_Score_from_Removing_Stones(1, 1, 1) == 1);
    assert(Max_Score_from_Removing_Stones(3, 3, 3) == 4);

    return 0;
}