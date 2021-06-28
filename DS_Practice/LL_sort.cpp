//LL reverse
#include <iostream>
using namespace std;

struct _Node *pHead, *pTail = NULL;

void insert_inList( int value);
void display_list();
void sort_list();
struct _Node
{
    int data;
    struct _Node *pNext;
};
void insert_inList(int value)
{
    struct _Node *pCurrent = (struct _Node *) malloc(sizeof(struct _Node *));
    pCurrent->data = value;
    pCurrent->pNext = NULL;

    if(pHead ==NULL)
    {
        //first node
        pHead = pCurrent;
        pTail = pCurrent;
    }
    else
    {
        pTail->pNext = pCurrent;
        pTail = pCurrent;
    }

}


void sort_list()
{
    struct _Node *pCurrent = pHead, *pNext = NULL;
    while(pCurrent)
    {
        pNext = pCurrent->pNext;
        while(pNext)
        {
            if(pCurrent->data > pNext->data)
            {
                int temp;

                temp = pCurrent->data;
                pCurrent->data= pNext->data;
                pNext->data = temp;
            }
            pNext=pNext->pNext;
        }
        display_list();
        pCurrent = pCurrent->pNext;
    }


}
void display_list()
{
    struct _Node *pCurrent = pHead;
    while(pCurrent)
    {
        cout << pCurrent->data ;
        pCurrent = pCurrent->pNext;
    }
    cout <<endl;
}

int main()
{
    insert_inList(5);
    insert_inList(2);
    insert_inList(1);
    insert_inList(7);
    insert_inList(8);
    insert_inList(3);






    sort_list();
    cout << "Hello world!" << endl;
    display_list();

    return 0;
}
