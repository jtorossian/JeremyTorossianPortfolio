/***************************************************
*		Programmer: Jeremy Torossian
*		Z-ID: Z1821996
*		Assignment Number: 6
*		Due Date: 3/27/2018
****************************************************/
#include <iostream>
#include "assignment5.h"
#include "assignment6.h"
using namespace std;

void BST::insert(int x)
{
	insert(root, x); // Calls the private version of "insert" function
}

bool BST::search(int x)
{
	return search(root, x);// Calls the private version of "search" function
}

bool BST::remove(int x)
{
	return remove(root, x); // Calls the private version of "remove" function
}

int BST::sumLeftLeaves()
{
	return sumLeftLeaves(root); // Calls the private version of "sumLeftLeaves" function
}

void BST::insert(Node *& r, int x)
{
		if (r == nullptr) // If the node is empty it assigns 'x' to the node
			r = new Node(x);
		else if (x > r->data) // Checks if the data in the node is less than 'x'
			insert(r->right, x); //If it is, it inserts into the right
		else
			insert(r->left, x); // Otherwise, it inserts into the left
}

bool BST::search(Node *& r, int x)
{
	if (r)
	{
		if (r->data == x) //If the data in the node is equal to x, it returns x
			return true;
		else if (x < r->data)// Checks if the data in the node is less than 'x'
			return search(r->left, x);//If it is, it searches the left node
		else
			return search(r->right, x);// Otherwise, it searchers the right
	}
	else //If x is not found, it returns false
		return false;
}

bool BST::remove(Node *& r, int x)
{
	Node * temp = r;
	if (!r) //If the node is not found, it returns false
		return false;
	else
	{
		if (r->data > x)// Checks if the data in the node is greater than 'x'
			remove(r->left, x); // if it is, it recursively calls 'remove' to the left node
		else if (r->data < x)
			remove(r->right, x);// otherwise, it recursively calls 'remove' to the right node
		else
		{
			if (r->right && r->left) // If it has two children
			{
				temp = r->left; //Sets the temp node
				while (temp->right != nullptr) //Gets the predecessor node
					temp = temp->right;

				r->data = temp->data;//Copies pred to the data
				remove(r->left, r->data); //Recursively calls 'remove' to the left node
			}
			else if (!r->right && !r->left) //If it is a leaf node
			{

				delete r; // deletes the node
				r = nullptr; //Assigns NULL to the node
			}
			else // If it has 1 child node
			{
				temp = r; //Assigns r to temp
				if (!r->right) //If there is no right node
					r = r->left; //Assigns the left node to the original node
				else
					r = r->right; //Otherwise, it assigns the right node to the original node

				delete temp; //Deletes the node
			}
		}
		return true; //Returns true on success
	}
}

int BST::sumLeftLeaves(Node *& r)
{
	int sum = 0;

	if (r)
	{
		if (r->left && !r->left->right && !r->left->left) //If there is a node to the left, and no nodes to the left or right of that node.
			sum += r->left->data; //Adds the date of the left node to sum
		else
			sum += sumLeftLeaves(r->left); //Otherwise, it adds what the recursive call to sumLeftLeaves returns, taking the left node as a parameter

		sum += sumLeftLeaves(r->right);// Adds what the recursive call to SumleaftLeaves returns, taking the right node as a parameter
	}
	return sum;

}

