#include <iostream>
#include <cstdint>
using namespace std;
union _my_data {
    uint32_t d_word;
    uint8_t byte[4];
}my_data;

union _my_data_non_array {
    uint32_t d_word;
    uint8_t byte_A;
    uint8_t byte_B;
    uint8_t byte_C;
    uint8_t byte_D;
}my_data_non_array;

int main()
{
    my_data.d_word = 0x12345678;
    printf("%X\n", my_data.byte[0]);
    printf("%X\n", my_data.byte[1]);
    printf("%X\n", my_data.byte[2]);
    printf("%X\n", my_data.byte[3]);


    my_data_non_array.d_word = 0x12345678;
    printf("%X\n", my_data_non_array.byte_A);
    printf("%X\n", my_data_non_array.byte_B);
    printf("%X\n", my_data_non_array.byte_C);
    printf("%X\n", my_data_non_array.byte_D);



    std::cout << "Hello World!\n";
}