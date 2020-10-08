#include<iostream>

using namespace std;

void duplicate(int& a, int& b);

void square(int* a);

int main() {
	
	int a = 5;
	int b = 6;

	cout<<a<<"\t"<<b<<endl;
	cout<<"After changing"<<endl;
	duplicate(a, b);
	
	cout<<a<<"\t"<<b;

	square(&a);
	cout << "Squre of a" << a;
	return 0;
}

void duplicate(int& a, int& b) {

	int temp = a;
	a = b;
	b = temp;
}

void square(int* a) {
	
	*a = *a * *a;
}
