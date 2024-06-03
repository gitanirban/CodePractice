#include <iostream>
#include <cstdint>
#include<bits/stdc++.h>
using namespace std;

void fun(){
    try {
        throw 0;
    }
    catch (int i){
        cout << 4*4 << endl;
        throw 4;
    }
}
 

 
int main() {
    cout << endl;
 int x =0;
 try {
    fun();
 }
 catch(int a)
 { cout <<a*a<<endl;}
    return 0;
}