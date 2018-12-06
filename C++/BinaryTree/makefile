 #
# PROGRAM:    assign6
# PROGRAMMER: Jeremy Torossian	
# LOGON ID:   z1821996
# DATE DUE:   03/27/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment6.exe: assignment6main.o assignment6.o assignment5.o
	g++ $(CCFLAGS) -o assignment6.exe assignment6main.o assignment6.o assignment5.o

# Rules to compile source code file to object code
assignment6main.o: assignment6main.cc assignment6.h assignment5.h
	g++ $(CCFLAGS) -c assignment6main.cc

assignment6.o: assignment6.cc assignment5.h assignment6.h
	g++ $(CCFLAGS) -c assignment6.cc

assignment5.o: assignment5.cc assignment5.h
	g++ $(CCFLAGS) -c assignment5.cc

# Header file dependency
Assignment6.h: Assignment5.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6.exe
