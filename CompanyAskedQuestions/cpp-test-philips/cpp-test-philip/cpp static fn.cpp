#include <iostream>
#include <cstdint>

using namespace std;

class H1{ int x =2.5;};
class H2{
    static H1 h;
    public:
    H2(){
        cout << "h2 has h " << endl;
    }

    static H1 printH(){
        cout <<"h has a var x "<< endl;
        return h; 
    }
};

H1 H2::h;

int main() {
 H2 d1, d2;
 H1 h = H2::printH();
 H1 g = H2::printH();

    return 0;
}