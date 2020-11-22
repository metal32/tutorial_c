
#include<iostream>

using namespace std;

#define LEN(X) sizeof(X)/sizeof(X[0])

void display(int*, int);

void countingsort(int*, int);

void swap(int*, int*);

int main() {

	int arr[] = {5, 4, 6, 11, 2};
	int size = LEN(arr);
	cout<<"Program to do counting sort for array: ";
	display(arr, size);
	cout<<'\n';
	countingsort(arr, size);
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

void countingsort(int *a, int size) {
	
	int max = *a;
	for (int i = 1; i < size; i++) {
		if (max < *(a + i)) {
			max = *(a + i);
		}
	}	


	int count[255 + 1];
	int output[size + 1];
	
	for (int i = 0; i <= max; i++) {	
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		count[*(a + i)]++;
	}

	for (int i = 0; i < max; i++) {
		count[i+1] += count[i];
		
	}
	
	for (int i = size -1; i >= 0; i--) {
		
		output[count[*(a+i)] - 1] = *(a + i);
		count[*(a + i)]--;
	}

	for (int i = 0; i < size; i++) {

		*(a + i) = output[i];
	}
}
