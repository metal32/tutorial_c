#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <cstdint>
#include <ctime>
using namespace std;

#define total_char 256

void reverseString(string s) {
	if (s.size() == 0) return;

	reverseString(s.substr(1));
	cout<<s[0];
}

int main() {

	string a = "Geeks for Geeks";
	reverseString(a);

	return 0;
}