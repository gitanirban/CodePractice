/*1507. Reformat Date Leet Code
Easy - Given a date string in the form Day Month Year, where:

Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
Year is in the range [1900, 2100].
Convert the date string to the format YYYY-MM-DD, where:

YYYY denotes the 4 digit year.

 MM denotes the 2 digit month.
DD denotes the 2 digit day.*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string reformatDate(const string& date) {
        int pos_of_first_space = date.find(' ');
       // cout << "pos_of_first_space : " << pos_of_first_space << endl;
        string dd = date.substr(0, date.length() - TOTAL_LEN_FROM_END_EXPECT_DD);
       // cout << dd << endl;
        string mm = date.substr(pos_of_first_space+1, MONTH_LEN);
        auto itr = m_monthMap.find(mm);
        if (itr == m_monthMap.end()) {
            cout << "err" << endl;
        }
       // cout << itr->second << endl;
       string yyyy = date.substr(pos_of_first_space+1+MONTH_LEN+1, YEAR_LEN);
        //cout << yyyy << endl;
        res = yyyy+ "-" +itr->second + "-" + dd;
        return res;
    }
    static void myInit() {
        m_monthMap.insert({"Jan", "01" });
        m_monthMap.insert({"Feb", "02" });
        m_monthMap.insert({"Mar", "03" });
        m_monthMap.insert({"Apr", "04" });
        m_monthMap.insert({"May", "05" });
        m_monthMap.insert({"Jun", "06" });
        m_monthMap.insert({"Jul", "07" });
        m_monthMap.insert({"Aug", "08" });
        m_monthMap.insert({"Sep", "09" });
        m_monthMap.insert({"Oct", "10" });
        m_monthMap.insert({"Nov", "11" });
        m_monthMap.insert({"Dec", "12" });
    }
private:
    static map<string, string> m_monthMap;
    string res;
    static constexpr uint8_t YEAR_LEN{4};
    static constexpr uint8_t MONTH_LEN{3};
    static constexpr uint8_t DATE_LEN{2};
    static constexpr uint8_t SUPERSCRIPT_LEN{2};
    static constexpr uint8_t TOTAL_LEN_FROM_END_EXPECT_DD{YEAR_LEN+1+MONTH_LEN+1+SUPERSCRIPT_LEN};
};
map<string, string> Solution::m_monthMap;
int main() {
    Solution s1, s2;
    s1.myInit();
    cout << s1.reformatDate("20th Oct 2052") << endl;
    cout << s2.reformatDate("2th Nov 2052") << endl;
    return 0;
}
