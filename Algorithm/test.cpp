#include <iostream>
#include <string>
#include "pqueue.h"
using namespace std;

int main(int argc, char* argv[])
{
    PriorityQueue<int> queue;
    queue.insert(47);
    queue.insert(42);
    queue.insert(49);
    queue.insert(5);
	queue.insert(15);
	queue.insert(25);
	queue.insert(1);
	bool real=true;
    	cout << "Empty? " << queue.isEmpty() << endl;
   	cout << "pop: " << queue.pop() << endl;
  	cout << "top: " << queue.top() << endl;
   	cout << "top: " << queue.top() << endl;
    return 0;
}