//ptr type

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    int b = 2;
    int * a = &b;
    if( typeid(*a) == typeid(int) )
    {
        cout << true ;
    }
    else
        cout << false;

}