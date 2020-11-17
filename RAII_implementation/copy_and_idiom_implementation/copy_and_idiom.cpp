#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;

class HolderNewGen{
	
	public:

		friend void swap(HolderNewGen& first, HolderNewGen& second) // nothrow
	    {
	        // enable ADL (not necessary in our case, but good practice)
	        using std::swap;

	        // by swapping the members of two objects,
	        // the two objects are effectively swapped
	        swap(first.m_size, second.m_size);
	        swap(first.m_data, second.m_data);
	    }

	    HolderNewGen() {}

		HolderNewGen(int size) {
			m_size = size;
			m_data = new int[size];
		}

		HolderNewGen(const HolderNewGen& other) {
			m_data = new int[other.m_size];
			std::copy(other.m_data, other.m_data+other.m_size, m_data);
			m_size = other.m_size;
		}

		//Move constructor
		HolderNewGen(HolderNewGen&& other) noexcept {
			HolderNewGen();
			swap(*this, other);
		}

		//Move assignment operator
		HolderNewGen& operator=(HolderNewGen&& other) noexcept {
			swap(*this, other);
		}

		//Copy and Swap Idiom way of writing copy assignment operator
		//1) Get the copy of it and let compiler do it as it is the best platform to do it
		// If copy fails then we will never enter the assignment function and hence our *this will be safe
		//2) We need to have a swap function as created
		HolderNewGen& operator=(HolderNewGen other){
   			swap(*this, other);
    		return *this;
		}

		~HolderNewGen() {
			delete[] m_data;
		}

	private:
		int* m_data;
		size_t m_size;
};

HolderNewGen createNewGenHolder(int size)
{
 	return HolderNewGen(size);
}

int main() {
	{
		// Using Copy-and-idioms
		HolderNewGen h1(10000); // regular constructor
		HolderNewGen h2 = h1;   // copy constructor

		HolderNewGen h5(10000);  // regular constructor
		HolderNewGen h6(60000);  // regular constructor
		h5 = h6;
	}
	return 0;
}