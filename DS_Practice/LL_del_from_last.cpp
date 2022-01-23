#include <iostream>
using namespace std;
struct _Node{
    int val;
    struct _Node *pNext;
};
struct _Node *pHead = nullptr;
void insertAtNode(int value){
    _Node* pTemp = (_Node*) malloc(sizeof(struct _Node));
    pTemp->val = value;
    pTemp->pNext = nullptr;

    if(pHead == NULL){
        pHead = pTemp;
    }
    else{
        _Node* pEnd = pHead;
        while (pEnd->pNext != nullptr){
            pEnd = pEnd->pNext;
        }
    pEnd->pNext = pTemp;
    }

}

void displayLL(){
    _Node *pTemp = pHead;
    while (pTemp != nullptr) {
        cout << pTemp->val << endl;
        pTemp = pTemp->pNext;
    }
}

void delFromBackWithPos(int pos){
    _Node * pStart = pHead;
    _Node * pLast = pHead;

    for(int i =0; i< pos; i++) {
        pLast = pLast->pNext;
    }

    while(pLast->pNext != nullptr){
        pStart = pStart->pNext;
        pLast = pLast->pNext;
    }

    _Node *pNodeToDel = pStart->pNext;
    pStart->pNext = pStart->pNext->pNext;
    free(pNodeToDel);
}
int main() {
    cout << "Hello, World!" << endl;
    insertAtNode(77);
    insertAtNode(88);
    insertAtNode(1);
    insertAtNode(6);
    insertAtNode(2);
    insertAtNode(9);

    displayLL();
    delFromBackWithPos(6);
    cout << "after deletion" << endl;
    displayLL();

    return 0;
}


