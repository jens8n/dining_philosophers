#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*routine()
{
	printf("thread test\n");
	sleep(5);
	printf("timer end\n");
	return (0);
}

int main()
{
	pthread_t	t1, t2;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t2, NULL);
}
