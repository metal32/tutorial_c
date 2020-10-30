#include<iostream>
#include "CircularQueue.h"
#include "CircularQueue.cpp"

using std::cout;
using std::endl;
using Queue::CircularQueue;

void display(int *a, int size);	

int main() {
	CircularQueue<int> c(5);
	int arr[] = {4, 6, 9, 10, 3, 2, 6, 11, 15};
	cout << "Adding this array into circular queue ";
	display(arr, 9);
	for (int i = 0; i < 9; i++) {
		c.push(arr[i]);
	}

	int item = c.shift();
	while(item != -1) {
		cout<<"Pop Called with output : "<<item<<endl;
		item = c.shift();
	}
	return 0;
}

void display(int *a, int size) {
	for (int i = 0; i <size; i++) {
		printf("%d ", *a);
		++a;
	}
	cout<<"\n";
}