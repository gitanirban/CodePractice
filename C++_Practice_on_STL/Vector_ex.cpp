//VECTOR EXCERSIZE

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<int> v_int;
    vector<int>::iterator it1;
    v_int.push_back(1);
    v_int.push_back(2);

    /*for(it1 =v_int.begin(); it1<v_int.end(); it1++){

        cout << " value at : "<<*it1<<endl;
    }
    printf("%d", v_int.begin()); */
    for(int j=0;j<v_int.size();j++){
        cout << "index : "<<j<<" value : "<<v_int.at(j)<<endl;
    }

    return 0;
}