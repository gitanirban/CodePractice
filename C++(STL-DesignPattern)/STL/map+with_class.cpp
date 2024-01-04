#include <iostream>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <string>
#include <utility>

using namespace std;
struct Foo {
    Foo(int val_) : val(val_) {}
    int val;
    bool operator==(const Foo& rhs) const {
        return val == rhs.val;
    }
};

namespace std {
    template<> struct hash<Foo> {
        std::size_t operator()(const Foo& f) const {
            return std::hash<int>{}(f.val);
        }
    };
}

int main()
{
    std::cout << "Hello World!\n";
    std::unordered_map<Foo, std::string> m7 = {
      { Foo(1), "One"}, { 2, "Two"}, { 3, "Three"}
    };

    cout << m7.find(Foo(1))->second << endl;
    cout << (5 % 5) << endl;


}