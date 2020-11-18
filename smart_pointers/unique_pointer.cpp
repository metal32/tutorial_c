#include<iostream>
#include<memory>

using namespace std;

class Rectangle {
	int width, height;
	public:
		Rectangle(int x, int y): width(x), height(y) {} 
		int area() {
			return width * height;
		}
};

int main() {
	unique_ptr<Rectangle> p1(new Rectangle(5, 10));

	unique_ptr<Rectangle> p2;

	p2 = move(p1);
	cout<<p2->area()<<endl;
	return 0;
}