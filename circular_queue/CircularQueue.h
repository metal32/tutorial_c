#pragma once

namespace Queue {
	template<typename T>
	class CircularQueue {
	private:
		int cp;
		// Don't forget to call destructor to clear heapmemory
		T* arr;
		int head = 0;
		int tail = 0;
		void resize();
	public:
		int size = 0;
		CircularQueue();
		CircularQueue(int capacity);
		~CircularQueue();
		int push(T val);
		T shift();
		int getCapacity(); 
		void display();
	};
}