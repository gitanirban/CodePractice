#include <bits/stdc++.h>
using namespace std;

void countUpperLowerCaseOptimised(const string& s) {
    int cap = count_if(s.begin(), s.end(), [](char c) { return  (c >= 'A' and c <= 'Z');});
    int small = count_if(s.begin(), s.end(), [](char c) {return  (c >= 'a' and c <= 'z');});


    cout << "cap \t: " << cap << endl;
    cout << "small \t: " << small << endl;
}


int main()
{
    //  init_my();
    cout << endl << endl;
    countUpperLowerCaseOptimised("all small");
    countUpperLowerCaseOptimised("Not all small");
    return 0;
}



// some other ways:
unordered_set<char> myCapsSet;
void countUpperLowerCase(string s)
{
    int cap, small = 0;

    int sz = s.size();

    for (uint64_t i = 0; i <= sz; i++)
    {
        if (myCapsSet.find(s[i]) != myCapsSet.end())
            cap++;
    }
    cout << "cap \t: " << cap << endl;
    cout << "samll \t: " << sz - cap << endl;

}

void init_my() {

    for (uint8_t i = 65; i <= 90; i++)
        myCapsSet.insert(i);
}


