#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define DATA_SIZE 256
int32_t LINK_LIST_SIZE = 10;
#define True 1
#define False 0

typedef struct node_t
{
    struct node_t* next;
    uint8_t data;
} node_t;

void print_data(uint8_t* data, uint32_t size)
{
    int32_t i=0;
    for(i=0;i<size;i++)
    {
        printf("%d ",*(data+i));
    }
}
void append_list(node_t **pHeadArg){
    node_t *pTemp = (node_t *) malloc(sizeof(node_t));

    pTemp->data = rand();
  //  printf("%d \t ",pTemp->data);
    pTemp->next = *pHeadArg;
    *pHeadArg = pTemp;

}
void create_linklist(node_t **pHeadArg, int32_t size){
    while(size--){
        append_list(pHeadArg);
    }

}

void printlinklist(node_t *pHeadArg){
    node_t *pTemp = pHeadArg;
    while(pTemp != NULL){
        printf("%d \t", pTemp->data);
        pTemp = pTemp->next;
    }
}
// sort function

void FrontBackSplit(node_t* source,
                    node_t** frontRef, node_t** backRef)
{
    node_t* fast;
    node_t* slow;
    slow = source;
    fast = source->next;

    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
node_t* SortedMerge(node_t* a, node_t* b)
{
    node_t* result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
void MergeSort(node_t ** headRef)
{
    node_t* head = *headRef;
    node_t* a;
    node_t* b;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }
    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}
int main() //
{

    node_t * pHead = NULL;
    create_linklist(&pHead, LINK_LIST_SIZE);

    printlinklist(pHead);
    printf("\n\n\n");
    MergeSort(&pHead);

    printlinklist(pHead);
    return 0;
}
