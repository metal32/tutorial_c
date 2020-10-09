#include<iostream>
#include<vector>


using namespace std;


void swap(int *, int *);

void insertHeap(vector<int> &a, int elem);

int deleteHeap(vector<int> &a);

void printHeap(vector<int> &a);

int main() {
	vector<int> ht;
	vector<int> heapSort;
	insertHeap(ht, 25);
	insertHeap(ht, 20);
	insertHeap(ht, 21);
	insertHeap(ht, 2);
	insertHeap(ht, 5);

	insertHeap(ht, 9);
	insertHeap(ht, 34);

	insertHeap(ht, 6);
	printHeap(ht);
	
	cout<<"\n Removed the max elem";
	int elem = deleteHeap(ht);
	heapSort.push_back(elem);
	printHeap(ht);
	cout<<"\n Removed the max elem";
	elem = deleteHeap(ht);
	heapSort.push_back(elem);
	printHeap(ht);

	cout<<"\n Removed the max elem";
	elem = deleteHeap(ht);
	heapSort.push_back(elem);
	printHeap(ht);
	cout<<"\n Removed the max elem";
	elem = deleteHeap(ht);
	heapSort.push_back(elem);
	printHeap(ht);
	cout<<"\n Removed the max elem";
	elem = deleteHeap(ht);
	heapSort.push_back(elem);
	printHeap(ht);
	printHeap(heapSort);
	return 0;
}

void swap(int *a, int *b) {
	
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printHeap(vector<int> &ht) {
	cout<<"\n";
	for(int it : ht) {
		cout<<" "<<it;
	}

}

void insertHeap(vector<int> &ht, int elem) {
	int size = ht.size();
	if (size == 0) {
		ht.push_back(elem);
	} else {
		ht.push_back(elem);
		// treat size as index
		while(size != 0 && ht[size] > ht[(size - 1)/2]) {
			swap(&ht[size], &ht[(size -1)/2]);
			size = (size - 1)/2;
		}
	}
}

int deleteHeap(vector<int> &ht) {
	int size = ht.size();
	if (size == 0) {
		cout << "\nHeap is empty ";
		return INT8_MAX;
	}

	if (size == 1){
		int elem = ht[0];
		ht.pop_back();
		return elem;
	}

	int root = ht[0];
	ht[0] = ht[size-1];
	ht.pop_back();
	size--;
	int i = 0;

	while (i < size - 1) {
		int index = 2*i + 1;
		if (2*i + 2 < size && ht[2*i + 1] < ht[2*i + 2]) {
			index = 2*i + 2;
		}
		if (ht[index] > ht[i]) {
			swap(&ht[i], &ht[index]);
		} else {
			break;
		}
		i = index;
	}
	return root;
}
