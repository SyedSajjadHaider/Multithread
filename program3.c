#include<stdio.h>
#include<pthread.h>
char msg[25]="flag";

void * function(void *arg){

strcpy(msg,"success");
return "thread_over";
}



int main(){

pthread_t pthread_id;
void *result;

pthread_create(&pthread_id,NULL,function,(void *)msg);
pthread_join(pthread_id,&result);

printf("%s\n",msg);
printf("%s",(char *)result);

}
