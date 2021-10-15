#include "philo.h"  

t_test *src()
{
    static t_test abc;

    return(&abc);
}

int out = 0;
pthread_mutex_t  mutex;
  
// The function to be executed by all threads
void    *myThreadFun(void)
{
    for (int i = 0; i < 10000000; i++)
    {
        pthread_mutex_lock()
        out++;
    }
    return (NULL);
}

int main()
{
    pthread_t tid0;
    pthread_t tid1;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid0, NULL, &myThreadFun, NULL);
    pthread_create(&tid1, NULL, &myThreadFun, NULL);
    
    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    pthread_mutex_destroy(&mutex, NULL);
    
    printf("%d\n", out);
    return 0;
}