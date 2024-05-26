
#include<bits/stdc++.h>
using namespace std;

//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non - alphanumeric characters, 
//it reads the same forward and backward.Alphanumeric characters include letters and numbers.
bool isPalindrome_(string s) {
    string res;
    for (auto c : s) {
        if (c >= 'a' and c <= 'z') {
            res += c;
        }
        if (c >= 'A' and c <= 'Z') {
            res += c + 32;
        }
        if (c >= '0' and c <= '9') {
            res += c + 32;
        }
    }
    string rev(res.rbegin(), res.rend());

    return res == rev;
}

bool isAlphaNumeric(char c) {
    if (c >= 'a' and c <= 'z') {
        return true;
    }
    if (c >= 'A' and c <= 'Z') {
        return true;
    }
    if (c >= '0' and c <= '9') {
        return true;
    }
    return false;
}

char toLower(char c) {
    if (c >= 'A' and c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}

bool isPalindrome(string s) {
    size_t l = 0, r = s.length() - 1;
    while (l < r) {
        while (l < r and isAlphaNumeric(s.at(l)) == false)
            l++;
        while (l < r and isAlphaNumeric(s.at(r)) == false)
            r--;
        if (toLower(s.at(l)) != toLower(s.at(r)))
            return false;

        l++;
        r--;
    }
    return true;
}

int main() {
    {
        string ip = " 0A man, a plan, a canal: Panama0";
        assert(isPalindrome(ip) == true);
    }

    return 0;
}