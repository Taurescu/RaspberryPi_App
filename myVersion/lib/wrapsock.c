#include "unp.h"

int Accept(int fd, struct  sockaddr *sa, socklen_t *salenptr)
{
	int n = 0;

	while (1) {
		if ((n = accept(fd, sa, salenptr)) < 0)
		{
#ifdef	EPROTO
			if (errno != EPROTO || errno != ECONNABORTED)
#else
			if (errno != ECONNABORTED)
#endif
			{
				err_sys("accept error");
			}
		}
		else
		{
			break;
		}
	}
	return (n);
}

void Bind(int fd,struct sockaddr *sa, socklen_t salen)
{
	if (bind(fd, sa, salen) < 0)
	{
		err_sys("bind error");
	}
}

void Connect(int fd, struct sockaddr *sa, socklen_t salen)
{
	if (connect(fd, sa, salen) < 0)
	{
		err_sys("connect error");
	}
}

void Listen(int fd, int backlog)
{
	char *ptr;

	if ((ptr = getenv("LISTENQ")) != NULL)
	{
		backlog = atoi(ptr);
	}

	if (listen(fd, backlog) < 0)
	{
		err_sys("listen error");
	}
}

int Socket(int family, int type, int protocol)
{
	int n = 0;

	if ((n = socket(family, type, protocol)) < 0)
	{
		err_sys("socket error");
	}
	return (n);
}

void Close(int fd)
{
	if (close(fd) == -1)
	{
		err_sys("close error");
	}
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
	ssize_t n = 0;

	if ((n = read(fd, ptr, nbytes)) == -1)
	{
		err_sys("read error");
	}

	return (n);
}

void Write(int fd, void *ptr, size_t nbytes)
{
	if (write(fd, ptr, nbytes) != nbytes)
	{
		err_sys("write error");
	}
}
