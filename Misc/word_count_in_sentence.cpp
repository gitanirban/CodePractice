#include<bits/stdc++.h>
using namespace std;
unordered_set<char> myAlphabets;
void myInit() {
    for (char i = 'a'; i <= 'z'; i++)
        myAlphabets.insert(i);
    for (char i = 'A'; i <= 'Z'; i++)
        myAlphabets.insert(i);

}
// user gives a sentence contains multiple words, count the words present
//

int main2() {
    const char* input = "   Hello  World    Hello   ";
    myInit();
    uint8_t cnt = 0;
    const uint8_t siz = strlen(input);
    for (uint8_t itr = 0; itr < siz; itr++) {
        if ((myAlphabets.end() != myAlphabets.find(*(input + itr))) && (*(input + itr + 1U) == ' ')) {

            for (uint8_t itr2 = itr + 1U; itr2 < siz; itr2++) {

                if ((*(input + itr2) == ' ') && (myAlphabets.end() != myAlphabets.find(*(input + itr2 + 1U)))) {
                    cnt++;
                }
            }
            break;
        }

    }
    if (siz != 0) {
        cnt++;
    }

    printf("count is %d", cnt);

    return 0;
}


int countWords(char const* input) {

    int count = 0;
    bool start_space = false;
    bool mid_letter = false;
    bool end_space = false;

    for (auto idx = 0; idx < strlen(input); idx++) {
        if (input[idx] == ' ' or idx == 0)
            start_space = true;
        if (start_space and input[idx] != ' ')
            mid_letter = true;
        if (start_space and mid_letter)
            if ((idx == strlen(input) - 1) or input[idx] == ' ')
                end_space = true;
        if (start_space and mid_letter and end_space) {
            count++; mid_letter = false; end_space = false;
        }
    }
    return count;
}

int main() {
    const char* input = "  Hello  World    Hello  ";
    assert(countWords(input) == 3);

    {
        const char* input = "Hello";
        assert(countWords(input) == 1);
    }

    {
        const char* input = " Hello World";
        assert(countWords(input) == 2);
    }
    {
        const char* input = "Hello World  ";
        assert(countWords(input) == 2);
    }
    {
        const char* input = "Hello World";
        assert(countWords(input) == 2);
    }
    {
        const char* input = "Hello   World";
        assert(countWords(input) == 2);
    }
    {
        const char* input = "Mix of letters and spaces";
        assert(countWords(input) == 5);
    }
    {
        const char* input = "Hello, World!";
        assert(countWords(input) == 2);
    }
    {
        const char* input = "";
        assert(countWords(input) == 0);
    }
    return 0;
}