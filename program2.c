#include<stdio.h>
#include<pthread.h>
int flag=2;
void *function(void *arg){
  int var=0;
  while(var++ < 20){
    if(flag == 1){
      printf("T");
      fflush(stdout);
      flag=2;
    }
    else{
      sleep(1);
    }
  }
}

int main(){

  pthread_t pthread_id;
  int var=0;
  pthread_create(&pthread_id,NULL,function,NULL);

  while(var++ < 20){
    if(flag ==2){
      printf("M");
      fflush(stdout);
      flag=1;
    }
    else{
      sleep(1);
    }
  }
  pthread_join(pthread_id,NULL);
}
