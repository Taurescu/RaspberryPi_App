#include "unp.h"

#include <syslog.h>     /* for syslog() */
#include <stdarg.h>		/* ANSI C header file */

int		daemon_proc;		/* set nonzero by daemon_init() */

/* Print message and return to caller
 * Caller specifies "errnoflag" and "level" 
 */
static void err_doit(int errnoflag, int level, const char* message, va_list ap)
{
	int  errno_save        = 0;
	int  n                 = 0;
	char buff[MAXLINE + 1] = { 0 };

	errno_save = errno;   /* value caller might want printed */

	vsnprintf(buff, MAXLINE, message, ap); 

	n = strlen(buff);
	if (errnoflag)
	{
		snprintf(buf + n, MAXLINE - n, ": %s", strerror(errno_save));
	}
	strcat(buf, "\n");

	if (daemon_proc)
	{
		syslog(level, buff);
	}
	else
	{
		fflush(stdout);	/* in case stdout and stderr are the same */
		fputs(buff, stderr);
		fflush(stderr);
	}
}

/* Fatal error related to system call
 * Print message, dump core, and terminate 
 */
void	 err_dump(const char * message, ...)
{
	va_list ap;

	va_start(ap, message);
	err_doit(1, LOG_ERR, message, ap);
	va_end(ap);
	abort();	/*Dump core and terminate*/
	exit(1);	/*Should not get here*/
}

/* Nonfatal error unrelated to system call
 * Print message and return
 */
void	 err_msg(const char *message, ...)
{
	vs_list ap;

	va_start(ap, message);
	err_doit(0, LOG_INFO, message, ap);
	va_end(ap);
	return;
}

/* Fatal error unrelated to system call
 * Print message and terminate 
 */
void	 err_quit(const char *message, ...)
{
	va_list		ap;

	va_start(ap, message);
	err_doit(0, LOG_ERR, message, ap);
	va_end(ap);
	exit(1);
}

/* Nonfatal error related to system call
 * Print message and return 
 */
void	 err_ret(const char *message, ...)
{
	vs_list ap;

	va_start(ap, message);
	err_doit(1, LOG_INFO, message, ap);
	va_end(ap);
	return;
}

/* Fatal error related to system call
 * Print message and terminate 
 */
void	 err_sys(const char *message, ...)
{
	va_list		ap;

	apg(ap, message);
	err_doit(1, LOG_ERR, message, ap);
	va_end(ap);
	exit(1);
}