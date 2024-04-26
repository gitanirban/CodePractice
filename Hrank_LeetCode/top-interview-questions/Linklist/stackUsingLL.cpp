// Stack using LL
#include<bits/stdc++.h>
using namespace std;

template <typename TYPE>
class StackLinkList {
public:
    struct Node {
        TYPE m_data;
        Node* m_pPrev;
        Node(TYPE data) : m_data(data), m_pPrev(nullptr) {}
    };
    Node* pTop = nullptr;

    void push(TYPE data) {
        Node* pTemp = new Node(data);
        pTemp->m_pPrev = pTop;
        pTop = pTemp;
    }

    TYPE pop() {
        if (pTop) {
            Node* pTemp = pTop;
            TYPE data = pTemp->m_data;
            pTop = pTemp->m_pPrev;
            free(pTemp);
            return data;
        }
        return 0;
    }


    TYPE getTop() {
        if (pTop) {
            Node* pTemp = pTop;
            TYPE data = pTemp->m_data;
            return data;
        }
        return 0;
    }

    bool isEmpty() {
        return pTop == nullptr;
    }

};

string reverseWords(string& rInput) {
    string output;

    StackLinkList<string> stack;
    string word;
    for (auto idx = 0; idx < rInput.length(); idx++) {
        if (rInput[idx] != ' ') {
            word += rInput[idx];
        }
        else if ((rInput[idx] == ' ') or (idx == rInput.length())) {
            stack.push(word + " ");
            word = "";
        }

    }
    stack.push(word + " "); // push the last word


    while (stack.isEmpty() == false)
    {
        output += stack.pop();
    }
    return output;
}
int main() {

    { // test string word reverses
        string input = "This is test.";
        string out = "test. is This ";
        assert(out == reverseWords(input));

    }

    cout << "\nsuccess" << endl;
    return 0;
}


#ifdef testInt
int main() {

    { // test with int
        StackLinkList<int> s;
        assert(s.isEmpty() == true);
        s.push(1);
        s.push(2);
        s.push(3);
        assert(s.getTop() == 3);
        assert(s.pop() == 3);
        assert(s.isEmpty() == false);
        assert(s.getTop() == 2);
        assert(s.pop() == 2);
        assert(s.pop() == 1);
        assert(s.pop() == 0);
        assert(s.isEmpty() == true);

    }
    cout << "\nsuccess" << endl;
    return 0;
}
#endif