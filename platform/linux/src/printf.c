/**
 * \file platform/linux/src/printf.c
 *
 * \brief Print stuff on Linux.
 *
 * \author Don A. Bailey <donb@labmou.se>
 * \date December 17, 2019
 */
#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>

static pthread_mutex_t plock = PTHREAD_MUTEX_INITIALIZER;

void
thread_printf(const char * fmt, ... )
{       
	va_list L;

	va_start(L, fmt);

	pthread_mutex_lock(&plock);

	fprintf(stdout, "%ld: ", pthread_self());
	vfprintf(stdout, fmt, L);
	fflush(stdout);

	pthread_mutex_unlock(&plock);

	va_end(L);
}

