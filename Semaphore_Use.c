#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


sem_t sem_var;
void *function(void *arg){
  printf("Thread Started ... \n"); 
  sem_wait(&sem_var);
  printf("critical section\n");
  sleep(2);
  sem_post(&sem_var);
  
}

int main(){
  pthread_t pthread_id1,pthread_id2;
  sem_init(&sem_var,0,1);

  pthread_create(&pthread_id1,NULL,function,NULL);
  pthread_create(&pthread_id2,NULL,function,NULL);
  pthread_join(pthread_id1,NULL);
  pthread_join(pthread_id2,NULL);
  sem_destroy(&sem_var);
  
  
}
