#include<iostream>

using namespace std;

#define LEN(X) sizeof(X)/sizeof(X[0])

void display(int*, int);

void bubbleSort(int*, int);

void swap(int*, int*);

int main() {

	int arr[] = {-2, 45, 0, 11, -9};
	int size = LEN(arr);
	cout<<"Program to do bubble sort for array: ";
	display(arr, size);
	cout<<'\n';
	bubbleSort(arr, size);
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

void bubbleSort(int * arr, int size) {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size -i-1; j++) {
			if (*(arr+j) > *(arr+j+1)) {
				swap(arr+j, arr+j+1);			
			}
		}

	}

}
