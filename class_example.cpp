#include<iostream>

using namespace std;


class Rectangle {
	int width, height;

	public:
		Rectangle(int x, int y) : width(x), height(y) {}
		void set_values(int, int);
		int area() {return width * height;}

}

void Rectangle::set_values(int x, int y) {

	width = x;
	height = y;
}

Rectangle::Rectangle(int x, int y) {
	width = x;
	height = y;
}


