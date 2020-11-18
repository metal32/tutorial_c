#include<iostream>

using std::cout;

template<typename T>
class SmartPointer{

	private:
		T* ptr;

	public:
		SmartPointer(T* p = NULL) : ptr(p){}
		SmartPointer() : ptr(NULL) {}

		~SmartPointer() {delete (ptr);}

		T& operator*() {
			return *ptr;
		} 	

		T* operator->() {
			return ptr;
		}
};

int main() 
{ 
    SmartPointer<int> ptr(new int);
    *ptr = 20; 
    cout << *ptr; 
    return 0; 
} 