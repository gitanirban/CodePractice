//https://www.hackerrank.com/challenges/camelcase/problem

/*

There is a sequence of words in CamelCase as a string of letters, , having the following properties:

It is a concatenation of one or more words consisting of English letters.
All letters in the first word are lowercase.
For each of the subsequent words, the first letter is uppercase and rest of the letters are lowercase.
Given , determine the number of words in .

Example

There are  words in the string: 'one', 'Two', 'Three'.

*/


#include <bits/stdc++.h>
#include <unordered_set>
#include <cstdint>
using namespace std;
unordered_set<char> myCapsSet;
// Complete the camelcase function below.
int camelcase(string s)
{
size_t count_upper = count_if(s.begin(), s.end(),    
               [](unsigned char ch) { return isupper(ch); });
return count_upper + 1;
}


int main()
{
    string s = "saveChangesInTheEditor";
    cout << camelcase(s) << endl;

    return 0;
}