#include<iostream>
#include<string>
#include<thread>
#include<vector>
#include<mutex>
#include<queue>
#include<condition_variable>

using namespace std;

mutex m;
condition_variable cv;
int start = 0;
int count, threadCount, numOfTime;
vector<bool> ready(10, false);

queue<char> qu;

void print(int id) {
	for (int i = 0; i < numOfTime; ++i) {
		unique_lock<mutex> lck(m);
  	while (!ready[id - 1]) cv.wait(lck);
  	// ...
  	string newString = "";
  	for (int i = 0; i < count; ++i) {
  		newString += qu.front();
  		qu.push(qu.front());
		qu.pop();
  	}
	// cout<<this_thread::get_id()<<endl;
	cout<<"Thread"<<id<<":"<<newString<<endl;
	start += count;
	ready[id-1] = false;
	if (id < threadCount) {
		ready[id] = true;
	} else {
		ready[0] = true;
	}
	cv.notify_one();

	}
}

void simplePrint(int id) {
	//Any thread can get mutex and then lock out for other resources.
	lock_guard<mutex> lck1(m);
	string newString = "";
	for (int i = 0; i < count; ++i) {
  		newString += qu.front();
  		qu.push(qu.front());
		qu.pop();
  	}
	cout<<"Thread"<<id<<":"<<newString<<endl;
	start += count;
}

int main() {
	string s;
	cin>>s;
	cin>>count>>threadCount>>numOfTime;

	for (auto &c: s) {
		qu.push(c);
	}

	// cout<<s<<endl;
	// cout<<count<<" "<<threadCount<<" "<<numOfTime;

	vector<thread> threads;
	for (int i = 0; i < threadCount; ++i) {
		threads.push_back(thread(print, i+1));
	}
	ready[0] = true;
	cv.notify_one();

	for (auto & th: threads) {
  		th.join();
  	}

	return 0;
}