//***************************************************************
// PROGRAM:    CSCI 340 Assignment 9
// PROGRAMMER: Jeremy Torossian
// LOGON ID:   z1821996
// DUE DATE:   5/04/2018
//
// FUNCTION:   Creates a graph that is then traversed using the
//             depth first method. The results are then printed.
//
//***************************************************************


#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include "assignment9.h"
#include <string>
using namespace std;

graph::graph(const char * filename)
{
	ifstream infile(filename); //Puts the file into an ifstream variable
	list<int> temp;
	if (!infile)//Checks if the file was opened
	{
		cerr << "Can't open file " << filename << endl;
		exit(-1);
	}
	char n;
	int nsize;
	infile >> n;
	size = n - '0';

	for (int i = 0; i < size; ++i)//Collects the labels of the graph from the file
	{
		infile >> n;
		labels.push_back(n);
	}

	while (infile)//Stores the adjacency nodes of the given node
	{
		infile >> n;
		int x = 0;
		if (n == '0') //Checks for empty variable
			break;

		for (int i = 0; i < size; i++) //Pushes the adjacency nodes into a temporary list
		{
			infile >> n;
			x = n - '0';
			temp.push_back(x);
		}

		adj_list.push_back(temp); //Stores the tempory list into the adjacency list
		temp.clear(); //Clears the temporary list
	}

}

graph::~graph() //Deconstructor
{
	PathOrder.clear();
	VisitingOrder.clear();
	adj_list.clear();
	labels.clear();
}

void graph::depth_first(int v)
{
	list<int> temp;
	std::vector<int>::iterator it;
	temp.clear(); //Clears the temporary list

	temp = adj_list[v]; //Assigns the adjacency nodes of the node that is based on v
	int Order = 0;
	bool check = false;
	VisitingOrder.push_back(v);//Pushes the current node into the visit order


	for (list<int>::iterator it = temp.begin(); it != temp.end(); it++)//Iterates through the temporary list
	{
		if (*it == 1)//Stop once it finds adjacency node
		{
			for (vector<int>::iterator vi = VisitingOrder.begin(); vi != VisitingOrder.end(); vi++) //Checks if that node has already been visited
			{
				if (*vi == Order)//Sets check to 'true' if it has already been visited
				{
					check = true;
				}
			}

			if (check == false)//If it hasnt been visited, it creates a path based on the current node and the adjacency node associated with the current value of 'order'
			{
				PathOrder.push_back(make_pair(v, Order));
				depth_first(Order);//Visits the node that is based on 'order'
			}

		}
		check = false;
		++Order;
	}

}

int graph::get_size() const
{
	return size;//Gets the size of the graph
}

void graph::traverse()
{
	int vertex;
	std::vector<int>::iterator it;
	cout << "-------- Traverse of graph -----" << endl;
	CurrentOrder = 0;

	for(int i = 0; i < size; i++) //Traverses the tree
	{
	it = find (VisitingOrder.begin(), VisitingOrder.end(), i); //Checks if the node based on 'i' has already been visited
		if(it == VisitingOrder.end()) //If the node has not yet been visited, it traverses the node using 'depth_first'
		{
		depth_first(i);
		}
	}

	for (int i = 0; i < size; i++) //Prints out the order the nodes were visited
	{
		vertex = VisitingOrder[i];
		cout << labels[vertex] << " ";
	}

	cout << endl;
	for (int j = 0; j < PathOrder.size(); j++) //Prints out the paths used to traverse the graph
	cout << "(" << labels[PathOrder[j].first] << ", " << labels[PathOrder[j].second] << ") ";

	cout << endl;
	cout << "--------- End of traverse -------" << endl;
	cout << endl;

}

void graph::print() const
{
	list<int> temp;
	vector<int> paths;
	int pathnum = 0;
	cout << endl;
	cout << "Number of vertices in the graph: " << get_size() << endl;
	cout << endl;
	cout << "--------graph------" << endl;
	for (int i = 0; i < size; i++)
	{
		pathnum = 0;
		cout << labels[i] << ": "; //Prints out a node of the graph based on the current value of 'i'
		temp = adj_list[i]; //Creates a temporary list based on the current value of 'i'
		for (list<int>::iterator it = temp.begin(); it != temp.end(); it++) //Looks for the adjecency nodes associated with the temporary list
		{
			if (*it == 1)
				paths.push_back(pathnum); //If the current node is an adjacency node it is pushed into 'paths'

			pathnum++;
		}

		for (vector<int>::iterator vi = paths.begin(); vi != paths.end(); vi++) //Prints out the labels associated with the nodes in 'paths'
			cout << labels[*vi] << ", ";

		paths.clear();
		temp.clear();
		cout << endl;
	}
	cout << "------- end of graph ------" << endl;
	cout << endl;
}


#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();

    g.traverse();

    return 0;
}

#endif

