#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

bool compareInterval(char* d, char* e) {

	return strcmp(d, e);
}

int main() {

	char * s[] = {"cat", "dog", "easfg", "saere"};

	int size = sizeof(s)/sizeof(s[0]);
	sort(s, s+size, compareInterval);
	
	for(int i = 0; i < size; i++) {
		cout<<s[i]<<endl;
	}	
	return 0;
}
