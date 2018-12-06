//***************************************************************
// PROGRAM:    CSCI 340 Assignment 2
// PROGRAMMER: Jeremy Torossian
// LOGON ID:   z1821996
// DUE DATE:   02/05/2018
//
// FUNCTION:   This program runs searches for variables using both
//	       a linear search method and binary search method. It
//             then calculates the percentage of successful searches.
//***************************************************************

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include  <cstdlib>

using namespace std;


const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

void genRndNums( vector<int>& v, int seed ) {
	int LOW = 1;
	int HIGH = 200;
	int size = v.size(); //Acquires the size of the vector array.
	int rando;
	srand(seed); //Initializes the random number generator using "seed."

	for (int i = 0; i < size; ++i)
	{
		rando = rand() % HIGH + LOW;  //Creates a random number within range  "low" to "high."
		v[i] = rando; //Inserts the random number into the vector array.
	}
}

bool linearSearch( const vector<int>& inputVec, int x) {
	vector<int>::const_iterator it;

	it = find (inputVec.begin(), inputVec.end(), x); //Looks for the variable "x" within the vector using a linear search method.
	if (it != inputVec.end()) // Returns 'true' if "x" is found within the vector array.
		return true;
	else
		return false;
}

bool binarySearch( const vector<int>& inputVec, int x) {

	if (binary_search(inputVec.begin(), inputVec.end(), x)) // Looks for the variable "x" within the vector using a binary search method.
		return true; // Returns 'true' if "x" is found within the vector array.
	else
		return false;
}

int search( const vector<int>& inputVec, const vector<int>& searchVec,
            bool (*p)( const vector<int>&, int) ){
				int comparison = 0;
				bool check;
				for (unsigned int i = 0; i < searchVec.size(); ++i)
				{
					check = p(inputVec, searchVec[i]); //Searches for the variable that "i" points to within "inputVec"
										// using the search function pass into "P"
					if (check == true) //If the variable that "i" points to is found, the amount of comparisons increments by 1.
						++comparison;
				}
				return comparison;
}

void sortVector (vector<int>& inputVec) {
	sort(inputVec.begin(), inputVec.end());//Sorts the array using the "Sort" function.
}

void printStat (int totalSucCnt, int vec_size) {
	float percentage;
	percentage = ( 100 *(float)totalSucCnt / vec_size ); // Calculates the percentage of successful searches.
	cout << "Successful searches: " << fixed << setprecision(2) << percentage << "%" << endl; //Prints the the percentage of successful searches.
}

void print_vec( const vector<int>& vec ){
	int count = 0;
	int NO_ITEMS = 10;
	int ITEM_W = 6;

	for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++) // Goes through the contents of the array.
	{
		cout << setw(ITEM_W) << *i; // Prints the elements of the array, while setting the width by 6.
		count++; // Counter to keep track how many items have been printed per line.

		if (count == NO_ITEMS) // Checks if the elements printed out is equal to 10.
		{
			cout << endl; // Starts a new line.
			count = 0; // Resets the count.
		}
	}

	cout << endl;

}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

