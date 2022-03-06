
#include <bits/stdc++.h>
using namespace std;
// wap to fn to take input to store pages and auth. name of book. there will be 3 books

// search for using auth name and return a pointer so that page number can be viewed.
struct _book{
    uint32_t m_pageCount{0};
    string m_authName{};
};

struct _book books[3];
void insertBook(){
    books[0].m_authName = "Anirban";
    books[0].m_pageCount = 10;

    books[1].m_authName = "Sunil";
    books[1].m_pageCount = 20;

    books[2].m_authName = "Aritra";
    books[2].m_pageCount = 30;
}


_book* getBook(string  const & rInputAuthName){
    for(uint32_t itr = 0; itr <3; itr++){
        if(books[itr].m_authName == rInputAuthName) {
            return  &books[itr];
        }
    }
    return nullptr;
}
int main()
{
    insertBook();
   _book * pBookToFind =  getBook((const string &) "Sunil");

   if(pBookToFind != nullptr){
       cout << "Book Present" << endl;
       cout << "Auth Name : " << pBookToFind->m_authName <<endl;
       cout << "pages are : " << pBookToFind->m_pageCount <<endl;
   }

   else{
       cout << "book not present" << endl;
   }
    return 0;
}
