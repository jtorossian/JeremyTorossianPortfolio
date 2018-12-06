#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string.h>
#include <dirent.h>

using namespace std;
int main(int argc, char *argv[]) {

	void chomp(char*);
	void writetest(ssize_t);
	void readtest(ssize_t);
	void readloop(DIR*, int, char*);


	//socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		perror("socket");
		exit(1);
	}

	struct sockaddr_in myaddr;
	struct sockaddr_in theiraddr;

	memset(&myaddr, 0, sizeof(myaddr));
	myaddr.sin_family = AF_INET;
	myaddr.sin_addr.s_addr = INADDR_ANY;
	myaddr.sin_port = htons(atoi(argv[1]));

	//bind
	if (bind(sock, (struct sockaddr *) &myaddr, sizeof(myaddr)))
	{
		perror("bind");
		exit(2);
	}

	//listen
	if (listen(sock, 64) == -1)
	{
		perror("listen");
		exit(3);
	}

	pid_t pid;
	int input;
	char buffer[1024];
	char* cbuffer;
	char* split;
	int newsock;
	DIR *dir;
	socklen_t clientlen = sizeof(sockaddr_in);
	while (1)
	{
		//accept
		newsock = accept(sock, (struct sockaddr *) &theiraddr, &clientlen);
		if (newsock < 0)
		{
			perror("Accept Failed");
			exit(EXIT_FAILURE);
		}

		//Fork
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid != 0)
		{
			//parent
			close(newsock);
			continue;
		}

		else
		{
			//handle connection
			if (newsock == -1)
			{
				perror("socket");
				exit(4);
			}
			//read
			ssize_t nread = read(newsock, buffer, 1024);	//Reading in commands from client.
			readtest(nread);	//Error checking
			buffer[nread] = '\0';	
			split = strtok(buffer, " ");	//Splits the "GET" command and path
			if (strcmp(buffer, "GET") == 0)	//Checks if the first command is GET
			{
				dir = opendir(argv[2]);	//Open directory
				if (dir == NULL)	//Error checks NULL
				{
					perror(argv[2]);
					exit(EXIT_FAILURE);
				}

				split = strtok(NULL, " ");	//Gets path
				chomp(split);	

				if (split[0] == '/') //Check if path refers to the root directory of the server
				{
					readloop(dir, newsock, cbuffer);	//Enters into readloop
					ssize_t nwrite = write(newsock, "\n", 1);	//Writes newline
					writetest(nwrite); //error tests newline
					closedir(dir);	//Closes directory
				}

				else
				{
					dir = opendir(split); //Attempts to open path as a directory
					if (dir != NULL)	//Checks if the path was able to open able as a directory
					{	
				
						readloop(dir, newsock, cbuffer); //enters path into readloop
						ssize_t nwrite = write(newsock, "\n", 1); //Writes newline
						writetest(nwrite); //error tests newline
						closedir(dir);	//Closes directory
					}

					else
					{
						input = open(split, O_RDWR); // opens file
						if (input == -1)
						{
							ssize_t nwrite = write(newsock, "Error:", 8); //Writes "Error " to client
							writetest(nwrite);	//error tests
							nwrite = write(newsock, split, strlen(split)); //Writes contents of split to client
							writetest(nwrite);	//error tests
							nwrite = write(newsock, " not found.", 12); //Writes "not found " to client
							writetest(nwrite);	//error tests
							nwrite = write(newsock, "\n", 1); //Writes newline
							writetest(nwrite);	//error tests
							exit(EXIT_FAILURE);
						}

						ssize_t nread = read(input, buffer, 1024);	//Reads in file given by the path
						readtest(nread);	//Error tests read
						ssize_t nwrite = write(newsock, "......contents of file......", 28);	//Writes "contents of file " to client
						writetest(nwrite);	//Error tests write
						nwrite = write(newsock, "\n", 1);	//Writes newline
						writetest(nwrite);	//Error tests write
						nwrite = write(newsock, buffer, nread);	//Writes in file given by the path
						writetest(nwrite);	//Error tests write
						nwrite = write(newsock, "\n", 1);	//Writes newline
						writetest(nwrite);	//Error tests write
						close(input);	//Closes input
					}
				}
				close(newsock); //Closes client
			}
			else
			{
				ssize_t nwrite = write(newsock, "Invalid command entered", 24);	//Writes "Invalid command entered" to client
				writetest(nwrite);	//Error tests write
				nwrite = write(newsock, "\n", 1);	//Writes newline
				writetest(nwrite);	//Error tests write
				close(newsock); //Closes client
			}
		}

	}
	//close
	close(sock);
	return 0;
}

void chomp(char *s)
{
	for (char *p = s + strlen(s) - 1; *p == '\r' || *p == '\n'; p--) //Removes newline
		*p = '\0';
}

void writetest(ssize_t nwrite)	// Error tests write()
{
	if (nwrite == -1)
	{
		perror("Mismatch in number of bytes");
		exit(EXIT_FAILURE);
	}
}

void readtest(ssize_t nread)	// Error tests read()
{
if (nread == -1)
	{
		perror("Failed to receive message");
		exit(EXIT_FAILURE);
	}
}

void readloop(DIR* dir,int newsock, char* cbuffer) //Reads through contents of directory
{
	ssize_t nwrite = write(newsock, "......contents of directory......", 33);	//Writes "contents of directory" to client
	writetest(nwrite);	//Error tests write
	nwrite = write(newsock, "\n", 1);	//Writes newline to client
	writetest(nwrite);	//Error tests write
	struct dirent *sd;
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.') //Checks to not write files that start with '.;
		{
			int count = 0;
			cbuffer = sd->d_name; //Assigns filename to cbuffer
			while (cbuffer[count] != '\0') //Gets the size of the filename
			{
				count++;
			}
			write(newsock, cbuffer, count); //Writes the filename to client	
			writetest(nwrite);	//Error tests write
			nwrite = write(newsock, " ", 1); //Writes space inbetween filenames to client
			writetest(nwrite);	//Error tests write
		}
	}
}