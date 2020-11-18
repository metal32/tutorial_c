#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>
#include<vector>

class Foo {
	std::atomic<int> bar;
public:
	Foo() : bar(0) {}
	void doSmth() {
        bar++;
    }

    void getBar() {
    	std::cout<<"bar is "<<bar<<std::endl;
    } 
};

int main() {
	Foo f;
	std::vector<std::thread> vect;
	for (int i = 0; i < 5; ++i) {
		vect.emplace_back(&Foo::doSmth, &f);
		vect.emplace_back(&Foo::getBar, &f);
	}
	for(auto& c: vect) {
		c.join();
	}
	return 0;
}