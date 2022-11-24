#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>




struct timespec alpha;

struct timespec Delta;

struct timespec bravo;

struct timespec charlie;

struct timespec gamma;

struct timespec theta;

void *countA(){
  FILE *f;
  f=fopen("other.txt","w");
  clock_gettime(CLOCK_MONOTONIC,&alpha);

  for(int i=1;i<=pow(2,32);i++){
  }

  clock_gettime(CLOCK_MONOTONIC,&Delta);
  f.write(f,(double)(Delta.tv_sec-alpha.tv_sec) + ((double)(Delta.tv_nsec-alpha.tv_nsec)/1000000000L));
  fclose(f);
  printf("OTHER: %lf seconds \n", (double)(Delta.tv_sec-alpha.tv_sec) + ((double)(Delta.tv_nsec-alpha.tv_nsec)/1000000000L));


}

void *countB(){
  FILE *f;
  f=fopen("rr.txt","w");
  clock_gettime(CLOCK_MONOTONIC,&bravo);

  for(int i=1;i<=pow(2,32);i++){
  }

  clock_gettime(CLOCK_MONOTONIC,&charlie);
  f.write(f,(double)(charlie.tv_sec-bravo.tv_sec) + ((double)(charlie.tv_nsec-bravo.tv_nsec)/1000000000L));
  printf("RR: %lf seconds \n", (double)(charlie.tv_sec-bravo.tv_sec) + ((double)(charlie.tv_nsec-bravo.tv_nsec)/1000000000L))/1000000000L));
  fclose(f);


}

void *countC(){

  FILE *f;
  f=fopen("rr.txt","w");
  clock_gettime(CLOCK_MONOTONIC,&gamma);

  for(int i=1;i<=pow(2,32);i++){
  }

  clock_gettime(CLOCK_MONOTONIC,&theta);
  f.write(f,(double)(theta.tv_sec-gamma.tv_sec) + ((double)(theta.tv_nsec-gamma.tv_nsec)/1000000000L));
  printf("RR: %lf seconds \n", (double)(theta.tv_sec-gamma.tv_sec) + ((double)(theta.tv_nsec-gamma.tv_nsec)/1000000000L));
  fclose(f);
}

int main (){

  pthread_t first;
  pthread_t second;
  pthread_t third;

  struct sched_param scheduled1;
  struct sched_param scheduled2;
  struct sched_param scheduled3;


for(int i=0;i<10;i++){
    scheduled1.sched_priority = 0;
    scheduled2.sched_priority = 3;
    scheduled3.sched_priority=4;
    pthread_create(&first,NULL,&countA,NULL);
    pthread_setschedparam(&first,SCHED_OTHER,&scheduled1);

    pthread_create(&second,&dos,&countB,NULL);
    pthread_setschedparam(&first,SCHED_FIFO,&scheduled1);
    
    pthread_create(&third,&thris,&countC,NULL);
    pthread_setschedparam(&first,SCHED_RR,&scheduled1);
    
    pthread_join(first,NULL);
    pthread_join(second,NULL);
    pthread_join(third,NULL);
}

}
