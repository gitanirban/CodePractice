#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Least Recently Used Cache.  This dont have get method. https://www.geeksforgeeks.org/lru-cache-implementation/

// Better Implementation : https://www.youtube.com/watch?v=iEmActx7dYc as per leet code problem.

// Need to fix the test cases as per leet code, it has time overhead. Not sure why 
// https://leetcode.com/problems/lru-cache/ 

// Its suppossed to have O(1) time complexity for get() and put()

// this solution fixes the problem

class LRUCache
{
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int size;
    LRUCache(int capacity)
    {
        size = capacity;
    }
    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }
    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == size)
        {
            auto d_key = l.back().first;
            l.pop_back();
            m.erase(d_key);
        }
        l.push_front({ key,value });
        m[key] = l.begin();
    }
};

int main() {
    std::cout << "Hello, LRU!" << std::endl;
    LRUCache lruCacheObj(1);

    cout << lruCacheObj.get(6) << endl;
    cout << lruCacheObj.get(8) << endl;
    lruCacheObj.put(12, 1);
    cout << lruCacheObj.get(2) << endl;
    lruCacheObj.put(15, 11);
    lruCacheObj.put(5, 2);
    lruCacheObj.put(1, 15);
    lruCacheObj.put(4, 2);
    cout << lruCacheObj.get(5) << endl;
    lruCacheObj.put(15, 15);

    return 0;
}
