// 206. Reverse Linked List
#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
template <typename TYPE>
class LinkList {
public:
    struct ListNode
    {
        TYPE val;

        ListNode* next{ nullptr };
        ListNode* prev{ nullptr };
        ListNode* random{ nullptr };

        ListNode(TYPE data) :val(data) {}
        ListNode(TYPE data, ListNode* pPrev) :val(data), prev(pPrev) {}
    };
    typedef struct ListNode Node;

    static ListNode* reverseList(ListNode*& pHead) {
        ListNode* pCurr = pHead;
        ListNode* prev = nullptr;
        while (pCurr) {
            ListNode* pNext = pCurr->next;
            pCurr->next = prev;

            prev = pCurr;
            pCurr = pNext;
        }
        pHead = prev;

        return pHead;
    }

    static ListNode* insert_back(ListNode*& pHead, TYPE data) {
        ListNode* pNew = new ListNode(data);
        if (pHead == nullptr) {
            pHead = pNew;
            return pHead;
        }

        ListNode* pLast = pHead;
        while (pLast->next) { pLast = pLast->next; }
        pLast->next = pNew;
        return pHead;
    }

    static void testLL(ListNode* pHead, vector<int>& inp) {
        for (auto n : inp) {
            assert(pHead->val == n);
            pHead = pHead->next;
        }
    }

    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode Dummy(0);
        ListNode* pTail = &Dummy;

        while (list1 and list2) {
            if (list1->val > list2->val) {
                pTail->next = list2;
                list2 = list2->next;
            }
            else {
                pTail->next = list1;
                list1 = list1->next;
            }
            pTail = pTail->next;
        }
        if (list1) { pTail->next = list1; }
        else if (list2) { pTail->next = list2; }

        return Dummy.next;
    }

    static void reorderList(ListNode* pHead) {

        ListNode* pLast = pHead;
        size_t sz = 1;
        while (pLast->next)
        {
            pLast = pLast->next; sz++;
        }
        if (sz == 1) { return; }
        if (sz == 2) { return; }
        ListNode* Nodes[sz];
        pLast = pHead;
        size_t idx = 0;
        while (pLast)
        {
            Nodes[idx++] = pLast;
            pLast = pLast->next;
        }

        ListNode* pStart = pHead;
        ListNode* pNext = pHead->next;
        idx = sz - 1;
        pLast = Nodes[idx];
        ListNode* pPrev = Nodes[idx - 1];


        sz /= 2;
        while (sz--) {
            pStart->next = pLast;
            pLast->next = pNext;

            pStart = pNext;
            pNext = pNext->next;

            pLast = pPrev;
            pPrev = Nodes[--idx - 1];
        }
        pStart->next = nullptr;
    }

    static ListNode* removeNthFromEnd(ListNode* pHead, int n) {
        ListNode* pDelNext = pHead, * pEnd = pHead;

        for (auto i = 0; i < n; i++)
        {
            pEnd = pEnd->next;
        }

        if (pEnd == nullptr) { // del head;
            pHead = pHead->next;
            return pHead;
        }
        while (pEnd->next) {
            pEnd = pEnd->next;
            pDelNext = pDelNext->next;
        }
        ListNode* pDel = pDelNext->next;
        pDelNext->next = pDelNext->next->next;
        delete(pDel);

        return pHead;
    }

    static Node* copyRandomList(Node* pHead) {
        Node* pCur = pHead;
        unordered_map<Node*, Node*> oldToNewMap{ {nullptr,nullptr} };
        while (pCur) {
            Node* pNew = new Node(pCur->val);
            oldToNewMap[pCur] = pNew;
            pCur = pCur->next;
        }

        pCur = pHead;
        while (pCur) {
            Node* pCopy = oldToNewMap[pCur];
            pCopy->next = oldToNewMap[pCur->next];
            pCopy->random = oldToNewMap[pCur->random];
            pCur = pCur->next;

        }

        return oldToNewMap[pHead];
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* pCur = dummy;

        size_t carry = 0;
        while (l1 or l2 or carry)
        {
            size_t l1Val = l1 ? l1->val : 0;
            size_t l2Val = l2 ? l2->val : 0;
            size_t sum = l1Val + l2Val + carry;

            size_t val = sum % 10;
            carry = sum / 10;

            pCur->next = new ListNode(val);

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            pCur = pCur->next;
        }
        return dummy->next;
    }

    bool hasCycle(ListNode* pHead) {
        if (pHead == nullptr) return false;
        Node* pSlow = pHead, pFast = pHead;
        while (pSlow->next and pFast->next and pFast->next->next )
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            if (pSlow == pFast) { return true; }
        }
        return false;
    }
};

int main() {
    {
        LinkList<int>::ListNode* pHead1 = nullptr;

        (void)LinkList<int>::insert_back(pHead1, 1);
        (void)LinkList<int>::insert_back(pHead1, 3);
        (void)LinkList<int>::insert_back(pHead1, 100);
        (void)LinkList<int>::insert_back(pHead1, 500);
        {
            vector<int> ip = { 1,3,100,500 };
            (void)LinkList<int>::testLL(pHead1, ip);
        }

        (void)LinkList<int>::reverseList(pHead1);
        {
            vector<int> ip = { 500,100,3,1 };
            (void)LinkList<int>::testLL(pHead1, ip);
        }
        (void)LinkList<int>::reverseList(pHead1);
        {
            vector<int> ip = { 1,3,100,500 };
            (void)LinkList<int>::testLL(pHead1, ip);
        }

        LinkList<int>::ListNode* pHead2 = nullptr;
        (void)LinkList<int>::insert_back(pHead2, 2);
        (void)LinkList<int>::insert_back(pHead2, 4);
        (void)LinkList<int>::insert_back(pHead2, 400);
        (void)LinkList<int>::insert_back(pHead2, 600);
        {
            vector<int> ip = { 2,4,400,600 };
            (void)LinkList<int>::testLL(pHead2, ip);
        }

        LinkList<int>::ListNode* mergedHead = LinkList<int>::mergeTwoLists(pHead1, pHead2);
        {
            vector<int> ip = { 1,3,100,500,2,4,400,600 };
            sort(ip.begin(), ip.end());
            (void)LinkList<int>::testLL(mergedHead, ip);
        }

        LinkList<int>::ListNode* pHead3 = nullptr;
        (void)LinkList<int>::insert_back(pHead3, 1);
        (void)LinkList<int>::insert_back(pHead3, 2);
        (void)LinkList<int>::insert_back(pHead3, 3);
        (void)LinkList<int>::insert_back(pHead3, 4);

        {
            LinkList<int>::reorderList(pHead3);
            vector<int> ip = { 1,4,2,3 };
            (void)LinkList<int>::testLL(pHead3, ip);
        }


        LinkList<int>::ListNode* pHead4 = nullptr;
        (void)LinkList<int>::insert_back(pHead4, 1);

        {
            LinkList<int>::reorderList(pHead4);
            vector<int> ip = { 1 };
            (void)LinkList<int>::testLL(pHead4, ip);
        }

        LinkList<int>::ListNode* pHead5 = nullptr;
        (void)LinkList<int>::insert_back(pHead5, 1);
        (void)LinkList<int>::insert_back(pHead5, 2);
        (void)LinkList<int>::insert_back(pHead5, 3);
        (void)LinkList<int>::insert_back(pHead5, 4);
        (void)LinkList<int>::insert_back(pHead5, 5);

        {
            LinkList<int>::removeNthFromEnd(pHead5, 2);
            vector<int> ip = { 1 ,2,3,5 };
            (void)LinkList<int>::testLL(pHead5, ip);
        }

        LinkList<int>::ListNode* pHead6 = nullptr;
        (void)LinkList<int>::insert_back(pHead6, 1);
        (void)LinkList<int>::insert_back(pHead6, 2);
        {
            LinkList<int>::removeNthFromEnd(pHead6, 1);
            vector<int> ip = { 1 };
            (void)LinkList<int>::testLL(pHead6, ip);
        }

        LinkList<int>::ListNode* pHead7 = nullptr;
        (void)LinkList<int>::insert_back(pHead7, 1);

        {
            LinkList<int>::removeNthFromEnd(pHead7, 1);
            vector<int> ip = {  };
            (void)LinkList<int>::testLL(pHead7, ip);
        }

    }

    cout << "Success" << endl;
    return 0;
}
