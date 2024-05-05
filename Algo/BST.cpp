// BST 
// insert
// search
// find hight
// minimum max of BST

// https://www.youtube.com/watch?v=Ut90klNN264&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=30
// todo https://www.youtube.com/watch?v=QfJsau0ItOY&list=PLot-Xpze53ldg4pN6PfzoJY7KsKcxF1jg
// traversal BFS dfs
#include<bits/stdc++.h>
using namespace std;

template <typename TYPE>
class BST {
public:
    struct Node {
        TYPE m_data;
        Node* m_pLeft;
        Node* m_pRight;
        Node(TYPE data) :m_data(data), m_pLeft(nullptr), m_pRight(nullptr) {}
    };

    static Node* insert(Node* pRoot, TYPE data) {
        Node* pNew = new Node(data);
        if (pRoot == nullptr) { pRoot = pNew; }
        else if (data < pRoot->m_data) { pRoot->m_pLeft = insert(pRoot->m_pLeft, data); }
        else { pRoot->m_pRight = insert(pRoot->m_pRight, data); }

        return pRoot;
    }
    static bool search(Node* pRoot, TYPE value) {
        if (pRoot == nullptr) { return false; }
        else if (pRoot->m_data == value) { return true; }
        else if (value < pRoot->m_data) { return search(pRoot->m_pLeft, value); }
        else { return search(pRoot->m_pRight, value); }
    }
    static size_t findHight(Node* pRoot) {
        if (pRoot == nullptr) { return 0; }
        return max(findHight(pRoot->m_pLeft), findHight(pRoot->m_pRight)) + 1;
    }

    static TYPE findMin(Node* pRoot) {
        if (pRoot == nullptr) return TYPE();
        while (pRoot->m_pLeft != nullptr) pRoot = pRoot->m_pLeft;
        return pRoot->m_data;
    }
};

int main() {
    BST<int>::Node* pRoot = nullptr;

    pRoot = BST<int>::insert(pRoot, 100);
    pRoot = BST<int>::insert(pRoot, 80);
    pRoot = BST<int>::insert(pRoot, 70);
    pRoot = BST<int>::insert(pRoot, 50);
    pRoot = BST<int>::insert(pRoot, 200);

    assert(BST<int>::search(pRoot, 100) == true);
    assert(BST<int>::search(pRoot, 50) == true);
    assert(BST<int>::search(pRoot, 200) == true);
    assert(BST<int>::search(pRoot, 1) == false);
    size_t hight = BST<int>::findHight(pRoot);
    assert(hight == 4);

    assert(BST<int>::findMin(pRoot) == 50);


    return 0;
}