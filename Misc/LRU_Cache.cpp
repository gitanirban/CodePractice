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
    void test(int arr[]);


private:
    list<int> m_dq;
    unordered_map<int, list<int>::iterator> m_map;
    const int m_size;
};

void LRUCache::insert(int data) {
    // item not present and full so delete the last used item
    if (m_map.find(data) == m_map.end())
    {
        if(m_dq.size() == m_size)
        {
            int least_used_data = m_dq.back();
            m_dq.pop_back();
            m_map.erase(least_used_data);
        }
    }
    
    else // item already present, then remove the item.
    {
        m_dq.erase(m_map[data]);
       // m_map.erase(data);
    }

    // add the new data in the front of deque
    m_dq.push_front(data);
    m_map[data] = m_dq.begin();
}

void LRUCache::display() {
    for (auto i = m_dq.begin(); i != m_dq.end(); i++)
        cout << *(i) << " ";

    cout << endl;
}

void LRUCache::test(int arr[]) {
    for (auto i = m_dq.begin(); i != m_dq.end(); i++)
    {
        if (*i != *arr++)
        {
            cout << "test fail\t" << *i << "\t" << *arr << endl;
        }
    }

    if (m_dq.size() != m_size)
        cout << "test fail : Size mismatch " << endl;

}


int main() {
    std::cout << "Hello, LRU!" << std::endl;
    LRUCache lruCacheObj(3);
    lruCacheObj.insert(1);
    lruCacheObj.insert(2);
    lruCacheObj.insert(3);

    int arr[] = { 3, 2, 1 };
    lruCacheObj.test(arr);

    lruCacheObj.insert(1);
    int arr2[] = { 1, 3, 2 };
    lruCacheObj.test(arr2);


    lruCacheObj.insert(4);
    int arr3[] = { 4, 1, 3 };
    lruCacheObj.test(arr3);

    lruCacheObj.insert(5);
    int arr4[] = { 5, 4, 1 };
    lruCacheObj.test(arr4);

    lruCacheObj.display();



    return 0;
}
