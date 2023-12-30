#include "philo.h"

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (phnum + 4) % NUM_PHILOSOPHERS
#define RIGHT (phnum + 1) % NUM_PHILOSOPHERS

int state[NUM_PHILOSOPHERS];
int phil[NUM_PHILOSOPHERS] = { 0, 1, 2, 3, 4 };
pthread_mutex_t mutex;
pthread_cond_t condition[NUM_PHILOSOPHERS];

void test(int phnum) {
  if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
      state[phnum] = EATING;
      sleep(2);
      printf("Philosopher %d takes fork %d and %d\n", phnum + 1, LEFT + 1, phnum + 1);
      printf("Philosopher %d is Eating\n", phnum + 1);
      pthread_cond_signal(&condition[phnum]);
  }
}

void take_fork(int phnum) {
  pthread_mutex_lock(&mutex);
  state[phnum] = HUNGRY;
  printf("Philosopher %d is Hungry\n", phnum + 1);
  test(phnum);
  while (state[phnum] != EATING)
      pthread_cond_wait(&condition[phnum], &mutex);
  pthread_mutex_unlock(&mutex);
}

void put_fork(int phnum) {
  pthread_mutex_lock(&mutex);
  state[phnum] = THINKING;
  printf("Philosopher %d putting fork %d and %d down\n", phnum + 1, LEFT + 1, phnum + 1);
  printf("Philosopher %d is thinking\n", phnum + 1);
  test(LEFT);
  test(RIGHT);
  pthread_mutex_unlock(&mutex);
}

void* philospher(void* num) {
  while (1) {
      int* i = num;
      sleep(1);
      take_fork(*i);
      sleep(0);
      put_fork(*i);
  }
}

int main() {
  int i;
  pthread_t thread_id[NUM_PHILOSOPHERS];
  pthread_mutex_init(&mutex, NULL);
  for (i = 0; i < NUM_PHILOSOPHERS; i++)
      pthread_cond_init(&condition[i], NULL);
  for (i = 0; i < NUM_PHILOSOPHERS; i++) {
      pthread_create(&thread_id[i], NULL, philospher, &phil[i]);
      printf("Philosopher %d is thinking\n", i + 1);
  }
  for (i = 0; i < NUM_PHILOSOPHERS; i++)
      pthread_join(thread_id[i], NULL);
}
