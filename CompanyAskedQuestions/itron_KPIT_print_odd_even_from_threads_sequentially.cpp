#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LogFile{
    std::mutex m_mu;
    ofstream m_f;
public:
    LogFile(){
        m_f.open("log1.txt");
    }
    void share_print(string msg, int id){
        std::lock_guard<std::mutex> lg(m_mu);
        m_f << msg << id << "\n";
       // std::this_thread::yield();
    }
    ~LogFile(){
        m_f.close();
    }
};


class Functor{
    LogFile &m_log;
public:
    Functor(LogFile &lRef) : m_log(lRef){}

    void operator() (){
        for(auto i = 0; i <= 50; i++)
            if(i%2 == 0){
            m_log.share_print(string("From Functor Thread: "), i);
            std::this_thread::yield();
            }
    }
};
int main() {
LogFile log;
Functor fObj(log);

    std::thread t1(fObj);

    for(auto i = 0; i <= 50; i++)
        if(i%2 != 0){
        log.share_print(string("From main Thread: "), i);
        std::this_thread::yield();
        }
    if(t1.joinable())
        t1.join();
    return 0;
}
