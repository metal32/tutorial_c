#include<iostream>

using namespace std;

template<class T>

T sum(T a, T b) {

	return a + b;
}

template<class T, class U>
bool are_equal(T a, U b) {
	return a == b;
}

int add(int a,int b) {

	return a+b;
}

int operation(int x, int y, int (*functocall) (int, int)) {
	
	int g;
	g = (*functocall) (x, y);
	return (g);

}

int main() {

	int a = 5, b = 7;
	double c = 5.5, d = 7.5;
	cout<<"Sum of double "<< sum<double>(c, d)<<endl; 
	cout<<"Sum of int "<< sum<int>(a, b)<<endl; 
	
	cout<<"Check whether int and double value be equal "<<are_equal<int, double>(10, 10.0)<<endl;

	bool is_equal = 10 == 10.0;
	cout<<"Check whether int and double value be equal "<<is_equal<<endl;


	int arr[] = {10, 20, 30, 50};

	for(int elem: arr) {
		cout<<elem<<endl;
	}

	cout<<operation(10, 25, add);
	return 0;
}

