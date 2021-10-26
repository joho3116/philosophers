# include "include/philosopher.h"


typedef struct  ph{
    pthread_t thread;
    int i;
}ph_t;

int g_count = 0;
pthread_mutex_t mutex;

void    *print(void *th)
{
    int i;
    char *name;

    name = th;
    pthread_mutex_lock(&mutex);
    for (i = 0; i < 4; i++)
    {
        printf("%s count is %d\n", name, g_count);
        g_count++;
        sleep(1);
    }
    printf("%s helllllo?\n", name);
    pthread_mutex_unlock(&mutex);
    return (NULL);
}

int main()
{
    pthread_t  t1;
    pthread_t  t2;
    pthread_t  print1;

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, print, (void *) "thread1");
    pthread_create(&t2, NULL, print, (void *) "thread2");
    pthread_create(&print1, NULL, print, (void *) "print1");
    // pthread_mutex_init(&mutex2, NULL);
    // pthread_mutex_lock(&mutex2);
    // printf("mutex1 on!!!\n");
    // // printf("ph_t i is == %d\n", t1->i);
    // pthread_mutex_unlock(&mutex2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(print1, NULL);
    return (0);
}