#include<stdio.h>
#include<pthread.h>
#include<string.h>
char msg[25] ="Hello";
void * function(void *ptr){
  printf("%s",ptr);

  return "Function";
}

int main(){

pthread_t pthread_id;
void *result;
pthread_create(&pthread_id,NULL,function,(void *)msg);

pthread_join(pthread_id,&result);

printf("%s",(char *)result);

}
