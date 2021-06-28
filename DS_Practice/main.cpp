#include <iostream>

using namespace std;
void insetAtNode(int value);
void printLL();
void insertionSortLL();
void insertSorted(  struct _Node *pCurrent);
struct _Node
{
    int data;
    struct _Node * pNext;
};

struct _Node *pHead = nullptr;
struct _Node *pSorted = nullptr;

void insetAtNode(int value)
{
    if(pHead == NULL)
    {
        _Node* pTemp = (_Node*) malloc(sizeof(struct _Node));
        pTemp->data = value;
        pTemp->pNext = nullptr;
        pHead = pTemp;
    }
    else
    {
        _Node* pTemp = (_Node*) malloc(sizeof(struct _Node));
        pTemp->data = value;
        pTemp->pNext = nullptr;

        _Node* pTemp2 = pHead;
        while(pTemp2->pNext!=NULL)
        {
            pTemp2=pTemp2->pNext;
        }
        pTemp2->pNext = pTemp;

    }

}

void insertionSortLL()
{
    struct _Node *pCurrent = pHead;
    while(pCurrent!=nullptr)
    {
        struct _Node *pNext = pCurrent->pNext;
        insertSorted(pCurrent);

        pCurrent = pNext;
    }

    pHead = pSorted;
}

void insertSorted( struct _Node *pNewNode)
{
    if((pSorted == nullptr) || (pSorted->data > pNewNode->data))
    {
        pNewNode->pNext = pSorted;
        pSorted = pNewNode;
    }
    else
    {
        struct _Node * pCurrent = pSorted;
        while((pCurrent->pNext !=nullptr)&& (pCurrent->pNext->data < pNewNode->data ))
        {
            pCurrent = pCurrent->pNext;
        }
        pNewNode->pNext = pCurrent->pNext;
        pCurrent->pNext = pNewNode;
    }
}
void printLL()
{
    _Node* pTemp2 = pHead;
    while(pTemp2!=NULL)
    {
        cout << pTemp2->data << endl;
        pTemp2=pTemp2->pNext;
    }

}
int main()
{
    cout << "Hello world!" << endl;
    insetAtNode(5);
    insetAtNode(1);
    insetAtNode(8);
    insetAtNode(2);
    insetAtNode(3);
    insetAtNode(9);
    insetAtNode(4);
    printLL();

    insertionSortLL();
    cout << "After Sort" << endl;
    printLL();
    return 0;
}
