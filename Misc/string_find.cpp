#include <iostream>
#include <string>

using namespace std;

char ip[] = "We Love Embedded Programming ";
char matcher[] = "Love";

int count = 0;

int main() {

    int j = 0;
    int len = max(sizeof(matcher), sizeof(ip));

    for (int i = 0; i < len; i++) {
        char c1 = ip[i];
        char c2 = matcher[j];
        if (c1 == c2) {
            j++;
            count++;
        }

    }


    if (count == sizeof(matcher))
        cout << " found " << endl;
    else
        cout << "Not found" << endl;
    return 0;
}
