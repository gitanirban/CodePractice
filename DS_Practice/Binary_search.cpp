// ConsoleApplication2_BIN_search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int binSearch(int arr[], int l, int r, int x)
{
    while (r >= l)
    {
        int m = l +((r - l) / 2);

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;

       

    }
    return -1;
}
int main()
{
    std::cout << "Hello World!\n" << endl;
        int ar[5] = { 1, 2, 3, 4, 5};
       int res =  binSearch(ar, 0, 4, 5);

       std::cout << "found at  " << res+1 << endl;
}