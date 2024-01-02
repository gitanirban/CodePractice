#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Least Recently Used Cache.  This dont have get method. https://www.geeksforgeeks.org/lru-cache-implementation/

// Better Implementation : https://www.youtube.com/watch?v=iEmActx7dYc as per leet code problem.

// Need to fix the test cases as per leet code, it has time overhead. Not sure why.

// Its suppossed to have O(1) time complexity for get() and put()

class LRUCache {
public:
    LRUCache(int size) : m_size(size) {}

    int get(int const key);
    void put(int key, int value);
    void put(int key);

    void display();
    void test(int arr[]);


private:
    list<int> m_dq_keys;
    unordered_map<int /*key*/, pair<int /*value */, list<int>::iterator>> m_map;
    const int m_size;
};

int LRUCache::get(int const key)
{
    if (m_map.find(key) != m_map.end())
    {
        // If present then put it in front.
        m_dq_keys.erase(m_map[key].second);
        m_dq_keys.push_front(key);
        m_map[key].second = m_dq_keys.begin();
        return m_map[key].first;
    }
    return -1;
}

void LRUCache::put(int key, int value) {
    if (m_map.find(key) != m_map.end()) {
        // If present then put it in front.
        m_dq_keys.erase(m_map[key].second);
        m_dq_keys.push_front(key);

        m_map[key] = { value, m_dq_keys.begin() };
    }
    else {
        if (m_dq_keys.size() == m_size) {
            m_map.erase(m_dq_keys.back());
            m_dq_keys.pop_back();
        }
        m_dq_keys.push_front(key);
        m_map[key] = { value, m_dq_keys.begin() };
    }
}




void LRUCache::display() {
    for (auto i = m_dq_keys.begin(); i != m_dq_keys.end(); i++)
        cout << *(i) << " ";

    cout << endl;
}

void LRUCache::test(int arr[]) {
    for (auto i = m_dq_keys.begin(); i != m_dq_keys.end(); i++)
    {
        if (*i != *arr++)
        {
            cout << "test fail\t" << *i << "\t" << *arr << endl;
        }
    }

    if (m_dq_keys.size() != m_size)
        cout << "test fail : Size mismatch " << endl;

}


int main() {
    std::cout << "Hello, LRU!" << std::endl;
    LRUCache lruCacheObj(2);

    lruCacheObj.put(1, 1);
    lruCacheObj.put(2, 2);
    cout << lruCacheObj.get(1) << endl;
    lruCacheObj.put(3, 3);
    cout << lruCacheObj.get(2) << endl;
    lruCacheObj.put(4, 4);
    cout << lruCacheObj.get(1) << endl;
    cout << lruCacheObj.get(3) << endl;
    cout << lruCacheObj.get(4) << endl;


    return 0;
}
