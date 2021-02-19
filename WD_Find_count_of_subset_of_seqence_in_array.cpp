//WD find count of sequence in an array

#include <iostream>
using namespace std;
int const sz = 7;
int arr[sz] = { 1, 2, 3, 4, 6, 7, 8 };
int slide = 1;
int cnt = 0;

int res = 0;

int main()
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] + 1 == arr[i + 1])
        {
            cnt++;
        }
        else if ( (arr[i] + 1 != arr[i + 1]) || i == sz-1)
        {
            res += (cnt * (cnt + 1)) / 2;
            cnt = 0;

        }

    }
    std::cout << "\n\n res  : " << res;

}
