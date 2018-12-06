
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
			ssize_t nread = read(newsock, buffer, 1024);
			readtest(nread);
			buffer[nread] = '\0';
			split = strtok(buffer, " ");
			if (strcmp(buffer, "GET") == 0)
			{
				dir = opendir(argv[2]);
				if (dir == NULL)
				{
					perror(argv[2]);
					exit(EXIT_FAILURE);
				}

				split = strtok(NULL, " ");
				chomp(split);

				if (split[0] == '/')
				{
					readloop(dir, newsock, cbuffer);
					write(newsock, "\n", 1);
					closedir(dir);
				}

				else
				{
					dir = opendir(split);
					if (dir != NULL)
					{	
				
						readloop(dir, newsock, cbuffer);
						ssize_t nwrite = write(newsock, "\n", 1);
						writetest(nwrite);
						closedir(dir);
					}

					else
					{
						input = open(split, O_RDWR); // opens file
						if (input == -1)
						{
							ssize_t nwrite = write(newsock, "Error:", 8);
							writetest(nwrite);
							nwrite = write(newsock, split, strlen(split));
							writetest(nwrite);
							nwrite = write(newsock, " not found.", 12);
							writetest(nwrite);
							nwrite = write(newsock, "\n", 1);
							writetest(nwrite);
							exit(EXIT_FAILURE);
						}

						ssize_t nread = read(input, buffer, 1024);
						readtest(nread);
						ssize_t nwrite = write(newsock, "......contents of file......", 28);
						writetest(nwrite);
						nwrite = write(newsock, "\n", 1);
						writetest(nwrite);
						nwrite = write(newsock, buffer, nread);
						writetest(nwrite);
						nwrite = write(newsock, "\n", 1);
						writetest(nwrite);
						close(input);
						close(newsock);
					}
				}
				close(newsock);
			}
			else
			{
				ssize_t nwrite = write(newsock, "Invalid command entered", 25);
				writetest(nwrite);
				close(newsock);
			}
		}

	}
	//close
	close(sock);
	return 0;
}



void chomp(char *s)
{
	for (char *p = s + strlen(s) - 1; *p == '\r' || *p == '\n'; p--)
		*p = '\0';
}

void writetest(ssize_t nwrite)
{
	if (nwrite == -1)
	{
		perror("Mismatch in number of bytes");
		exit(EXIT_FAILURE);
	}
}
void readtest(ssize_t nread)
{
if (nread == -1)
	{
		perror("Failed to receive message");
		exit(EXIT_FAILURE);
	}
}

void readloop(DIR* dir,int newsock, char* cbuffer)
{
	ssize_t nwrite = write(newsock, "......contents of directory......", 33);
	writetest(nwrite);
	nwrite = write(newsock, "\n", 1);
	writetest(nwrite);
	struct dirent *sd;
	while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
		{
			int count = 0;
			cbuffer = sd->d_name;
			while (cbuffer[count] != '\0')
			{
				count++;
			}
			write(newsock, cbuffer, count);
			writetest(nwrite);
			nwrite = write(newsock, " ", 1);
			writetest(nwrite);
		}
	}
}
