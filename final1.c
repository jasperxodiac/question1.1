#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>

void *countA(){
    struct timespec alpha;
    struct timespec Delta;
  FILE *f;
  f=fopen("other.txt","w");
  clock_gettime(CLOCK_MONOTONIC,&alpha);
  for(long long i=1;i<=pow(2,32);i++){
  }
  clock_gettime(CLOCK_MONOTONIC,&Delta);
  perror("Error");
  fprintf(f,"%lf",(double)(Delta.tv_sec-alpha.tv_sec) + ((double)(Delta.tv_nsec-alpha.tv_nsec)/1000000000));
  fclose(f);
  printf("OTHER: %lf seconds \n", (double)(Delta.tv_sec-alpha.tv_sec) + ((double)(Delta.tv_nsec-alpha.tv_nsec)/10000000000));


}

void *countB(){
    struct timespec bravo;
    struct timespec charlie;
  FILE *f;
  f=fopen("rr.txt","w");
  clock_gettime(CLOCK_MONOTONIC,&bravo);

  for(long long i=1;i<=pow(2,32);i++){
  }

  clock_gettime(CLOCK_MONOTONIC,&charlie);
  double z=
  fprintf(f,"%lf",(double)(charlie.tv_sec-bravo.tv_sec) + ((double)(charlie.tv_nsec-bravo.tv_nsec)/1000000000L));
  printf("RR: %lf seconds \n", (double)(charlie.tv_sec-bravo.tv_sec) + ((double)(charlie.tv_nsec-bravo.tv_nsec)/1000000000L));
  fclose(f);


}

void *countC(){
  
    struct timespec gamma1;
    struct timespec theta;
  FILE *f;
  f=fopen("rr.txt","w");
  clock_gettime(CLOCK_MONOTONIC,&gamma1);

  for(long long i=1;i<=pow(2,32);i++){
  }

  clock_gettime(CLOCK_MONOTONIC,&theta);
  fprintf(f,"%lf",(double)(theta.tv_sec-gamma1.tv_sec) + ((double)(theta.tv_nsec-gamma1.tv_nsec)/1000000000L));
  printf("RR: %lf seconds \n", (double)(theta.tv_sec-gamma1.tv_sec) + ((double)(theta.tv_nsec-gamma1.tv_nsec)/1000000000L));
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
    pthread_setschedparam(first,SCHED_OTHER,&scheduled1);
    perror("Error");

    pthread_create(&second,NULL,&countB,NULL);
    pthread_setschedparam(second,SCHED_RR,&scheduled2);
    perror("Error");
    
    pthread_create(&third,NULL,&countC,NULL);
    pthread_setschedparam(third,SCHED_FIFO,&scheduled3);
    perror("Error");
    
    pthread_join(first,NULL);
    pthread_join(second,NULL);
    pthread_join(third,NULL);
}

}
