#include "../lib/unp.h"
#include <time.h>

int main(int argc, char **argv)
{
	int                listenfd       = 0;
	int                connfd         = 0;
	struct sockaddr_in servaddr;
	char               buff[MAXLINE]  = { 0 };
	time_t             ticks;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(13);
	Bind(listenfd,(struct sockaddr*) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	while (1)
	{
		connfd = Accept(listenfd,(struct  sockaddr *) NULL, NULL);

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s \r\n", ctime(&ticks));
		Write(connfd,buff, strlen(buff));

		Close(connfd);
	}
}
