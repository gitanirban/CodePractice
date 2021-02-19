#include <iostream>

using namespace std;

void addi(int a,int b)
{
    cout << a+b << endl;
}

void subs(int a, int b)
{
    cout << a-b << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    int a = 10;
    int b = 2;
    int choice;
 cout << "enter 0 to add, 1 to substract"<< endl;
 cin >> choice;

 void(*fptrAddDel[])(int, int) = {addi, subs};
fptrAddDel[choice](a,b);
    return 0;
}