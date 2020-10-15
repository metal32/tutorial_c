#include <iostream>
#include <vector>
#include <cstring>

#define MAX 100
using namespace std;

class Deque {

	public:
		int arr[MAX];
		int front;
		int rear;
		int size;

		Deque(int size) {
			front = -1;
			rear = -1;
			this->size = size;
		}

		void insert_front(int elem);
		void insert_back(int elem);
		int pop_back();
		int pop_front();
		bool isfull();
		bool isEmpty();
};

bool Deque::isfull() {
	if ((front == 0 && rear == size -1) || (front == rear + 1)) {
		return true;
	} else {
		return false;
	}
}

bool Deque::isEmpty() {
	
	return front == -1;

}

void Deque::insert_front(int elem) {

	if(isfull()){
		cout << "Deque is full\n";
		return;
	}
	if (front == -1) {
		front++;
		rear++;
	} else if (front == 0){
		front = size - 1;	
	} else {
		front--;
	}
	arr[front] = elem;

}

void Deque::insert_back(int elem) {
	
	if (isfull()) {
		cout << "Deque is full\n";
	}

	if (rear == -1) {
		front++;
		rear++;
	} else if (rear == size - 1) {
		rear = 0;
	} else {
		rear++;
	}
	arr[rear] = elem;

}


int Deque::pop_back() {
	
	if (isEmpty()) {
		cout<<"Deque is empty\n";
		return -1;
	}
	int item = arr[rear];
	arr[rear] = -1;
	if (front == rear) {
		front--;
		rear--;
	} else if (rear == 0) {
		rear = size - 1;
	} else {
		rear--;
	}
	return item;

}

int Deque::pop_front() {

	if (isEmpty()) {
		cout<<"Deque is empty\n";
		return -1;
	}
	int item = arr[front];
	arr[front] = -1;
	if (front == rear) {
		front--;
		rear--;
	} else if (front == size - 1) {
		front = 0;
	} else {
		front++;
	}
	return item;
}



int main () {

	Deque dq(5); 
    cout << "Insert element at rear end  : 5 \n"; 
    dq.insert_back(5); 
  
    cout << "insert element at rear end : 10 \n"; 
    dq.insert_back(10); 
  
    cout << "get rear element " << " "
         << dq.pop_back() << endl; 
  
    cout << "After delete rear element new rear"
         << " become " << dq.pop_back() << endl; 
  
    cout << "inserting element at front end \n"; 
    dq.insert_front(15); 
  
    cout << "get front element " << " "
         << dq.pop_front() << endl; 
  
    cout << "After delete front element new "
       << "front become " << dq.pop_front() << endl; 
	return 0;
}
