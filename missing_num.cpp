#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
// Array is suppose to start from 1 to N where size of an array is N-4
void findMissingAndDuplicateNumber(int arr[], int size) {

	cout<<"Duplicate element is : "; 
	for(int i = 0; i < size; ++i) {
		if (arr[abs(arr[i]) - 1] > 0) {
			arr[abs(arr[i]) - 1] *= -1;
		} else {
			cout<<abs(arr[i])<<" ";
		}
	}

	cout<<"\nMissing element are : ";
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			cout<<i+1<<" ";
		}
	}

}

int main() {

	int arr[] = {3, 6, 3, 4, 1, 1};

	findMissingAndDuplicateNumber(arr, 6);

}