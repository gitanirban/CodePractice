// sorted queue

#include <iostream>
#include <vector>

class SortedQueue {
private:
    std::vector<int> data;
public:
    void enqueueSorted(int value) {
        // Find the position to insert the new element
        int pos = 0;
        while (pos < data.size() && data[pos] < value) {
            ++pos;
        }
        
        // Insert the new element at the found position
        data.insert(data.begin() + pos, value);
    }
    
    void print() {
        for (int val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    SortedQueue sq;
    
    sq.enqueueSorted(3);
    sq.enqueueSorted(1);
    sq.enqueueSorted(5);
    sq.enqueueSorted(2);
    sq.enqueueSorted(4);
    
    sq.print();  // Output: 1 2 3 4 5 
    
    return 0;
}
