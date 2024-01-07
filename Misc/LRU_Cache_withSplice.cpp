// Asked in Hexagon Leica interview

#include <bits/stdc++.h>

using namespace std;
class LRUCache
{
private:
    std::list<string> m_dq_key;
    std::unordered_map <string /* key*/, pair<string /* value */, list<string>::iterator /* pos */>> m_map;
    size_t m_size;

public:
    LRUCache(size_t size) : m_size(size) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    string get(const string& key) {
        if (m_map.find(key) != m_map.end()) {
            //void splice( const_iterator pos, list& other, const_iterator it );
            m_dq_key.splice(m_dq_key.begin(), m_dq_key, m_map[key].second);
            m_map[key].second = m_dq_key.begin();
            return m_map[key].first;
        }
        return {};
    }

    void put(const string& key, const string& value) {
        if (m_map.find(key) != m_map.end()) {
            // same key already exit, but replace the new value, may be value is new
            m_dq_key.splice(m_dq_key.begin(), m_dq_key, m_map[key].second);
            m_map[key] = { value, m_dq_key.begin() };
        }
        else {// new key
            // if there is no room, make one.
            if (m_map.size() == m_size) {
                m_map.erase(m_dq_key.back());
                m_dq_key.pop_back();
            }
            // now put the new key value
            m_dq_key.push_front(key);
            m_map[key] = { value, m_dq_key.begin() };
        }
    }
};

void test()
{
    LRUCache cache{ 3 };
    const string s[] = { "alpha", "beta" };

    auto put = [&](const std::string& key, const std::string& value)
        {
            std::cout << "put: " << key << " <- " << value << std::endl;

            cache.put(key, value);
        };

    auto get = [&](const std::string& key)
        {

            auto value = cache.get(key);
            std::cout << "get: " << key << " -> " << value << std::endl;
            return value;
        };

    put("A", s[0]);
    put("B", "beta");
    put("C", "gamma");
    put("D", "delta");

    get("A"); // Expected output: "A -> "
    get("B"); // Expected output: "B -> beta"
    get("C"); // Expected output: "C -> gamma"
    get("D"); // Expected output: "D -> delta"

}
