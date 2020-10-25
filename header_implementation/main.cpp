#include<iostream>
#include "Cube.h"

int main() {

	uiuc::Cube c(3.48);

  	c.setLength(5);
  	double volume = c.getVolume();
  	std::cout << "Volume: " << volume << std::endl;
	return 0;
}
