
#include <iostream>

#include "binary_tree.h"

int main() {

	BST<int> a;

	try {
		a.insert(10);
		a.insert(15);
		a.insert(2);
		a.insert(5);
	} catch (std::runtime_error) {
		std::cout<<"Exception caught"<<std::endl;
	}

	std::cout<<a.find(10)<<std::endl;

	a.preOrder(); 

	

	return 0;
}