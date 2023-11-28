// #dailybiteofcpp by Šimon Tóth
// https://www.linkedin.com/search/results/content/?fromMember=%5B%22ACoAAAEuqqQBcPIxsH-hh8YOxmf08R6xuhhOnfw%22%5D&heroEntityKey=urn%3Ali%3Afsd_profile%3AACoAAAEuqqQBcPIxsH-hh8YOxmf08R6xuhhOnfw&keywords=%C5%A1imon%20t%C3%B3th&position=0&searchId=046bf13e-77f2-4b34-9047-f26ffa1e6099&sid=LYb&update=urn%3Ali%3Afs_updateV2%3A(urn%3Ali%3Aactivity%3A7134601705849073664%2CBLENDED_SEARCH_FEED%2CEMPTY%2CDEFAULT%2Cfalse)
// https://compiler-explorer.com/z/6ssPPzMdK



#include <string>
#include <numeric> // why ?
#include <cstdint>
/* Problem:
Given a string that contains parentheses '(',')' intermixed
with other characters, return the longest string 
(formed by removing some characters) that contains only valid
parentheses.

If there are multiple such strings, return any.
*/

/* Solution:
We can remove one type of invalid parentheses in one pass.

Going left-to-right, we can remove excessive ')' parentheses.
Going right-to-left, we can remove excessive '(' parentheses.

If we first go right-to-left and then left-to-right, we can
avoid excessive copies.
*/

std::string longest_valid_string(std::string s) {
    auto dst = s.rbegin();
    int64_t left = 0;
    int64_t right = 0;
    // Right-to-left, remove excessive '('.
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == ')') {
            ++right;
        } else if (*it == '(') {
            // This instance is excessive, do not copy.
            if (left == right) continue;
            ++left;
        }
        // Since we are working with characters, 
        // the std::move is superfluous.
        *dst = std::move(*it);
        ++dst;
    }

    // Left-to-right, remove excessive ')'.
    auto dst_fwd = s.begin();
    int64_t to_remove = right-left;
    // We have moved the non-removed characters to the right
    // so the string now starts at dst.base().
    for (auto it = dst.base(); it != s.end(); ++it) {
        if (*it == ')' && to_remove > 0) {
            // This instance is excessive, do not copy.
            --to_remove;
            continue;
        }
        // Since we are working with characters, 
        // the std::move is superfluous.
        *dst_fwd = std::move(*it); 
        ++dst_fwd;
    }

    // Remove the now invalid tail of the string.
    s.erase(dst_fwd, s.end());
    return s;
}

#include <cassert>

bool is_valid_string(std::string_view s);

int main() {
    {
        std::string t = longest_valid_string("");
        assert(t == "");
    }
    {
        std::string t = longest_valid_string("a");
        assert(t == "a");
    }
    {
        std::string t = longest_valid_string("a()b");
        assert(t == "a()b");
    }
    {
        std::string t = longest_valid_string("a()b");
        assert(t == "a()b");
    }
    {
        std::string t = longest_valid_string(")a()b(");
        assert(t == "a()b");
    }
    {
        std::string t = longest_valid_string("(((a))");
        assert(is_valid_string(t) && t.length() == 5);
    }
    {
        std::string t = longest_valid_string("((a)))");
        assert(is_valid_string(t) && t.length() == 5);
    }
    {
        std::string t = longest_valid_string("()((a)))");
        assert(is_valid_string(t) && t.length() == 7);
    }
    {
        std::string t = longest_valid_string("(((a))()");
        assert(is_valid_string(t) && t.length() == 7);
    }
    {
        std::string t = longest_valid_string("()))(a((b)()c(()(");
        assert(is_valid_string(t) && t.length() == 11);
    }
}

bool is_valid_string(std::string_view s) {
    int64_t left = 0;
    int64_t right = 0;
    for (auto c : s) {
        if (c == '(') ++left;
        if (c == ')') ++right;
        if (right > left) return false;
    }
    return left == right;
}