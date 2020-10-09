#include<iostream>
#include<vector>

#define LEN(X) sizeof(X)/sizeof(X[0])
using namespace std;

void display(int a[], int size);

void heapify(int a[],  int n, int i);

void heapSort(int a[], int size);

void swap(int& a, int& b);

int main() {

	int a[] = {12, 11, 13, 5, 6, 7};
	int size = LEN(a);
	cout<<"Array is :: ";
	display(a, size);

	heapSort(a, size);

	cout<<"\n";
	display(a, size);
	return 0;
}

void display(int a[], int size) {
	for(int i = 0; i < size; i ++) {
		cout<<a[i]<<" ";
	}	
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int a[], int size, int index) {

	int smallest = index;
	int l = 2*index + 1;
	int r = 2 * index + 2;
	if (l < size && a[smallest] > a[l]) {
		smallest = l;
	}

	if (r < size && a[smallest] > a[r]) {
		smallest = r;
	}

	if (smallest != index) {
		swap(a[smallest], a[index]);

		// Heapify till the leaf node
		heapify(a, size, smallest);
	}
}

void heapSort(int a[], int size) {
	
	for (int i = size/2 -1; i >= 0; i--) {
		heapify(a, size, i);
	}

	cout<<"\nHeapify completed ::";
	display(a, size);

	for (int i = size-1; i >= 0; i--) {
		swap(a[i], a[0]);
		heapify(a, i, 0);
	}

}

