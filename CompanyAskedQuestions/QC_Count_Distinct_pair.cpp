

#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int countDistinctPair();
void my_init();

unordered_set<int> my_visited_Set;
int const sz = 5;
vector<int> arr = { 1 ,1 ,2, 3, 5 };
int diff = 1;
int main()
{
 
	cout << countDistinctPair() << endl;
}


int countDistinctPair() {
	unordered_set<int> my_set(arr.begin(), arr.end());
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
