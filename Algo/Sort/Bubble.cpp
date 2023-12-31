#include <iostream>
#include <cstdint>
using namespace std;
void bubble_sort(int arr[], size_t sz);
void print_arr(int arr[], size_t sz);

int main()
{
    int arr[] = { 99, 8, 11, 3, 5, 7, 66, 1, 2, 6 };

    bubble_sort(arr, 10);
    print_arr(arr, 10);
    return 0;
}

void bubble_sort(int arr[], size_t sz) {
    for (uint8_t i = 0; i < sz - 1; i++) {
        // Last i elements are already sorted
        for (uint8_t j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }

    }


}

void print_arr(int arr[], size_t sz)
{
    for (uint8_t i = 0; i < sz; i++)
        cout << arr[i] << '\t';

}