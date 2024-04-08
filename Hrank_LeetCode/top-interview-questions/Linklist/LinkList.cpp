
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

public:
    void insertNode(ListNode*& pHead, int val) {
        ListNode* pNewNode = new ListNode(val);
        if (pHead == nullptr)
            pHead = pNewNode;
        else {
            ListNode* pLastNode = pHead;
            while (pLastNode->next) {
                pLastNode = pLastNode->next;
            }
            pLastNode->next = pNewNode;
                                                            }                                                                                                                                                                                                      
    }
    ListNode* removeNthFromEnd1(ListNode*& pHead, int n) {
        // Remove the nth node from the end of the list and return its head.
        ListNode* pNodeLast = pHead;
        uint32_t sz = 0;
        while (pNodeLast) {
            pNodeLast = pNodeLast->next;
            sz++;
        }

        int n_back = sz - n - 1;

        if (n_back < 0) {
            // Handle the case where the head needs to be removed
            ListNode* pNodeToDelete = pHead;
            pHead = pHead->next;
            delete(pNodeToDelete);
        }
        else {
            pNodeLast = pHead;
            while (n_back-- > 0 and pNodeLast->next) {
                pNodeLast = pNodeLast->next;
            }

            ListNode* pNodeToDelete = pNodeLast->next;
            pNodeLast->next = pNodeLast->next->next;

            // Check if the node to be deleted is the last node
            if (n_back == 0 && pNodeToDelete->next == nullptr) {
                pNodeLast->next = nullptr;
            }

            delete(pNodeToDelete);
        }

        return pHead;
    }

    ListNode* removeNthFromEnd(ListNode*& pHead, int n) {
        // Remove the nth node from the end of the list and return its head.
        ListNode* pCopyHead = pHead;
        ListNode* pLeft = pHead, * pRight = pHead;


        for (int i = 0; i < n; i++)
            pRight = pRight->next;

        if (pRight == nullptr) {
            ListNode* to_be_deleted = pHead;
            pHead = pHead->next;

            delete(to_be_deleted);
            return pHead;
        }
        else {
            while (pRight->next)
            {
                pRight = pRight->next;
                pLeft = pLeft->next;
            }
            ListNode* to_be_deleted = pLeft->next;
            pLeft->next = pLeft->next->next;

            delete(to_be_deleted);
            return pCopyHead;
        }
    }

    void displayNodes(ListNode*& pHead) {
        ListNode* pLastNode = pHead;
        while (pLastNode) {
            std::cout << pLastNode->val << "\t";
            pLastNode = pLastNode->next;
        }
        cout << endl;
    }

    // You can implement the other functions here...

    void deleteMiddleNode(ListNode* node, ListNode* pHead) {
        if (node == nullptr || node->next == nullptr) {
            // Handle the case where the input node is nullptr or the last node
            return;
        }

        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }


    ListNode* reverseList(ListNode*& head) {
        ListNode* pCurrent = head;
        ListNode* pPrev = nullptr;

        while (pCurrent)
        {
            ListNode* next = pCurrent->next;
            pCurrent->next = pPrev;

            pPrev = pCurrent;
            pCurrent = next;
        }
        head = pPrev;

        return head;
    }

    /* ListNode* mergeTwoListsMy(ListNode*& list1, ListNode*& list2) {  //merge   Two Sorted Lists
        ListNode* newHead = nullptr;
        if (list1 == nullptr and list2 == nullptr) return nullptr;
        ListNode* pCurrent = nullptr;

        while (list1 or list2) {

            int b1 = getBegin(list1);
            int b2 = getBegin(list2);
            int small;
            ListNode* pAdd = nullptr;
            ListNode* pLast = nullptr;


            if (b1 > b2) {
                if (list2 == nullptr) continue;
                small = b2;
                pAdd = popBegin(list2);
                if (pAdd == nullptr) continue;
                if (newHead == nullptr) {
                    newHead = pAdd;
                    newHead->next = nullptr;
                    pCurrent = newHead;
                }
                else {
                    pCurrent->next = pAdd;
                    pCurrent = pCurrent->next;

                }
            }
            else {
                if (list1 == nullptr) continue;
                small = b1;
                pAdd = popBegin(list1);
                if (pAdd == nullptr) continue;
                if (newHead == nullptr) {
                    newHead = pAdd;
                    newHead->next = nullptr;
                    pCurrent = newHead;

                }
                else {
                    //newHead->next = pAdd;
                    pCurrent->next = pAdd;
                    pCurrent = pCurrent->next;

                }
            }
            //  cout << "\t" << small << "\t";

        }
        //cout << endl;
        return newHead;
    }

    int getBegin(ListNode*& pHead) {
        return (pHead == nullptr) ? UINT16_MAX : pHead->val;
    }

    ListNode* popBegin(ListNode*& pHead) {
        if (pHead == nullptr)
            return nullptr;

        ListNode* tmp = pHead;
        pHead = pHead->next;

        return tmp;
    } */

    ListNode* mergeTwoLists(ListNode*& list1, ListNode*& list2) {
        ListNode dummy(0);
        ListNode* pTail = &dummy;

        while (list1 and list2) {

            if (list1->val < list2->val) {
                pTail->next = list1;
                list1 = list1->next;
            }
            else {
                pTail->next = list2;
                list2 = list2->next;
            }
            pTail = pTail->next;
        }

        if (list1)
            pTail->next = list1;
        else
            pTail->next = list2;

        return dummy.next;
    }
    bool hasCycle(ListNode*& head) {
        ListNode* slow = head, * fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;

    }

};

int main() {
    Solution s;
    Solution::ListNode* pHead1 = nullptr;
    s.insertNode(pHead1, 1);
    s.insertNode(pHead1, 3);
    s.insertNode(pHead1, 5);
    s.insertNode(pHead1, 7);
    s.displayNodes(pHead1);

    // (void)s.removeNthFromEnd(pHead, 4);
   // s.reverseList(pHead);

    Solution::ListNode* pHead2 = nullptr;
    s.insertNode(pHead2, 2);
    s.insertNode(pHead2, 4);
    s.insertNode(pHead2, 6);
    s.insertNode(pHead2, 8);

    s.displayNodes(pHead2);

    Solution::ListNode* pNewMergedHead = s.mergeTwoLists(pHead1, pHead2);
    s.displayNodes(pNewMergedHead);

    return 0;
}
