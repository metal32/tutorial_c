#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool comparotar(pair<int, int>& t1, pair<int, int>& t2) {
	return t1.first < t2.first;
}

int findMinimumRoomRequired(vector<pair<int, int>>& duration) {
	int len = duration.size();
	int maxCapacity = 0;
	int emptyRoom = 0;
	for (int i = 1; i < len; ++i) {
		if (!emptyRoom && duration[i].start > duration[i-1].second) {
			maxCapacity++;
			emptyRoom++;
		} else {
			emptyRoom--;
		}
	}
}

int main() {
	vector<pair<int,int>> conferenceRooms = {{7,10}, {0, 11}, {5, 12}, {11, 20}, {15, 30}};

	sort(conferenceRooms.begin(), conferenceRooms.end(), comparotar);



}