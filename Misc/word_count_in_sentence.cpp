#include <iostream>
#include <string.h>
#include <unordered_set>
using namespace std;
unordered_set<char> myAlphabets;
void myInit(){
    for(char i = 'a'; i <= 'z'; i++)
        myAlphabets.insert(i);
    for(char i = 'A'; i <= 'Z'; i++)
        myAlphabets.insert(i);

}
// user gives a sentence contains multiple words, count the words present
//

int main() {
    const char *input = "   Hello  World    Hello   ";
    myInit();
    uint8_t cnt = 0;
    const uint8_t siz = strlen(input);
     for(uint8_t itr = 0; itr < siz; itr++){
         if( (myAlphabets.end() != myAlphabets.find(*(input + itr ))) && (*(input + itr + 1U) == ' ')){

             for(uint8_t itr2 = itr + 1U; itr2 < siz; itr2++){

                 if( (*(input + itr2 ) == ' ') && (myAlphabets.end() != myAlphabets.find(*(input + itr2 + 1U))) ){
                     cnt++;
                 }
             }
             break;
         }

     }
     if(siz != 0){
         cnt++;
     }

    printf("count is %d", cnt);

    return 0;
}
