#include<iostream>
#include<string>
#include<thread>
#include<vector>

using namespace std;

void print(int n, const string & s) {
	cout << "N is "<<n<<" "<<s<<endl;
}

int main() {

	vector<string> ss = {
	"Educative.blog",
      "Educative",
      "courses",
      "are great"
	};

	vector<thread> threads;

	for (int i = 0; i < ss.size(); i++) {
    //they will be copied into the internal storage for the new thread and supplied to the thread function
    	threads.push_back(thread(print, i, ss[i]));
  	}

  	for (auto & th: threads) {
  		th.join();
  	}

	return 0;
}