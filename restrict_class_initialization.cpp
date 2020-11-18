#include<iostream>

using namespace std;

class A{
	
	private:
		~A(){}
		friend void destructA(A*);
};

void destructA(A* ptr) {
	delete ptr;
}

int main(){
	A* a = new A();
	destructA(a);
	return 0;
}