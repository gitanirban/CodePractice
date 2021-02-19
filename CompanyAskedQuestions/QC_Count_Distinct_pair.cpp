// QC_Count_Distinct_pair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
//#include "stdc++.h"
using namespace std;

int countDistinctPair();
void my_init();
unordered_set<int> my_set;
unordered_set<int> my_visited_Set;
int const sz = 5;
int arr[sz] = { 1 ,1 ,2, 3, 5 };
int diff = 1;
int main()
{
	my_init();
	cout << countDistinctPair() << endl;
}


int countDistinctPair() {
	int res = 0;
	for (int i = 0; i < sz; i++) {
		if ((my_set.find(arr[i] + diff) != my_set.end()) && (my_visited_Set.find(arr[i]) == my_visited_Set.end()))
		{
			my_visited_Set.insert(arr[i]);
			res++;
		}
	}
	return res;
}
void my_init()
{
	for (int i = 0; i < sz; i++)
		my_set.insert(arr[i]);
}