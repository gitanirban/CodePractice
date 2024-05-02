//SNAKE QCOM

#include <iostream>

using namespace std;
int arr[5][5] =
{
    { 1, 2, 3, 4, 5},
    { 2, 3, 4, 5, 6},
    { 3, 4, 5, 6, 7},
    { 4, 5, 6, 7, 8},
    { 5, 6, 7, 8, 9},
};

int main()
{
    cout << "Hello world!" << endl;
    for(int i = 0; i<5; i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j<5; j++)
            {
                cout<< arr[i][j] ;
            }
        }
        else
        {
            for(int j=4; j>=0; j--)
            {
                cout<< arr[i][j] ;
            }
        }

    }
    return 0;
}