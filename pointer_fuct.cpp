#include<iostream>

#include<string>

using namespace std;

int add(int a, int b) {
	
	return a+b;

}

void print() {
	cout<<"Print c"<<endl;
}

int main() {

	int (*fun)(int, int) = add;
	cout<<fun(5,6);

	void (*func2)() = print;
	func2();
	return 0;
}
