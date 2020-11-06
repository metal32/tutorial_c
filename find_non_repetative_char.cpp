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

// This method is slower
int findFirstNonRepeatativeChar(string s) {
	const clock_t begin_time = clock();
	int out = INT_MAX;
	vector<int> c(256);
	int len = s.size();
	for (int i = 0; i < len; i++) {
		c[s[i]]++;
	}

	for (int i = 0; i < len; i++) {
		if (c[s[i]] == 1) {
			out = i;
			break;
		}
	}
	std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC<<endl;
	return out;

}

//Faster Method

int findFirstNonRepeatativeCharFast(string s) {
	const clock_t begin_time = clock();
	int out = INT_MAX;
	vector<pair<int,int>> c(256);
	int len = s.size();
	for (int i = 0; i < len; i++) {
		c[s[i]].first++;
		c[s[i]].second = i;
	}

	for (int i = 0; i < 256; i++) {
		if (c[i].first == 1) {
			out = c[i].second;
			break;
		}
	}
	std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC <<endl;
	return out;

}

int main() {

	string s = "GeeksForGeekssahjafrhaubuaugwojhfggahpqvgafcwsghdnmjhytegbcmgldpougbdssgavgelpPsgaFTHFSHJAKGRDARFAAUaaa'kfgay';lgafdcvaLT";
	int index = findFirstNonRepeatativeChar(s);
	index = findFirstNonRepeatativeCharFast(s);
	if (index != INT_MAX) {
		cout<<"Non repetative char is : "<<s[index];
	} else {
		cout<<"No such character is present";
	}
	
}