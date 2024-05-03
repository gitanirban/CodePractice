#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
    uint8_t m_front, m_rear, m_size, m_capacity;
    int8_t* m_array;
};

Queue* createQueue(uint8_t capacity) {
    Queue* pQueue = new Queue();
    pQueue->m_capacity = capacity;
    pQueue->m_front = pQueue->m_size = 0U;
    pQueue->m_rear = capacity - 1U;
    pQueue->m_array = new int8_t[capacity];
    return pQueue;
}

int isFull(Queue* pQueue) {
    return (pQueue->m_size == pQueue->m_capacity);
}
int isEmpty(Queue* pQueue) {
    return (pQueue->m_size == 0U);
}

void enqueue(Queue* pQueue, int8_t data) {
    if (isFull(pQueue))
        return;
    pQueue->m_rear = (pQueue->m_rear + 1U) % pQueue->m_capacity;
    pQueue->m_array[pQueue->m_rear] = data;
    pQueue->m_size += 1U;
    printf("enqueued to queue %d \n", data);// << data << " enqueued to queue\n";

}

int dequeue(Queue* pQueue) {
    if (isEmpty(pQueue))
        return INT_MIN;
    int8_t data = pQueue->m_array[pQueue->m_front];
    pQueue->m_front = (pQueue->m_front + 1U) % pQueue->m_capacity;
    pQueue->m_size -= 1U;
    return data;

}

int front(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->m_array[queue->m_front];
}

// Function to get rear of queue
int rear(Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->m_array[queue->m_rear];
}




int main() {
    std::cout << "Hello, World!" << std::endl;

    Queue* pQ = createQueue(5);

    enqueue(pQ, 10);
    cout << "Front item is "
        << front(pQ) << endl;
    cout << "Rear item is "
        << rear(pQ) << endl;
    enqueue(pQ, 20);
    cout << "Front item is "
        << front(pQ) << endl;
    cout << "Rear item is "
        << rear(pQ) << endl;
    enqueue(pQ, 30);
    cout << "Front item is "
        << front(pQ) << endl;
    cout << "Rear item is "
        << rear(pQ) << endl;
    enqueue(pQ, 40);
    cout << "Front item is "
        << front(pQ) << endl;
    cout << "Rear item is "
        << rear(pQ) << endl;

    return 0;
}
