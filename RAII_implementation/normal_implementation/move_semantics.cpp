// Run this code in c++11 or later versions only
//Using Move semantic and Resource Acquisition Is Initialization (RAII) Technique
// Whenever we create any thing in heap memory or use pointer
// It is best to create a copy constructor, assignment constructor and Destructor (Rule of three)

#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;

class Holder{
	
	public:

		Holder(int size) {
			m_size = size;
			m_data = new int[size];
		}

		Holder(const Holder& other) {
			cout<<"Copy Constructor of Holder class called::"<<endl;
			m_data = new int[other.m_size];
			std::copy(other.m_data, other.m_data+other.m_size, m_data);
			m_size = other.m_size;
		}

		//Move constructor
		Holder(Holder&& other) noexcept {
			cout<<"Move Constructor of Holder class called::"<<endl;
			m_data = other.m_data;
			m_size = other.m_size;
			// It's important to set the rvalue reference data to some valid state (2)
			// to prevent it from being accidentally deleted when the temporary object dies
			other.m_data = nullptr;
  			other.m_size = 0;
		}

		//Move assignment operator
		Holder& operator=(Holder&& other) noexcept {
			cout<<"Move Asssignment of Holder class called::"<<endl;
			if (this == &other) return *this;
			delete[] m_data;
			m_data = other.m_data;
			m_size = other.m_size;
			//It is important to set this, without setting it to null we attempt to delete the memory that is already deleted
			other.m_data = nullptr;
			other.m_size = 0;
		}

		// Normal way of writing copy assignment operator
		Holder& operator=(const Holder& other) {
			cout<<"Copy Assignment of Holder class called::"<<endl;
			if (this == &other) return *this;
			delete[] m_data;
			m_data = new int[other.m_size];
			std::copy(other.m_data, other.m_data+other.m_size, m_data);
			m_size = other.m_size;
			return *this;
		}

		//Copy and Swap Idiom way of writing copy assignment operator
		//1) Get the copy of it and let compiler do it as it is the best platform to do it
		// If copy fails then we will never enter the assignment function and hence our *this will be safe
		//2) We need to have a swap function as created
		// Holder& operator=(Holder other){
  //  			swap(*this, other);
  //   		return *this;
		// }

		~Holder() {
			delete[] m_data;
		}

	private:
		int* m_data;
		size_t m_size;
};

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

// Now in this function is returning by value
Holder createHolder(int size)
{
 	return Holder(size);
}

HolderNewGen createNewGenHolder(int size)
{
 	return HolderNewGen(size);
}

int main() {

	{
		Holder h1(10000); // regular constructor
		Holder h2 = h1;   // copy constructor

		Holder h5(10000);  // regular constructor
		Holder h6(60000);  // regular constructor
		h5 = h6;

		// Here compiler will create a temporary storage for r value 
		// Now, our Holder is a heavy-weight object due to its internal memory allocation, 
		// which is a very expensive task: returning such things by value with our current 
		// class design would trigger multiple expensive memory allocations, which is rarely a great idea.
		Holder h = createHolder(1000);
		//The temporary object that came is passed to the Holder class copy constructor
		//According to our current design, the copy constructor allocates its own m_data pointer by
		// copying the data from the temporary object. Two expensive memory allocations:
		// a) during the creation of the temporary, b) during the actual object copy-construct operation.

		// To deal with this problem we have move constructor and move assignment operator
		Holder h3 = createHolder(2000); // move constructor (rvalue in input) (1) 
		h2 = h3;                        // assignment operator (lvalue in input)
	  	h2 = createHolder(500);         // move assignment operator (rvalue in input)
	}

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

