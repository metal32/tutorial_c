#include <iostream>
using namespace std;

class MyClass {
    int x;
  public:
    MyClass(int val) : x(val) {}
    const int& get() const {return x;}
};

void print (const MyClass* arg) {
  cout << arg->get() << '\n';
}

int main() {
  MyClass foo (10);
  MyClass * p = &foo;
  print(p);

  return 0;
}
