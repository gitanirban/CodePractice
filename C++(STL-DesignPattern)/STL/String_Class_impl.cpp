#include <bits/stdc++.h>
using namespace std;

class String {
public:
    std::string toStdString() const {
        return std::string(m_pResource, m_length);
    }
    String() : m_pResource(nullptr), m_length(0) {}


    String(char const* pArg) {
        m_length = strlen(pArg);
        m_pResource = new char[m_length + 1];
        strcpy(m_pResource, pArg);
    }

    String(String const& other)
    {
        m_length = other.m_length;
        m_pResource = new char[m_length + 1];
        strcpy(m_pResource, other.m_pResource);
    }

    /*
     * Better copy assignment operator using CAS idiom (copy and swap idiom)
     * overloaded assignment operator argument passed by value. calls copy ctor.
     * Important note : INPUT CAN'T BE A REFERENCE.
     */
    String& operator=(String other)
    {
        swap(other.m_pResource, m_pResource);
        swap(other.m_length, m_length);
        return *this;
    }

    String(String&& other)
    {
        m_length = other.m_length;
        m_pResource = other.m_pResource;
        other.m_length = 0;
        other.m_pResource = nullptr;
    }


    friend ostream& operator << (ostream& out, const String& rStr);
    friend istream& operator >> (istream& in, const String& rStr);

private:
    char* m_pResource;
    size_t m_length;

};

ostream& operator <<(ostream& out, String const& other) {
    out << other.m_pResource;
    return out;
}

istream& operator >>(istream& in, String const& other) {
    in >> other.m_pResource;
    return in;
}

int main() {
    String s; //default Ctr
    assert(s.toStdString() == "");

    String s1 = "Hello 1"; // parameterised ctor
    assert(s1.toStdString() == "Hello 1");


    String s2(s1); // copy ctor
    //  String s2 = s1; // copy ctor
    assert(s2.toStdString() == "Hello 1");


    String s3 = move(s2);
    assert(s3.toStdString() == "Hello 1");
    assert(s2.toStdString() == "");


    String s4;
    s4 = s1; //copy assignment operator 
    assert(s4.toStdString() == "Hello 1");
    assert(s1.toStdString() == "Hello 1");

    String h = "Hello"; //default Ctr
    String w = "World"; //default Ctr

    cout << h << w << endl; // overload <<





    return 0;
}