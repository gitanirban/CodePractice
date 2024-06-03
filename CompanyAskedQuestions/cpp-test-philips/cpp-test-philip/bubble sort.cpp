#include <iostream>
#include <cstdint>
#include<bits/stdc++.h>
using namespace std;
 
 

 
int main() {
 int a[5] = {22,44,11,0,-1};

for(int i =0; i < 5-1;i++)
    for(int j = 5-1; i < j; j--)
        if(a[j]<a[j-1])
            swap(a[j], a[j-1]);

 cout << endl;
 for(auto n : a)
    cout << n << "\t";
    return 0;
}