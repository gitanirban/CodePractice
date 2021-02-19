#include <iostream>
#include <string>
using namespace std;
int strl(char const *pAr)
{
    int sz = 0;
    while (*pAr !=  NULL)
    {
        ++sz;
        pAr++;
    }
    return sz;
}
int main()
{
    std::cout << "Hello World!\n";
    char const *str = "Anirban";
    cout << strl(str) << endl;
}