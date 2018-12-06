//***************************************************************
// PROGRAM:    CSCI 340 Assignment 1
// PROGRAMMER: Jeremy Torossian
// LOGON ID:   z1821996
// DUE DATE:   4/13/2018
//
// FUNCTION:   Creates an htable that can effectively add, remove
//				and locate entry's using the "hashing" method.
//
//***************************************************************



#include "assignment8.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


// key is in form of letter-letter-digit
// compute sum <-- ascii(pos1)+ascii(pos2)+ascii(pos3)
// compute sum%htable_size
Entry* get_entry(const string& line)
{
	Entry * entryptr = new Entry();
	stringstream ss_line(line); //Converts "line" into a stream for getline to read

	string single_letter;
	string s_key;
	string s_description;

	getline(ss_line, single_letter, ':'); //Gets the first letter from the line
	getline(ss_line, s_key, ':'); //Gets the first letter from the line
	getline(ss_line, s_description, ':'); //Gets the description from the line

	entryptr->key = s_key; //Assigns the new etry's key
	entryptr->description = s_description; //Assigns the new etry's description
	return entryptr; //Returns the new entry

}

string get_key(const string& line)
{

	stringstream ss_line(line); //Converts "line" into a stream for getline to read
	string single_letter;
	string s_key;

	getline(ss_line, single_letter, ':');// Gets the first letter from the line
	getline(ss_line, s_key, ':'); // Gets the first letter from the line
	return s_key;

}
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

HT::HT(int size = 11)
{
	hTable = new vector<Entry>(size); //Initializes the hTable
	table_size = size; //Initializes the size of the table
	item_count = 0; //Initializes the item count of the table
}

HT::~HT()
{
	delete hTable;
}

bool HT::insert(const Entry& r)
{
	int searchval, keyval;
	Entry * temp; //Creates a pointer to the an entry
	keyval = hashing(r.key); //Assigns "keyval" the value of the key passed into the hashing function
	searchval = search(r.key); //Assigns "Searchval" the value that search returns

	if (searchval != -1) //Checks if key has already been inserted into the hTable
	{
		cout << "Error, " << r.key << " already exists" << endl;
		return false;
	}

	else if(table_size == item_count) //Checks if table is full
	{
		cout << "Error, table is full" << endl;
		return false;
	}

	else
	{
		for (int i = 0; i < table_size; i++) //Goes through the hTable looking for an empty slot to insert the new entry
		{
			temp = &hTable->at(keyval); //Assigns "temp" the entry located at the position that keyval represents
			if(temp->key == "---" || temp->key == "+++") //Checks if that location is empty
			{
				(*hTable)[keyval] = r; //Assigns r to that location
				item_count++;//Increments the item count
				return true; 
			}
			keyval = keyval + 1 % table_size; //Increments the keyval using linear probing
		}
	}
	return false;
}

int HT::search(const std::string & key)
{
	Entry * temp; //Creates a pointer to the an entry
	int keyval;
	keyval = hashing(key); ///Assigns "keyval" the value of the key passed into the hashing function

	for (int i = 0; i < table_size; ++i)//Goes through the hTable looking for the key that was passed into the function
	{
		temp = &hTable->at(keyval);//Assigns "temp" the entry located at the position that keyval represents
		if (temp->key == key) //Checks if the key was located
			return keyval;
		keyval = (keyval + 1) % table_size; //Increments the keyval using linear probing
	}
		return -1;

}

bool HT::remove(const std::string & key)
{
	Entry * temp; //Creates a pointer to the an entry
	int keyval;
	keyval = search(key); ///Assigns "keyval" the value of the key passed into the search function
	if (keyval == -1) //Checks if the value was not found
	{
		cout << "The value " << key << " not found" << endl;
		return false;
	}

	temp = & hTable->at(keyval);//Assigns "temp" the entry located at the position that keyval represents
	(*hTable)[keyval].key = "+++";//Assigns "+++" to the variable, effectively removing it from the htable
		--item_count;//Reduces the item count
		return true;

}

void HT::print()
{
	Entry * temp; //Creates a pointer to the an entry
	cout << "----Hash Table-----" << endl;
	cout << endl;

	for (int i = 0; i < table_size; ++i)//Goes through the htable
	{
		temp = &hTable->at(i);//Assigns "temp" the entry located at the position that "i" represents
		if(temp->key != "---" && temp->key != "+++") //Checks if the entry is not empty
		cout << i << ": " << temp->key << " " << temp->description << endl; //Prints the entry to the screen
	}

	cout << "-------------------" << endl;
	cout << endl;
}

int main(int argc, char** argv ) {
    if ( argc < 2 ) {
        cerr << "argument: file-name\n";
        return 1;
    }

    HT ht;
    ifstream infile(argv[1], ios::in);
    string line;
    infile >> line;    
    while ( !infile.eof() ) {
        if ( line[0] == 'A' ) { 
            Entry* e = get_entry( line );
            ht.insert( *e );
            delete e;
        }
        else {
            string key = get_key(line);
            if ( line[0] == 'D' ) {
                cout << "Removing " << key << "...\n";
                bool removed = ht.remove( key );
                if ( removed )
                    cout << key << " is removed successfully...\n\n";
                else
                    cout << key << " does not exist, no key is removed...\n\n";
            }
            else if ( line[0] == 'S' ) {
                int found = ht.search( key );
                if ( found < 0 ) 
                    cout << key << " does not exit in the hash table ..." << endl << endl;
                else
                   cout << key << " is found at table position " << found << endl << endl;
            }
            else if ( line[0] == 'P' ) {
                cout << "\nDisplaying the table: " << endl;
                ht.print();
            }
            else
                cerr << "wrong input: " << line << endl;
        }
        infile >> line;
 
    }

    infile.close();
    return 0;
}
