
#include<iostream>

using namespace std;

#define LEN(X) sizeof(X)/sizeof(X[0])

void display(int*, int);

void selectionSort(int*, int);

void swap(int*, int*);

int main() {

	int arr[] = {-2, 45, 0, 11, -9};
	int size = LEN(arr);
	cout<<"Program to do bubble sort for array: ";
	display(arr, size);
	cout<<'\n';
	selectionSort(arr, size);
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

void selectionSort(int * a, int size) {	
	for(int i = 0; i < size - 1; i++) {
		for(int j = i + 1; j < size; j++) {
			if (*(a + i) > *(a + j)) {

				swap(a+i, a+j);
			}
		}	

	}

}
