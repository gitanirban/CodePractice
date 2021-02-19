#include <stdio.h>
#include <stdlib.h>

// reset the first bit(0), toggle the 2nd bit(1th), and set the 4th bit(3rd).
//insert at node and print
struct _Node
{
    int value;
    struct Node *pNext;
};
struct _Node *pHead = NULL;
void insertLL(int v);
void displayLL();
int main()
{
    printf("Hello world!\n");
    insertLL(5);
    insertLL(4);
    insertLL(3);

    displayLL();
    return 0;
}

void insertLL(int v)
{
    struct _Node *pTemp = NULL;
    pTemp = (struct _Node *) malloc(sizeof(struct _Node));
    pTemp->value = v;
    pTemp->pNext = NULL;

    if(pHead == NULL)
    {
        pHead = pTemp;
    }
    else
    {
        pTemp->pNext = pHead;
        pHead = pTemp;
    }
}

void displayLL()
{
    while(pHead != NULL)
    {
        printf("%d\n",pHead->value);
        pHead = pHead->pNext;
    }
}
