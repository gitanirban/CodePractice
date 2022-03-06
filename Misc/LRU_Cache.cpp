#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Least Recently Used Cache
// https://www.geeksforgeeks.org/lru-cache-implementation/
class LRUCache {
public:
    LRUCache(int size) : m_size(size) {}

    void insert(int data);

    void display();

private:
    list<int> m_dq;
    unordered_map<int, list<int>::iterator> m_map;
    const int m_size;
};

void LRUCache::insert(int data) {
    // check already there
    // not present
    if (m_map.find(data) == m_map.end()) {
        // already full
        if (m_dq.size() == m_size) {
            int least_used_data = m_dq.back();
            m_dq.pop_back();
            m_map.erase(least_used_data);
        }
    }
        // present
    else {
        m_dq.erase(m_map[data]);
    }
    // update
    m_dq.push_front(data);
    m_map[data] = m_dq.begin();
}

void LRUCache::display() {
    for (auto i = m_dq.begin(); i != m_dq.end(); i++)
        cout << *(i) << " ";

    cout << endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    LRUCache lruCacheObj(4);
    lruCacheObj.insert(1);
    lruCacheObj.insert(2);
    lruCacheObj.insert(3);
    lruCacheObj.insert(1);
    lruCacheObj.insert(4);
    lruCacheObj.insert(5);
    lruCacheObj.display();



    return 0;
}
