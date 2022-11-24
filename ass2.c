#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

enum { NS_PER_SECOND = 1000000000 };

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td)
{
    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}

void countA() {
    long long int a = pow(2, 32);
    while (a > 0)
    {
        a--;
    }
}
void countB() {
    long long int a = pow(2, 32);
    while (a > 0)
    {
        a--;
    }
}
void countC() {
    long long int a = pow(2, 32);
    while (a > 0)
    {
        a--;
    }
}

static void *THR_A() {
  struct sched_param *p;
  pthread_setschedparam(pthread_self(), SCHED_OTHER, p);
  countA();
}
static void *THR_B() {
  struct sched_param *p;
  pthread_setschedparam(pthread_self(), SCHED_RR, p);
  countB();
}
static void *THR_C() {
  struct sched_param *p;
  pthread_setschedparam(pthread_self(), SCHED_FIFO, p);
  countC();
}


int main() {
// struct timespec RR_start, RR_finish, RR_delta, FIFO_start, FIFO_finish, FIFO_delta, OTHER_start, OTHER_finish, OTHER_delta;

double RR_start, RR_finish, RR_delta, FIFO_start, FIFO_finish, FIFO_delta, OTHER_start, OTHER_finish, OTHER_delta;

  pthread_t thr1, thr2, thr3;
  pthread_create(&thr1, NULL, THR_A, NULL);
  RR_start = clock();
	// clock_gettime(CLOCK_REALTIME, &RR_start);
  pthread_create(&thr2, NULL, THR_B, NULL);
  FIFO_start = clock();
	// clock_gettime(CLOCK_REALTIME, &FIFO_start);
  pthread_create(&thr3, NULL, THR_C, NULL);
  OTHER_start = clock();
	// clock_gettime(CLOCK_REALTIME, &OTHER_start);
  pthread_join(thr1, NULL);
  RR_finish = clock();
	// clock_gettime(CLOCK_REALTIME, &RR_finish);
  pthread_join(thr2, NULL);
  FIFO_finish = clock();
	// clock_gettime(CLOCK_REALTIME, &FIFO_finish);
  pthread_join(thr3, NULL);
  OTHER_finish = clock();
	// clock_gettime(CLOCK_REALTIME, &OTHER_finish);
    RR_delta = RR_finish - RR_start;
	// sub_timespec(RR_start, RR_finish, &RR_delta);
    FIFO_delta = FIFO_finish - FIFO_start;
	// sub_timespec(FIFO_start, FIFO_finish, &FIFO_delta);
	sub_timespec(OTHER_start, OTHER_finish, &OTHER_delta);
    OTHER_delta = OTHER_finish - OTHER_start;

    printf("%lf\n", RR_delta);
    printf("%lf\n", FIFO_delta);
    printf("%lf\n", OTHER_delta);
	//  printf("%d.%.9ld\n", (int)RR_delta.tv_sec, RR_delta.tv_nsec);
	//  printf("%d.%.9ld\n", (int)FIFO_delta.tv_sec, FIFO_delta.tv_nsec);
	//  printf("%d.%.9ld\n", (int)OTHER_delta.tv_sec, OTHER_delta.tv_nsec);
  
  return 0;
}
