#include "../philo.h"

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

void *threadFunc(void *arg) {
 pthread_mutex_lock(&lock);
 printf("Thread Function :: Start\n");
 pthread_mutex_unlock(&lock);
 return NULL;
}

int main() {
 pthread_t threadId;
 int err = pthread_mutex_init(&lock, NULL);
 if (err) {
     printf("Mutex initialization failed : %s\n", strerror(err));
     return err;
 }
 err = pthread_create(&threadId, NULL, &threadFunc, NULL);
 if (err) {
     printf("Thread creation failed : %s\n", strerror(err));
     return err;
 } else {
     printf("Thread Created with ID : %p\n", (void *)threadId);
 }
 err = pthread_join(threadId, NULL);
 if (err) {
     printf("Failed to join Thread : %s\n", strerror(err));
     return err;
 }
 pthread_mutex_destroy(&lock);
 printf("Exiting Main\n");
 return 0;
}
