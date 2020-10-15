#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class CircularBuffer {
	int cp;
	int * arr;
	int head = 0;
	int tail = 0;
	public:
		int size = 0;
		CircularBuffer() {
			cp = 5;
			arr = new int[cp];
		}

		CircularBuffer(int capacity) : cp(capacity), arr(new int[capacity]){}

		int push(int val);
		int shift();
		void resize();
		int getCapacity() {return cp;}
};

void CircularBuffer::resize() {
	int * arr2 = new int[this->getCapacity() * 2];
	int item = this->shift();
	int i = 0;
	printf("Resizing method \n");
	while (item != -1) {
		printf("%d ", item);
		arr2[i] = item;
		i++;
		item = this->shift();
	}
	this->arr = arr2;
	delete arr2;
}

int CircularBuffer::push(int val) {
	int newPos = (tail + 1) % cp;
	if (newPos == head) {
		cout << "The queue is full"<<endl;
		resize();
		push(val);
		return -1;
	}
	size++;
	tail = newPos;
	arr[newPos] = val;
       return 0;	
}

int CircularBuffer::shift() {
	if (head == tail) {
		cout <<"The queue is empty"<<endl;
		return -1;
	}
	size--;
	head = (head + 1) % cp;
	int val = arr[head];
	arr[head] = -1;
	return val;

}

void display(int *a, int size);

int main() {
	int arr[] = {4, 6, 9, 10, 3, 2, 6, 11, 15};
	display(arr, 9);
	CircularBuffer c;
	for (int i = 0; i < 9; i++) {
		c.push(arr[i]);
	}
	cout<<"Added arr inside Circular Queue : "<<c.size<<endl;

	cout<<c.shift()<<endl;
	cout<<c.shift()<<endl;
	cout<<c.shift()<<endl;
	cout<<c.shift()<<endl;
	cout<<c.shift()<<endl;
	return 0;
}

void display(int *a, int size) {
	for (int i = 0; i <size; i++) {
		printf("%d ", *a);
		++a;
	}
	cout<<"\n";
}
