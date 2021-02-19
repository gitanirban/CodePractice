#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <iostream>
#include <string>
#include <map>
using namespace std;
class emp
{
public:
    emp(string lName, string fName, int roll) : m_lName(lName), m_fName(fName), m_roll(roll)//
    {
        // m_lName(lName);
          // m_fName(fName);
           //m_roll = roll;

    }
    void view() {

        cout << m_fName << m_lName << m_roll << endl;

    }


    string m_lName;
    string m_fName;
    int m_roll;
};
int main()
{
    cout << "Hello world!" << endl;
    //_emp Anirban = _emp(8);//"Sengupta","Anirban",
    emp ani("sen","Ani",8);
    emp kank("sar", "Kank", 45);
    emp sudipta("das", "sudip", 7);
    emp jag("sing", "jag", 8);

    map<string, class emp> list;

    list.insert(pair<string, emp>("sen", ani));
    list.insert(pair<string, emp>("sar", kank));
    list.insert(pair<string, emp>("das", sudipta));
    list.insert(pair<string, emp>("sing", jag));

    string query;
    cout << "enter surname to query" <<endl;
    cin >> query;

    //auto itr = list.find(query);
    cout << list.find(query)->second.m_fName() <<endl;


    return 0;
}