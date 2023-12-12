#include "../philo.h"

void *threadFunc(void *arg) {
 printf("Thread Function :: Start\n");
 pthread_exit(NULL);
}

int main() {
 pthread_t threadId;
 int err = pthread_create(&threadId, NULL, &threadFunc, NULL);
 if (err) {
     printf("Thread creation failed : %s\n", strerror(err));
     return err;
 } else {
     printf("Thread Created with ID : %p\n", (void *)threadId);
 }
 printf("Waiting for thread to exit\n");
 void *retval;
 err = pthread_join(threadId, &retval);
 if (err) {
     printf("Failed to join Thread : %s\n", strerror(err));
     return err;
 }
 printf("Exiting Main\n");
 return 0;
}
