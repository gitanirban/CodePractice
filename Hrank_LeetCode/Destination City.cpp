// Destination city 
// Hack Sussex Coder's cup 2024

#include<bits/stdc++.h>
using namespace std;

string destinationCity(vector<vector<string>> ip) {
    string res;
    size_t s = 0, e = 1;
    size_t sz = ip.size();
    while (e < sz - 1) {
        if (ip[s][1] != ip[e][0])
        {
            s++;
        }
        e++;
    }

    res.append(ip[e][1]);
    return res;
}

int main() {
    {
        vector<vector<string>> ip = {
                                       {"London", "New York"},
                                       {"New York", "Lima"},
                                       {"Lima", "Sao Paulo"}
        };

        string op = destinationCity(ip);
        assert("Sao Paulo" == op);
    }


        string op = destinationCity(ip);
        assert("Sao Paulo" == op);
    }

  
    cout << "All test cases passed!" << endl;
}
