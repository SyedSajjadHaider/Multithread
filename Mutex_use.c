#include<stdio.h>
#include<pthread.h>

pthread_mutex_t var;

void * function(void *arg){
  pthread_mutex_lock(&var);
  printf("%s\n",arg);
  sleep(2);
  pthread_mutex_unlock(&var);
  
}


int main(){

  pthread_mutex_init(&var,NULL);
  
  pthread_t pthread_id1,pthread_id2;
  pthread_create(&pthread_id1,NULL,function,(void *)"thread1");
  pthread_create(&pthread_id2,NULL,function,(void *)"thread2");

  pthread_join(pthread_id1,NULL);
  pthread_join(pthread_id2,NULL); 
  
  
}
