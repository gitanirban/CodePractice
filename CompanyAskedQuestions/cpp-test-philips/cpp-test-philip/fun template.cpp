#include <iostream>
#include <cstdint>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct fun
{

   void x() { cout << "hi" << endl; }
   void y() { cout << "hello" << endl; }

};


template<>
void fun<int>::x() { cout << "hello world" << endl; }

int main() {
   cout << endl;
   fun<int> t;
   t.x();
   t.y();

   return 0;
}