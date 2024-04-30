// Link List Merge sort
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

    Node* mergeList(Node*& pHead1, Node*& pHead2) {
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


    Node* findMiddle(Node* head) {
        if (!head || !head->_pNext) return head;

        Node* slow = head;
        Node* fast = head;

        while (fast->_pNext && fast->_pNext->_pNext) {
            slow = slow->_pNext;
            fast = fast->_pNext->_pNext;
        }

        return slow;
    }

    void mergeSort(Node*& pHead) {
        if (!pHead || !pHead->_pNext) return; // Base case: 0 or 1 node

        // Find middle of the linked list
        Node* mid = findMiddle(pHead);
        Node* midNext = mid->_pNext;
        mid->_pNext = nullptr;

        // Recursively sort the left and right halves
        mergeSort(pHead);
        mergeSort(midNext);

        // Merge the sorted halves
        pHead = mergeList(pHead, midNext);
    }
};
int main() {
    linkList<int> s;
    linkList<int>::Node* pHead1 = nullptr;
    s.insertAtEnd(pHead1, 100);
    s.insertAtEnd(pHead1, 90);
    s.insertAtEnd(pHead1, 80);
    s.insertAtEnd(pHead1, 70);
    s.insertAtEnd(pHead1, 60);
    {
        vector<int> res = { 100, 90,80,70,60 };
        s.testLL(pHead1, res);
    }
    s.mergeSort(pHead1);

    {
        vector<int> res = { 60,70,80,90,100 };
        s.testLL(pHead1, res);
    }

    cout << "Success" << endl;
    return 0;
}




