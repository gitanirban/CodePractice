// Q SWAP LAST BYTE

#include <iostream>
#include <cstdint>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  cout << "Hello world!" << endl;
  uint32_t val = 0x12345678;
  uint32_t F_word = (val & 0xFFFF0000) >> 16;
  uint32_t S_word = (val & 0xFFFF) << 16;
  uint32_t res;

  res = (S_word) | F_word;

  assert(res == 0x56781234);


  return 0;
}