//https://www.hackerrank.com/challenges/reduced-string/problem


/*
Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. In each operation, select a pair of adjacent letters that match, and delete them.

Delete as many characters as possible using this method and return the resulting string. If the final string is empty, return Empty String

Example.
s='aab' op =ab

s='abba' op = ''

aab shortens to b in one operation: remove the adjacent a characters.


Remove the two 'b' characters leaving 'aa'. Remove the two 'a' characters to leave ''. Return 'Empty String'.

*/

#include <iostream>
#include <cstring>
using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s)
{

    string result ="";
    unsigned int sz = s.size();
    unsigned int head =0;
    unsigned int i =0;

    char str_char[sz + 1];
    strcpy(str_char, s.c_str());

    for(i=0; i<sz; i++ )
    {
        if(str_char[i] == str_char[i+1])
        {
            ++i;
            continue;
        }
        result += str_char[i];
    }

    unsigned int sz2 = result.size();
    char str_char2[sz2 + 1];
    strcpy(str_char2, result.c_str());
    for(i=0; i<sz2; i++ )
    {
        if(str_char2[i] == str_char2[i+1])
        {
            result = superReducedString(result);
        }
    }


    if(result =="")
        result = "Empty String";

    return result;
}
int main()
{
    cout << superReducedString("abba") << endl;

    return 0;
}