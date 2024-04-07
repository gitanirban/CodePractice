#include <iostream>

using std::cout;
using std::endl;

template<class DERIVED>
class Base {
public:
    void speak() { (reinterpret_cast<DERIVED*>(this))->vocalise(); }
};

class Cat : public Base<Cat> {
public:
    void vocalise() { cout << "Meow " << endl; }
};

class Dog : public Base<Dog> {
public:
    void vocalise() { cout << "Vow  " << endl; }
};

int main() {

    Base<Cat> cat;
    Base<Dog> dog;

    cat.speak();
    dog.speak();

    return 0;
}