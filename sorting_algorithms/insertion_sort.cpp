#include<iostream>

using namespace std;

#define LEN(X) sizeof(X)/sizeof(X[0])

void display(int*, int);

void insertionsort(int*, int);

void swap(int*, int*);

int main() {

	int arr[] = {9, 5, 3, 8, -1, 2, 7, -6};
	int size = LEN(arr);
	cout<<"Program to do insertion sort for array: ";
	display(arr, size);
	cout<<'\n';
	insertionsort(arr, size);
	display(arr, size);
	return 0;
}

void display(int * arr, int size) {
	for(int i = 0; i < size; i++) {
		cout<<*arr<<" ";
		arr++;
	}
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insertionsort(int * a, int size) {	
	int j;
	for(int i = 1; i < size; i++) {
		j = i - 1;
		int key = *(a + i);
		while (key < *(a + j) && j >= 0) {
			*(a + j + 1) = *(a + j);
			j--;
		}
		*(a + j + 1) = key;
	}

}
