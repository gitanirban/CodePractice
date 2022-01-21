#include <iostream>
using namespace std;

int knapsack(int wt[], int val[], int W, int n);
int max(int a, int b) { return (a>b ? a:b); }

int knapsack(int wt[], int val[], int W, int n){
    if(n==0 || W == 0){
     return 0;
    }

    if(wt[n-1]<=W){
        return max( (val[n-1] + knapsack(wt, val, W - wt[n-1], n-1 )), knapsack(wt, val, W , n-1));
    }
    if(wt[n-1]>W)
        return knapsack(wt, val, W , n-1);

    return -1;
}
int main() {

    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(wt, val, W, n) << endl;
    std::cout << "Hello, World!" << std::endl;


    return 0;
}
