#
# PROGRAM:    assign8
# PROGRAMMER: Jeremy Torossian
# LOGON ID:   z1821996
# DATE DUE:   4/13/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11 -g

# Rule to link object code files to create executable file
assignmnet9.exe: assignment9.o
	g++ $(CCFLAGS) -o assignment9.exe assignment9.o

# Rules to compile source code file to object code
assignment8.o: assignment9.cc assignment9.h
	g++ $(CCFLAGS) -c assignment9.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment9.exe

