#include <iostream>
#include "CircularQueue.h"
#include <vector>
#include <cstdio>

using std::cout;
using std::endl;

namespace Queue {
	template<typename T>
	CircularQueue<T>::CircularQueue() {
		cp = 5;
		arr = new T[cp];
		printf("Circular Queue Of size %d is initialized\n", cp-1);
	}

	template<typename T>
	CircularQueue<T>::CircularQueue(int cp_) {
		cp = cp_;
		arr = new T[cp];
		printf("Circular Queue Of size %d is initialized\n", cp-1);
	}

	template<typename T>
	CircularQueue<T>::~CircularQueue() {
		delete arr;
		arr = nullptr;
		// cout<<"Destructor called"<<endl;
	}

	template<typename T>
	void CircularQueue<T>::resize() {
		cp = this->getCapacity() * 2;
		T * arr2 = new T[cp];
		T item = this->shift();
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

	template<typename T>
	int CircularQueue<T>::push(T val) {
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

	template<typename T>
	T CircularQueue<T>::shift() {
		if (head == tail) {
			cout <<"The queue is empty"<<endl;
			return -1;
		}
		size--;
		head = (head + 1) % cp;
		T val = arr[head];
		arr[head] = NULL;
		return val;
	}

	template<typename T>
	int CircularQueue<T>::getCapacity() {return cp;}

	// void CircularQueue::display() {
	// 	printf("\n");
	// 	for (int i = 1; i <= size; i++) {
	// 		cout<<arr[i]<<" ";
	// 	}
	// 	printf("\n");
	// }

}