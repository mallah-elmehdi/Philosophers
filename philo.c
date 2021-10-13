#include "philo.h"  

int g = 0;
  
// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
    int *myid = (int *)vargp;
    static int s = 0;
    ++s; ++g;
    printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
    return (vargp);
}

int main()
{
    int i;
    pthread_t tid;
    for (i = 0; i < 3; i++)
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
  
    pthread_exit(NULL);
    return 0;
}