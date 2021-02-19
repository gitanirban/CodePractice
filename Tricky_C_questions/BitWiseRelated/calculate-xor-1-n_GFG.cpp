//https://www.geeksforgeeks.org/calculate-xor-1-n/


/*
Given a number n, the task is to find the XOR from 1 to n.

Examples :

Input : n = 6
Output : 7
// 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6  = 7

Input : n = 7
Output : 0
// 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0
*/

// C++ program to find XOR of numbers 
// from 1 to n. 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to calculate xor 
long computeXOR(const int n) 
{ 
    // Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
  
    switch(n & 3) // n % 4  
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
} 
  
// Driver code 
int main() 
{ 
    // your code goes here 
    int n = 5; 
    cout <<    computeXOR(n); 
    return 0; 
} 

/*
How does this work?
When we do XOR of numbers, we get 0 as XOR value just before a multiple of 4. This keeps repeating before every multiple of 4.

Number Binary-Repr  XOR-from-1-to-n
0	      0            0000  <------ n		
1         1           [0001]  <------ 1
2        10           [0011]  <------- n+1
3        11           [0000]  <----- We get a 0
4       100           [0100]  <----- Equals to n
5       101           [0001]
6       110           [0111]
7       111           [0000]  <----- We get 0
8      1000           [1000]  <----- Equals to n
9      1001           [0001]
10     1010           [1011]
11     1011           [0000] <------ We get 0
12     1100           [1100] <------ Equals to n

*/