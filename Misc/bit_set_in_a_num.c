#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int n = 5;
    int res = 0;
    while(n){
        n = n & (n-1);
        res++;
    }
    std::cout << "res : "<< res << std::endl;
    return 0;
}
