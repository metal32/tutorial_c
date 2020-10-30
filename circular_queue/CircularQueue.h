#pragma once

namespace Queue {
	class CircularQueue {
	private:
		int cp;
		// Don't forget to call destructor to clear heapmemory
		int * arr;
		int head = 0;
		int tail = 0;
		void resize();
	public:
		int size = 0;
		CircularQueue();
		CircularQueue(int capacity);
		~CircularQueue();
		int push(int val);
		int shift();
		int getCapacity(); 
		void display();
	};
}
