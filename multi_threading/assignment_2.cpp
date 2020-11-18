#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class Queue {

	public:
		Queue() : versionNum(0){}
		void enqueue(int elem);
		int dequeue();
		int print(int versionNum);

	private:
		int versionNum;
		list<int> data;
		unordered_map<int, int> mm;

};

void Queue::enqueue(int elem) {
	versionNum++;
	mm[versionNum] = elem;
	data.push_back(elem);
}

int Queue::dequeue() {
	versionNum++;
	if (data.empty()) return -1;
	int temp = data.front();
	mm[versionNum] = temp;
	data.pop_front();
	return temp;
}

int Queue::print(int versionNum) {
	if (mm.find(versionNum) == mm.end()) {
		return -1;
	} else {
		return mm[versionNum];
	}
}

int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(4);
	q.dequeue();
	q.enqueue(5);
	cout<<q.print(2)<<endl;
	cout<<q.print(4)<<endl;
}
