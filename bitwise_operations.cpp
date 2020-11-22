#include<iostream>

using namespace std;

void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

bool findPowerOf2(int x) {
	return !((x-1) & x);
}

int main() {

	int a = 5;
	int b = 6;
	swap(a, b);
	cout<<"A is "<<a<<" B is "<<b<<endl;

	cout<<"12 is power of "<<findPowerOf2(12)<<endl;
	cout<<"16 is power of "<<findPowerOf2(16)<<endl;
	return 0;
}