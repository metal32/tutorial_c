#include <iostream>
using namespace std;
class Base {
   public:
      void greet() {
         cout << "Hello from Base" << endl;;
      }
};
class Derived : protected Base {
   public:
      void greet(string s) {
         cout << "Hello from " << s << endl;
         // Instead of recursing, the greet() method
         // of the base class is called.
         Base::greet();
      }
      using Base::greet;
};
int main() {
   Derived D;
   D.greet();
   D.greet("Derived");
   return 0;
}