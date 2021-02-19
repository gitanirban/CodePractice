// ConsoleApplication2_Link_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct SNode
{
    int value;
    SNode* pNext;
};
SNode* pHead;

void insertAtN(int data, int n) {
    SNode* pTemp1 = (SNode*)malloc(sizeof(struct SNode*));
    pTemp1->value = data;
    pTemp1->pNext = NULL;
    if (n == 1) {
        pTemp1->pNext = pHead;
        pHead = pTemp1;
        return;
    }

    SNode* pTemp2 = pHead;
    for (int i = 0; i < n-2; i++)
    {
        pTemp2 = pTemp2->pNext;
    }
    pTemp1->pNext = pTemp2->pNext;
    pTemp2->pNext = pTemp1;
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
    insertAtN(5, 1);
    print();


    insertAtN(4,1);
    print();


    insertAtN(3,2);
    print();


    insertAtN(2,1);
    print();


    insertAtN(1,2);
    print();

    std::cout << "Hello World!\n";
}