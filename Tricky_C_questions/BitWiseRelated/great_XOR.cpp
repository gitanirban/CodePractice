//https://www.hackerrank.com/challenges/the-great-xor/problem

/*
Input  : n = 12
Output : 3
Numbers are 1, 2 and 3
1^12 > 12,  2^12 > 12 and 3^12 > 12

Input  : n = 11
Output : 4
Numbers are 4, 5, 6 and 7

*/

//gfg
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long theGreatXor(long x);
int main()
{
    cout << "Hello world!" << endl;

    cout<<theGreatXor(303924675) <<endl;
    return 0;
}


long theGreatXor(long x)
{
    long count_res =0;
    long i =1;
    while(i<x)
    {
        if((x^i) > x)
        {
            count_res++;
        }
        i++;
    }
    return count_res;
}
