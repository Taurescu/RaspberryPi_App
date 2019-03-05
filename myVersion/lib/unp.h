#ifndef GUARD_UNP_H
#define GUARD_UNP_H

#include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<errno.h>
#include	<fcntl.h>		/* for nonblocking */
#include	<netdb.h>

#include	<sys/un.h>		/* for Unix domain sockets */

#ifdef	HAVE_POLL_H
# include	<poll.h>		/* for convenience */
#endif

#ifdef	HAVE_SYS_EVENT_H
# include	<sys/event.h>	/* for kqueue */
#endif

#ifdef	HAVE_STRINGS_H
# include	<strings.h>		/* for convenience */
#endif

#ifndef	INADDR_NONE
/* $$.Ic INADDR_NONE$$ */
#define	INADDR_NONE	0xffffffff	/* should have been in <netinet/in.h> */
#endif

#ifndef	SHUT_RD				/* these three POSIX names are new */
#define	SHUT_RD		0	/* shutdown for reading */
#define	SHUT_WR		1	/* shutdown for writing */
#define	SHUT_RDWR	2	/* shutdown for reading and writing */
#endif

/* *INDENT-OFF* */
#ifndef INET_ADDRSTRLEN
/* $$.Ic INET_ADDRSTRLEN$$ */
#define	INET_ADDRSTRLEN		16	/* "ddd.ddd.ddd.ddd\0"
									1234567890123456 */
#endif

									/* Define following even if IPv6 not supported, so we can always allocate
								   an adequately sized buffer without #ifdefs in the code. */
#ifndef INET6_ADDRSTRLEN
								   /* $$.Ic INET6_ADDRSTRLEN$$ */
#define	INET6_ADDRSTRLEN	46	/* max size of IPv6 address string:
				   "xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx" or
				   "xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:ddd.ddd.ddd.ddd\0"
					1234567890123456789012345678901234567890123456 */
#endif
					/* *INDENT-ON* */

/* Define bzero() as a macro if it's not in standard C library. */
#ifndef HAVE_BZERO
#define bzero(ptr,n)	memset(ptr, 0, n)
#endif

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

   /* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */

/* Define some port number that can be used for our examples */
#define	SERV_PORT		 9877			/* TCP and UDP */
#define	SERV_PORT_STR	"9877"			/* TCP and UDP */
#define	UNIXSTR_PATH	"/tmp/unix.str"	/* Unix domain stream */
#define	UNIXDG_PATH		"/tmp/unix.dg"	/* Unix domain datagram */

#define min(a,b)  ((a) < (b)) ? (a) : (b)
#define max(a,b)  ((a) > (b)) ? (a) : (b)

#define SA struct sockaddr

			/* prototypes for our own library functions */

int	     daemon_init(const char *, int);

/* prototypes for our Unix wrapper functions: see {Sec errors} */

void	 Close(int);
ssize_t	 Read(int, void *, size_t);
void	 Write(int, void *, size_t);

/* prototypes for our socket wrapper functions: see {Sec errors} */
int		 Accept(int, SA *, socklen_t *);
void	 Bind(int, const SA *, socklen_t);
void	 Connect(int, const SA *, socklen_t);
void	 Listen(int, int);
void	 Send(int, const void *, size_t, int);
int		 Socket(int, int, int);


void	 err_dump(const char *, ...);
void	 err_msg(const char *, ...);
void	 err_quit(const char *, ...);
void	 err_ret(const char *, ...);
void	 err_sys(const char *, ...);



#endif /*GUARD_UNP_H*/