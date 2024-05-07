#include <iostream>
#include <bitset>
using namespace std;

int findMSSB(int num) {
    if (num == 0)
        return -1; // No set bit found
    
    int mssb = 0; // Initialize the MSSB position

    // Loop to find the position of the leftmost set bit
    while (num >>= 1) {
        mssb++;
    }

    return mssb;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int mssbPos = findMSSB(num);
    
    if (mssbPos != -1) {
        cout << "Position of the Most Significant Set Bit (MSSB): " << mssbPos << endl;
    } else {
        cout << "No set bit found in the number." << endl;
    }

    return 0;
}
