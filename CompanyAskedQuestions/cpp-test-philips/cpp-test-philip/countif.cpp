#include <iostream>
#include <cstdint>
#include<bits/stdc++.h>
using namespace std;

int main() {
 int nu[] = {10,-20,-30,40,-50};
 int c;
 c = count_if(nu, nu +5, bind2nd(less<int>(),0));
 cout << endl << c;
    return 0;
}