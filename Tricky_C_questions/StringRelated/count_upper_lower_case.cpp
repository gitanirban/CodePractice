#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <cstring>
using namespace std;
unordered_set<char> myCapsSet;
void countUpperLowerCase(string s);

void countUpperLowerCase(string s)
{
    int cap,small =0;

    int sz = s.size();
    char str_char[sz + 1];
    strcpy(str_char, s.c_str());


    for(uint64_t i =0; i<=sz; i++ )
    {
        if(myCapsSet.find(str_char[i]) != myCapsSet.end())
        cap++;
    }
    cout << "cap \t: "<<cap<<endl;
    cout << "samll \t: "<< sz - cap<<endl;

}

void init_my(){

for(uint8_t i = 65; i<=90; i++)
   myCapsSet.insert(i);
}
int main()
{
    init_my();
    countUpperLowerCase("all small");

    return 0;
}