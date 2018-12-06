//***************************************************************
// PROGRAM:    CSCI 340 Assignment 9
// PROGRAMMER: Jeremy Torossian
// LOGON ID:   z1821996
// DUE DATE:   5/04/2018
//
// FUNCTION:   Header file that the declares the methods and
//             variables used in 'assignment9.cc'
//
//***************************************************************


#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

class graph {
    private:
        int size;
        std::vector< std::list<int> > adj_list;
        std::vector< char > labels;
	std::vector< int > VisitingOrder;
	std::vector< std::pair< int, int > >PathOrder;
	int CurrentOrder;
        void depth_first( int );
    public:
        graph( const char* filename );
        ~graph();
        int get_size() const;
        void traverse( ) ;
        void print ( ) const;
};

#endif 
