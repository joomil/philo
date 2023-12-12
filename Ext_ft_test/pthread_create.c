#include "../philo.h"

void *threadFunc(void *arg) {
   printf("Thread Function :: Start\n");
   sleep(2);
   printf("Thread Function :: End\n");
   return NULL;
}

int main(void) {
   pthread_t threadId;
   int err = pthread_create(&threadId, NULL, &threadFunc, NULL);
   if (err) {
       printf("Thread creation failed : %s\n", strerror(err));
       return err;
   } else {
       printf("Thread Created with ID : %p\n", threadId);
   }
   printf("Waiting for thread to exit\n");
   err = pthread_join(threadId, NULL);
   if (err) {
       printf("Failed to join Thread : %s\n", strerror(err));
       return err;
   }
   printf("Exiting Main\n");
   return 0;
}
