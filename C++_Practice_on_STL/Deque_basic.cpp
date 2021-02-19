// deque::front
#include <iostream>
#include <deque>

int main()
{
std::deque<int> mydeque(4);

mydeque.push_back(10);
mydeque.push_back(20);
mydeque.push_back(30);
mydeque.push_back(40);




std::cout << "mydeque.front() is now " << mydeque.front() << '\n';

std::cout << "mydeque.back() is now " << mydeque.back() << '\n';

return 0;
}