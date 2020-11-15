#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

  return 0;
}