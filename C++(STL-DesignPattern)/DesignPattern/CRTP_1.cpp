#include <iostream>
using namespace std;
template <typename T>
struct Base{
    void m_fun(){
        (static_cast<T*>(this))->m_fun();
    }
};

struct Derived : Base <Derived>{
    void m_fun(){
        cout <<"derived fun" <<endl;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;

    Base<Derived> *bp = new Derived;
    bp->m_fun();
    return 0;
}
