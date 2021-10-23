# include "include/philosopher.h"

void    *print(void *th)
{
    printf("helllllo?");
    return (NULL);
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, print, NULL);
    pthread_join(thread, NULL);
    return (0);
}