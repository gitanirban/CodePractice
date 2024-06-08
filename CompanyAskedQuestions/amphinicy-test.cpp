#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;
class WindowManager
{
private:
    list<string> m_stack;
    unordered_map<string, list<string>::iterator> m_map;

public:
    void open(const std::string windowName)
    {
        m_stack.push_front(windowName);
        m_map[windowName] = m_stack.begin();
    }

    void close(const std::string windowName)
    {
        if (m_map.count(windowName)) {
            m_stack.erase(m_map[windowName]);
            m_map.erase(windowName);
        }

    }

    std::string getTopWindow()
    {
        return m_stack.size() ? m_stack.front() : "";
    }
};

int main()
{
    // Test 1: Basic functionality
    {
        WindowManager wm;
        wm.open("Calculator");
        wm.open("Browser");
        wm.open("Player");
        wm.close("Browser");
        assert(wm.getTopWindow() == "Player");
    }

    // Test 2: Reopen a closed window
    {
        WindowManager wm;
        wm.open("Calculator");
        wm.open("Browser");
        wm.open("Player");
        wm.close("Browser");
        wm.open("Browser");
        assert(wm.getTopWindow() == "Browser");
    }

    // Test 3: Close all windows
    {
        WindowManager wm;
        wm.open("Calculator");
        wm.open("Browser");
        wm.open("Player");
        wm.close("Player");
        wm.close("Browser");
        wm.close("Calculator");
        assert(wm.getTopWindow() == ""); // No windows open
    }

    // Test 4: Close non-existent window
    {
        WindowManager wm;
        wm.open("Calculator");
        wm.open("Browser");
        wm.open("Player");
        wm.close("Editor"); // "Editor" was never opened
        assert(wm.getTopWindow() == "Player");
    }

    // Test 5: Open windows with the same name (though logically should not happen)
    {
        WindowManager wm;
        wm.open("Calculator");
        wm.open("Calculator");
        assert(wm.getTopWindow() == "Calculator");
        wm.close("Calculator");
        assert(wm.getTopWindow() == "Calculator");
    }

    // Test 6: Open and close in a sequence
    {
        WindowManager wm;
        wm.open("Editor");
        wm.open("Browser");
        wm.open("Terminal");
        wm.close("Browser");
        wm.open("Player");
        assert(wm.getTopWindow() == "Player");
    }

    cout << "All tests passed!" << endl;

    return 0l;
}