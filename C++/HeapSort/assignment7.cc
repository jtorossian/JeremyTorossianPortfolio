//***************************************************************
// PROGRAM:    CSCI 340 Assignment 7
// PROGRAMMER: Jeremy Torossian
// LOGON ID:   z1821996
// DUE DATE:   04/06/2018
//
// FUNCTION:   This program creates a heap and sorts it in both 
//             min and max order.
//             
//***************************************************************


#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

const int HEAP_SIZE = 50;

void heapify(vector < int >& v, int heap_size, int r, bool(*compar)(int, int))
{
	int left = 2*r; //Creates the left child of the heap
	int right = 2*r + 1; //Creates the right child of the heap
	int largest;
	int temp;

	if (left <= heap_size && compar(v[left], v[r])) // Checks if the heapsize is less than the left child and compares the left child and the element in r
		largest = left; //Assigns the left child as the largest value
	else
		largest = r; //Assigns the element in r as the largest value

	if (right <= heap_size && compar(v[right], v[largest])) // Checks if the heapsize is less than the right child and compares the right child and the element in r
		largest = right; //Assigns the right child as the largest value

	if (largest != r)// Checks if r is not the largest value
	{
		temp = v[r]; // Assigns r to temp
		v[r] = v[largest]; // Exchanges r and the largest value
		v[largest] = temp;
		temp = 0;
		heapify(v, heap_size, largest, compar); //Recursively calls heapify using the largest value
	}

}

void build_heap(vector < int >& v, int heap_size, bool(*compar)(int, int))
{
	int i;

	for (i = heap_size / 2; i >= 1; --i) //Starts with last half of V and goes until it reaches element 1
		heapify(v, heap_size, i, compar); // Recursively calls heapify.
}

bool less_than(int e1, int e2)
{
	if (e1 < e2) //Checks if the first element is less than the second
		return true; //Returns true if is is
	else
		return false; //Otherwise false
}

bool greater_than(int e1, int e2)
{
	if (e1 > e2) //Checks if the first element is less than the second
		return true; //Returns true if is is
	else
		return false; //Otherwise false
}

int extract_heap(vector < int >& v, int& heap_size, bool(*compar)(int, int))
{
	int max;
	if (heap_size < 1) // Returns error if the heapsize is less than one
		cout << "error underflow" << endl;
	max = v[1]; //Assigns the first element to max
	v[1] = v[heap_size]; //Assigns the last element to the first element
	--heap_size; //Decreases the size of the heap
	heapify(v, heap_size, 1, compar); //Recursively calls heapify function
	return max; //Returns the maximum or minimum element of the heap

}

void heap_sort(vector < int >& v, int heap_size, bool(*compar)(int, int))
{
	for (int i = heap_size; i >= 2; --i) // Loops goes until i is less than or equal to 2
		v[i] = extract_heap(v, heap_size, compar); //Calls extract heap

	reverse(v.begin() + 1, v.end()); // Reverses the order of the array
}



void print_vector(vector < int >& v, int pos, int size)
{
	int count = 0;
	int NO_ITEMS = 8;
	int ITEM_W = 5;

	while(pos <= size) // Goes through the contents of the array.
	{
		cout << setw(ITEM_W) << v[pos]; // Prints the elements of the array, while setting the width by 5.
		count++; // Counter to keep track how many items have been printed per line.

		if (count == NO_ITEMS) // Checks if the elements printed out is equal to 8.
		{
			cout << endl; // Starts a new line.
			count = 0; // Resets the count.
		}
		++pos; // Goes to next element
	}

	cout << endl;

}

int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}
