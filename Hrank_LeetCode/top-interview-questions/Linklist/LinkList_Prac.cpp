// Link List
#include<bits/stdc++.h>
using namespace std;

template <typename TYPE>
class linkList {
public:
    struct Node {
        TYPE _data;
        Node* _pNext;
        Node(TYPE data) : _data(data), _pNext(nullptr) {}
        Node(TYPE data, Node* pNext) : _data(data), _pNext(pNext) {}
    };

    void insertAtEnd(Node*& pHead, TYPE data) {
        // Generic LL, i.e insert after Head.
        Node* pNew = new Node(data);

        if (pHead == nullptr) {
            pHead = pNew;
            return;
        }

        Node* pLastNode = pHead;
        while (pLastNode->_pNext) { pLastNode = pLastNode->_pNext; }
        pLastNode->_pNext = pNew;
    }

    void insertAtFront(Node*& pHead, TYPE data) {
        // Stack, i.e i.e insert before Head.
        pHead = new Node(data, pHead);
    }

    void display(Node* pHead) {
        Node* pTemp = pHead;
        while (pTemp) {
            cout << pTemp->_data << "\t";
            pTemp = pTemp->_pNext;
        }
        cout << endl;
    }

    void testLL(Node* pHead, vector<TYPE>& res) {
        Node* pTemp = pHead;

        for (auto idx = 0; pTemp; idx++) {
            assert(pTemp->_data == res[idx]);
            pTemp = pTemp->_pNext;
        }
        cout << endl;
    }


    Node* removeNthNodeFromBack(Node*& pHead, size_t pos) {
        Node* pLeft = pHead, * pRight = pHead;
        while (pos--) { pRight = pRight->_pNext; }
        if (pRight == nullptr) { // delete Head
            Node* pDel = pHead;
            pHead = pHead->_pNext;
            delete(pDel);
            return pHead;
        }
        else {
            /*  Initial :
                -   -   -   -   -   -   -
                <------>R
                   pos

                Final :
                -   -   -   -   -   -   -
                                   pos
                                L<----->R
                                    ^
                                    |
                                   Del
                and then del L->next
            */

            while (pRight->_pNext) { pRight = pRight->_pNext; pLeft = pLeft->_pNext; }
            Node* pDel = pLeft->_pNext;
            pLeft->_pNext = pLeft->_pNext->_pNext;
            delete(pDel);
            return pHead;
        }
    }

    void reverseList(Node*& pHead) {
        Node* pCur = pHead;
        Node* pRev = nullptr;
        while (pCur) {
            Node* pNext = pCur->_pNext;
            pCur->_pNext = pRev;

            pRev = pCur;
            pCur = pNext;
        }
        pHead = pRev;
    }

    Node* mergeList(Node* pHead1, Node* pHead2) {
        Node Dummy(0);
        Node* pTail = &Dummy;

        while (pHead1 and pHead2) {
            if (pHead1->_data < pHead2->_data) {
                pTail->_pNext = pHead1;
                pHead1 = pHead1->_pNext;
            }
            else {
                pTail->_pNext = pHead2;
                pHead2 = pHead2->_pNext;
            }
            pTail = pTail->_pNext;
        }

        if (pHead1) { pTail->_pNext = pHead1; }
        else if (pHead2) { pTail->_pNext = pHead2; }

        return Dummy._pNext;
    }

    bool hasCycle(Node* pHead) {
        Node* pSlow = pHead, * pFast = pHead;
        while (pFast && pFast->_pNext) {
            pFast = pFast->_pNext->_pNext;
            pSlow = pSlow->_pNext;
            if (pFast == pSlow) return true;
        }

        return false;

    }

    void makeLoop(Node*& pHead) {
        if (pHead == nullptr) return;
        Node* pEnd = pHead;
        while (pEnd->_pNext) { pEnd = pEnd->_pNext; }
        pEnd->_pNext = pHead;
    }

};

int main() {
    linkList<int> s;
    linkList<int>::Node* pHead1 = nullptr;
    linkList<int>::Node* pHead2 = nullptr;


    s.insertAtEnd(pHead1, 1);
    s.insertAtEnd(pHead1, 3);
    s.insertAtEnd(pHead1, 5);
    s.insertAtEnd(pHead1, 7);
    s.insertAtEnd(pHead1, 9);
    s.insertAtEnd(pHead1, 11);
    s.insertAtEnd(pHead1, 13);

    //  s.display(pHead1);

    {
        vector<int> res = { 1,3,5,7 ,9,11,13 };
        s.testLL(pHead1, res);
    }

    s.removeNthNodeFromBack(pHead1, 2);
    {
        vector<int> res = { 1,3,5,7 ,9,13 };
        s.testLL(pHead1, res);
    }

    s.removeNthNodeFromBack(pHead1, 6);
    {
        vector<int> res = { 3,5,7 ,9,13 };
        s.testLL(pHead1, res);
    }

    s.reverseList(pHead1);
    {
        vector<int> res = { 13, 9 ,7 ,5 ,3 };
        s.testLL(pHead1, res);
    }

    s.insertAtEnd(pHead2, 10);
    s.insertAtEnd(pHead2, 30);
    s.insertAtEnd(pHead2, 50);
    s.insertAtEnd(pHead2, 70);


    linkList<int>::Node* pHead3 = s.mergeList(pHead1, pHead2);
    {
        vector<int> res = { 10, 13,9,7,5,3,30,50,70 };
        s.testLL(pHead3, res);
    }

    // s.display(pHead1);

    assert(s.hasCycle(pHead3) == false);
    s.makeLoop(pHead3);
    assert(s.hasCycle(pHead3) == true);

    cout << "PASS" << endl;
    return 0;
}