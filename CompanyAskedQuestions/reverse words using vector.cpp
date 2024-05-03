
#include<bits/stdc++.h>
using namespace std;

std::string reverseWords(const std::string& sentence) {
    std::vector<std::string> words;
    std::string word;

    // Iterate through each character in the sentence
    for (char c : sentence) {
        // If the character is not a space, append it to the current word
        if (c != ' ') {
            word += c;
        }
        else {
            // If the character is a space, add the current word to the vector of words
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }

    // Add the last word if it's not empty
    if (!word.empty()) {
        words.push_back(word);
    }


    // Concatenate the reversed words into a sentence
    std::string reversedSentence;
    for (auto itr = words.rbegin(); itr != words.rend(); itr++) {
        reversedSentence += *itr + " ";
    }

    // Remove the trailing space
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back();
    }

    return reversedSentence;
}

int main() {

    { // test string word reverses
        string input = " This is  test.";
        string out = "test. is This ";
        cout << reverseWords(input);

    }

    cout << "\nsuccess" << endl;
    return 0;
}

 