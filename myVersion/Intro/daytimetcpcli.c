#include "../lib/unp.h"

int main(int argc, char **argv)
{
	int sockfd = 0;
	int n = 0;
	char recvline[MAXLINE + 1] = { 0 };
	struct sockaddr_in servaddr = { 0 };

	if (argc != 2)
	{
		err_quit("usage : a.out <IPaddress>");
	}

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
	{
		err_quit("inet_pton error for %s", argv[1]);
	}
	
	Connect(sockfd,(struct sockaddr*) &servaddr, sizeof(servaddr));


	while ( (n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = 0;
		if (fputs(recvline, stdout) == EOF)
		{
			err_sys("fputs error");
		}
	}
	if (n < 0)
	{
		err_sys("read error");
	}

	exit(0);
}
