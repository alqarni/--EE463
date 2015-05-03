/*
 * PThreadSchedulingAPI.c
 *
 *  Created on: Jul 3, 2012
 *      Author: User
 */

#include <pthread.h>
#include <stdio.h>

#define NUM THREADS 5
int main(int argc, char *argv[])
{
	 int i;
	pthread_t tid[NUM THREADS];
	pthread_attr_t attr;

	/* get the default attributes */
	pthread_attr init(&attr);

	/* set the scheduling algorithm to PROCESS or SYSTEM */
	pthread_attr setscope(&attr, PTHREAD SCOPE SYSTEM);

	/* set the scheduling policy - FIFO, RT, or OTHER */
	pthread_attr setschedpolicy(&attr, SCHED OTHER);

	/* create the threads */
	for (i = 0; i < NUM THREADS; i++)
		pthread create(&tid[i],&attr,runner,NULL);

	/* now join on each thread */
	for (i = 0; i < NUM THREADS; i++)
		pthread join(tid[i], NULL);
}
 /* Each thread will begin control in this function */
void *runner(void *param)
{
	printf("I am a thread\n");
	pthread_exit(0);
}

