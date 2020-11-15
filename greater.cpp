
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


struct Node {
	float start_time;
	float end_time;
	float absolute_duration;
	string id;
	Node* parent;
	vector<Node*> children;
};

float get_start_time(string id) {
	// auto it = mm.find(id);
	// if (it != mm.end()) {

	// 	float parent_duration = it -> second -> parent -> absolute_duration;

	// 	return it -> second ->  start_time * parent_duration;

	// }
	// return -1;

	vector<int> arr = split(id, ".");
	string first = arr[0];
	vector<int> temp =component[0];
	for (int i = 0; i < arr.size() - 1; ++i) {
		int index = search(temp,first);
		temp = temp[index];
		first = first + arr[i+1];
	}
}



int main() {
	

	return 0;
}

