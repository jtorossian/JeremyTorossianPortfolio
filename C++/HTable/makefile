#
# PROGRAM:    assign8
# PROGRAMMER: Jeremy Torossian
# LOGON ID:   z1821996
# DATE DUE:   4/13/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11 -g

# Rule to link object code files to create executable file
assignmnet8.exe: assignment8.o
	g++ $(CCFLAGS) -o assignment8.exe assignment8.o

# Rules to compile source code file to object code
assignment8.o: assignment8.cc assignment8.h
	g++ $(CCFLAGS) -c assignment8.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment8.exe

