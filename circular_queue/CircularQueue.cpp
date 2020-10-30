#include <iostream>
#include "CircularQueue.h"
#include <vector>
#include <cstdio>

using std::cout;
using std::endl;

namespace Queue {
	CircularQueue::CircularQueue() {
		cp = 5;
		arr = new int[cp];
		printf("Circular Queue Of size %d is initialized\n", cp-1);
	}

	CircularQueue::CircularQueue(int cp_) {
		cp = cp_;
		arr = new int[cp];
		printf("Circular Queue Of size %d is initialized\n", cp-1);
	}

	CircularQueue::~CircularQueue() {
		delete arr;
		arr = nullptr;
		// cout<<"Destructor called"<<endl;
	}

	void CircularQueue::resize() {
		cp = this->getCapacity() * 2;
		int * arr2 = new int[cp];
		int item = this->shift();
		int i = 1;
		while (item != -1) {
			arr2[i] = item;
			item = this->shift();
			i++;
		}
		delete this->arr;
		this->arr = arr2;
		head = 0;
		tail = i - 1; 
		size = i - 1;
	}

	int CircularQueue::push(int val) {
		int newPos = (tail + 1) % cp;
		if (newPos == head) {
			// cout << "The queue is full with size "<<size<<endl;
			resize();
			push(val);
			return -1;
		}
		size++;
		tail = newPos;
		arr[newPos] = val;
	    return 0;	
	}

	int CircularQueue::shift() {
		if (head == tail) {
			return -1;
		}
		size--;
		head = (head + 1) % cp;
		int val = arr[head];
		arr[head] = -1;
		return val;
	}

	int CircularQueue::getCapacity() {return cp;}

	void CircularQueue::display() {
		printf("\n");
		for (int i = 1; i <= size; i++) {
			cout<<arr[i]<<" ";
		}
		printf("\n");
	}

}