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
    int result =0;

    int sz = s.size();
    char str_char[sz + 1];
    strcpy(str_char, s.c_str());
    if(sz > 0)
        result++;

    for(uint64_t i =0; i<=sz; i++ )
    {
        if(myCapsSet.find(str_char[i]) != myCapsSet.end())
        result++;
    }
return result;
}

void init_my(){

for(uint8_t i = 65; i<=90; i++)
   myCapsSet.insert(i);
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);
    init_my();
    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}