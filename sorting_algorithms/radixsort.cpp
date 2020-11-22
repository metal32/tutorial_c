

#include<iostream>

using namespace std;

#define LEN(X) sizeof(X)/sizeof(X[0])

void display(int*, int);

void countingsort(int*, int, int);

int getMax(int*, int);

void radixsort(int*, int);

int main() {

	int arr[] = {125, 303, 606, 123, 234, 567, 789, 900, 204, 106, 11, 727};
	int size = LEN(arr);
	cout<<"Program to do counting sort for array: ";
	display(arr, size);
	cout<<'\n';
	radixsort(arr, size);
	display(arr, size);
	return 0;
}

void display(int * arr, int size) {
	for(int i = 0; i < size; i++) {
		cout<<*arr<<" ";
		arr++;
	}
}

int getMax(int* a, int size) {
	int max = *a;
	for(int i = 1; i < size; i++) {
		if (max < *(a + i)) max = *(a + i);
	}
	return max;
}

void countingsort(int *a, int size, int place) {
	int max = 10;	
	int count[10];
	int output[size + 1];
	
	for (int i = 0; i < max; i++) {	
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		count[(*(a + i) / place) % 10]++;
	}
	for (int i = 1; i < max; i++) {
		count[i] += count[i - 1];
		
	}
	
	for (int i = size -1; i >= 0; i--) {
		
		output[count[(*(a+i)/place) % 10] - 1] = *(a + i);
		count[(*(a + i)/place) % 10]--;
	}

	//display(output, size);

	for (int i = 0; i < size; i++) {

		*(a + i) = output[i];
	}
}


void radixsort(int *a, int size) {
	
	int max = getMax(a, size);
	for (int i = 1; max/i > 0; i*=10) {
		countingsort(a, size, i);
	}

}
