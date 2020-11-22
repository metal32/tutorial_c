#include<iostream>

#define LEN(X) sizeof(X)/sizeof(X[0])

using namespace std;


void display(int * , int);

void mergesort(int *, int, int);

void merge(int *, int, int, int);

int main() {
	int arr[] = {6, 5, 12, 10, 9, 1};
	int size = LEN(arr);
	cout<<"Program to do merge sort : ";
	display(arr, size);
	mergesort(arr, 0, size - 1);
	cout<<"\n";
	display(arr, size);
	return 0;
}


void display(int * a, int size) {
	
	for (int i = 0; i < size; i++) {
		cout<<*a<<" ";
		a++;
	}
}

void merge(int * a, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], M[n2];
	// left array ,right array
	//
	for (int i = 0; i < n1; i++) {
		L[i] = *(a + l + i);
	}	

	for (int j = 0; j < n2; j++) {
		M[j] = *(a + j + m + 1);
	}

	int i, j, k;
	i = 0, j = 0;
	k = l;

	while(i < n1 && j < n2){
		if (L[i] <= M[j]) {
			*(a + k) = L[i];
			i++;
		} else {
			*(a + k) = M[j];
			j++;
		}		
		k++;
	}

	while (i < n1) {
		*(a + k) = L[i];
		i++;
		k++;
	}

	while( j < n2) {
		*(a + k) = M[j];
		j++;
		k++;
	}
}

void mergesort(int *a, int left, int right) {
	if (left < right) {
		int mid = left + (right - left)/2;
		mergesort(a, left, mid);
		mergesort(a, mid+1, right);
		merge(a, left, mid, right);
	}
	
}
