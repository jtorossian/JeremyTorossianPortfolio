
#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <vector>
#include "assignment5.h"
using namespace std;

const int MAX_SIZE = 40;
const int MAX_COUNT = 40;
const int WIDTH = 5;
const int ROW_SIZE = 8;

int mcount = 0;
int rcount = 0;

void display(int d) {
    if ( mcount < MAX_COUNT ) {
        cout << setw(WIDTH) << d;
        mcount++;
        rcount++;
        if ( rcount == ROW_SIZE ) {
            cout << endl;
            rcount = 0;
        }
    }
}

binTree::binTree()
{
	root = nullptr; // Declares root of binary tree
}

void binTree::insert(int x)
{
	insert(root, x); // Calls the private version of "insert" function
}

unsigned binTree::height() const
{
	return height(root); // Returns what the private version of "height" returns
}

unsigned binTree::size() const
{
	return size(root); // Returns what the private version of "size" returns
}

void binTree::inorder(void(*p)(int))
{
	inorder(root, p); // Calls the private version of "inorder" function

}

void binTree::preorder(void(*p)(int))
{
	preorder(root, p); // Calls the private version of "preorder" function
}

void binTree::postorder(void(*p)(int))
{
	postorder(root, p); // Calls the private version of "postorder" function
}

void binTree::insert(Node *& r, int x)
{
	if (r == nullptr) // Checks if the node is empty
		r = new Node(x); // Assigns value onto empty node
	else if (size(r->right) < size(r->left)) // Checks if the size of the right now is less the than the size of the right node
		insert(r->right, x); // Recursively calls insert function and inserts the value into the right node
	else
		insert(r->left, x); // Recursively calls insert function and inserts the value into the left node

}

unsigned binTree::height(Node * r) const
{
	if (r == nullptr) // Checks if node is empty
		return -1;
	int left = height(r->left); // Recursively calls height function and acquires the height of the left sub tree
	int right = height(r->right); // Recursively calls height function and acquires the height of the right sub tree
	return max(left, right) + 1; // Gets the total height of the tree
}

unsigned binTree::size(Node * r) const
{
	if (r == nullptr) // Checks if node is empty
		return 0;

	else
		return(size(r->left) + size(r->right) + 1); //Gets the total size of the tree

}

void binTree::inorder(Node * r, void(*p)(int))
{
	if (r != nullptr)
	{
		inorder(r->left, p); //Traverses the left subtree
		p(r->data); //Visits the Node
		inorder(r->right, p); //Traverses the right subtree
	}
}

void binTree::preorder(Node * r, void(*p)(int))
{
	if (r != nullptr)
	{
		p(r->data); //Visits the Node
		preorder(r->left, p); //Traverses the left subtree
		preorder(r->right, p); //Traverses the right subtree
	}
}

void binTree::postorder(Node * r, void(*p)(int))
{
	if (r != nullptr)
	{
		postorder(r->left, p); //Traverses the left subtree
		postorder(r->right, p); //Traverses the right subtree
		p(r->data); //Visits the Node
	}
}
//#define BINTREE_MAIN
#ifdef BINTREE_MAIN
int main() {
    vector<int> v(MAX_SIZE);
    for (int i=1; i<MAX_SIZE; i++)
        v[i] = i;
    random_shuffle( v.begin(), v.end() );

    binTree bt;
    vector<int>::iterator it;
    for (it=v.begin(); it!=v.end(); it++)
        bt.insert( *it );

    cout << "Height: " << bt.height() << endl;
    cout << "Size: " << bt.size() << endl;
    cout << "In order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.inorder( display );
    cout << "\n\nPre order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.preorder( display );
    cout << "\n\nPost order traverse (displaying first " << MAX_COUNT << " numbers): " << endl;
    mcount = rcount = 0;
    bt.postorder( display );

    cout << endl;
    return 0;
}

#endif
