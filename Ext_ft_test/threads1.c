#include "../philo.h"

void    *my_turn(void *arg)
{
    int i;

    i = 0;
    while (i++ < 8)
    {
        sleep(1);
        printf("My turn! %d\n", i);
    }
    return (NULL);
}

void    your_turn()
{
    int i;

    i = 0;
    while (i++ < 3)
    {
        sleep(2);
        printf("Your turn! %d\n", i);
    }
}

int     main()
{
    pthread_t   newthread;

    pthread_create(&newthread, NULL, my_turn, NULL);

    //my_turn();
    your_turn();
    pthread_join(newthread, NULL);
    return (0);
}