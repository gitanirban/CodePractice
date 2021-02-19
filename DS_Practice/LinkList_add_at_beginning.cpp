#include <iostream>
using namespace std;
struct SNode
{
    int value;
    SNode* pNext;
};
SNode* pHead;

void insertAtBegin(int data) {
    SNode* pTemp1 = (SNode*) malloc(sizeof(struct SNode*));
    pTemp1->value = data;
    pTemp1->pNext = pHead;
    pHead = pTemp1;
}

void print() {
    SNode* pTemp = pHead;
    while (pTemp != NULL)
    {
        cout << pTemp->value << " ";
        pTemp = pTemp->pNext;

    }
    cout << endl;
}

int main()
{
    pHead = NULL;
    insertAtBegin(5);
    print();


    insertAtBegin(4);
    print();


    insertAtBegin(3);
    print();


    insertAtBegin(2);
    print();


    insertAtBegin(1);
    print();

    std::cout << "Hello World!\n";
}