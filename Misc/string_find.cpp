#include <iostream>
#include <string>

using namespace std;

char ip[] = "We Love Embedded Programming ";
char matcher[] = "Love";

int count = 0;

int main() {

    int i = 0, j = 0;
    int len = max(sizeof(matcher), sizeof(ip));

    while (len) {
        char c1 = ip[i];
        char c2 = matcher[j];
        if (c1 == c2) {
            i++;
            j++;
            count++;
        } else {
            i++;
        }
        len--;
    }


    if (count == sizeof(matcher))
        cout << " found " << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
