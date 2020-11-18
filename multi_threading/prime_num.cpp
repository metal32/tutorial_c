#include<iostream>
#include<mutex>
#include<thread>
#include<ctime>
#include<vector>

std::mutex m;

std::vector<unsigned int> primeVect;

void findPrimeNum(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
	for (unsigned int x = start; x <= end; x+=2) {
		for (unsigned int y = 2; y < x; y++) {
			if (x%y == 0) {
				break;
			} else if (y+1 == x){
				vect.push_back(x);
			}
		}
	}

}

void primeFactor(unsigned int start, unsigned int end) {
	for (unsigned int x = start; x <= end; x+=2) {
		for (unsigned int y = 2; y < x; y++) {
			if (x%y == 0) {
				break;
			} else if (y+1 == x){
				m.lock();
				primeVect.push_back(x);
				m.unlock();
			}
		}
	}
}

void findPrimeNumMultiThread(unsigned int start, unsigned int end, unsigned int numThreads) {
	std::vector<std::thread> threads;

	unsigned int threadSpread = end/numThreads;
	unsigned int newEnd = start + threadSpread - 1;
	for (unsigned int x = 0; x < numThreads; ++x) {
		threads.emplace_back(primeFactor, start, newEnd);
		start += threadSpread;
		newEnd += threadSpread;
	}

	for (auto &c : threads) {
		c.join();
	}

}

int main() {
	std::vector<unsigned int> vect;
	int start_time = clock();
	findPrimeNum(1, 100000, vect);
	// for (auto c: vect) {
	// 	std::cout<<c<<" ";
	// }
	std::cout<<std::endl;
	int end_time = clock();
	std::cout<<"Execution time: "<<(end_time-start_time)/double(CLOCKS_PER_SEC)<<std::endl;

	start_time = clock();
	findPrimeNumMultiThread(1, 100000, 3);
	// for (auto& c: primeVect) {
	// 	std::cout<<c<<" ";
	// }
	end_time = clock();

	std::cout<<"Execution time with threads: "<<(end_time-start_time)/double(CLOCKS_PER_SEC)<<std::endl;

	return 0;
}