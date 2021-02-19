// Iterative C++ program to generate all binary
// strings formed by replacing each wildcard
// character by 0 or 1
#include <iostream>
#include <queue>
using namespace std;

// Iterative function to generate all binary strings
// formed by replacing each wildcard character by 0
// or 1
void print(string str)
{
	queue<string> q;
	q.push(str);

	while (!q.empty())
	{
		string str = q.front();

		// find position of first occurrence of wildcard
		size_t index = str.find('?');

		// If no matches were found,
		// find returns string::npos
		if (index != string::npos)
		{
			// replace '?' by '0' and push string into queue
			str[index] = '0';
			q.push(str);

			// replace '?' by '1' and push string into queue
			str[index] = '1';
			q.push(str);
		}

		else
			// If no wildcard characters are left,
			// print the string.
			cout << str << endl;

		q.pop();
	}
}

// Driver code to test above function
int main()
{
	string str = "1??0?101";

	print(str);

	return 0;
}
