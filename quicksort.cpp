#include<iostream>

#define LEN(X) sizeof(X)/sizeof(X[0])

using namespace std;


void display(int * , int);

void quicksort(int *, int, int);

int partition(int *, int, int);

void swap(int *, int *);

int main() {
	int arr[] = {6, 5, 12, 10, 9, 1};
	int size = LEN(arr);
	cout<<"Program to do Quick sort : ";
	display(arr, size);
	quicksort(arr, 0, size - 1);
	cout<<"\n";
	display(arr, size);
	return 0;
}

void swap(int * a, int * b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void display(int * a, int size) {
	
	for (int i = 0; i < size; i++) {
		cout<<*a<<" ";
		a++;
	}
}

int partition(int *a, int left, int right) {
	int pivot = *(a + right);
	int i = left;

	for(int j = left; j < right; j++) {
		if (*(a + j) <= pivot) {
			swap(a+i, a+j);
			i++;
		}
	}
	swap(a+i, a+right);
	return i;

}

void quicksort(int * a, int left, int right) {
	
	if (left < right) {

		int pi = partition(a, left, right);
		// sort the element on the left and on the right of pivot
		quicksort(a, left, pi - 1);
		quicksort(a, pi + 1, right);
	}

}
