// Practice from : https://github.com/embeddedartistry/embedded-resources/blob/master/examples/cpp/circular_buffer/circular_buffer.hpp
// Question isEmpty () not thread safe. why ? 

#include <iostream>
#include <cstdint>
#include <cstring>
#include <mutex>

template <typename TYPE, size_t SIZE>
class CircularQueue
{
private:
    TYPE m_buffer[SIZE];
    size_t m_head;
    size_t m_tail;
    const size_t m_size;
    bool m_isFull;
    std::mutex m_mutex;

public:
    CircularQueue() : m_head(0), m_tail(0), m_size(SIZE), m_isFull(false), m_mutex()
    {
        std::memset(m_buffer, 0, sizeof(m_buffer));
    }

    void push(TYPE data)
    {
        std::lock_guard lg(m_mutex);
        m_buffer[m_head] = data;

        if (m_isFull)
            m_tail = (m_tail + 1U) % m_size;
        m_head = (m_head + 1U) % m_size;

        m_isFull = (m_head == m_tail);
    }

    TYPE get() const
    {
        if (isEmpty())
        {
            return NULL;
        }
        TYPE data;
        data = m_buffer[m_head];
        m_tail = (m_tail + 1U) % m_size;

        return data;
    }

    bool isEmpty() const
    {
        return (!m_isFull && (m_head == m_tail));
    }
};

int main()
{
    CircularQueue<uint8_t, 10> circularQueue;

    for (auto i = 0; i < 11; i++)
        circularQueue.push(i);

    return 0;
}