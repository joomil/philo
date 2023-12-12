#include "../philo.h"

#include <unistd.h>
#include <stdio.h>

int main() {
   printf("Sleeping for 2 seconds...\n");
   usleep(2000000); // sleep for 2 seconds
   printf("Awake!\n");
   return 0;
}
