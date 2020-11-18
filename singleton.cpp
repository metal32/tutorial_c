#include<iostream>

//Constructor has been made private to stop anyone making more than one object of it

using namespace std;

class Singleton {

	static Singleton* instance;
	int data;

	Singleton() : data(0){}

	public:

		static Singleton* getInstance() {

			if (instance == nullptr) {
				instance = new Singleton;
			}
			return instance;
		}

		int getData() {
			return data;
		}

		void setData(int data) {
      		this -> data = data;
   		}	

};

Singleton* Singleton::instance = 0;

int main() {
	Singleton* s = s->getInstance();
	cout << s->getData() << endl;
   	s->setData(100);
   	cout << s->getData() << endl;
	return 0;
}