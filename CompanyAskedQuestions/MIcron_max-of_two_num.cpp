#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
   
    int8_t a, b = 0;
    cin >> a;
    cin >> b;
    cout << "enterd number is " << a  <<" & "<< b << endl;

    int8_t c = a - b;
    int mask =  1 << 7;
    bool sb = c & mask;

    if( a & mask)
        cout << b << " is bigger " << endl;

    else if (b & mask)
        cout << a << " is bigger " << endl;

    if ((sb == false) && ((a & mask) == false) && ((b & mask)) == false)
        cout << a <<" is bigger if case " << endl;
    else
        cout << b << " is bigger else case" << endl;
    std::cout << "Hello World!\n";
   
}