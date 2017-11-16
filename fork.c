#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){

  printf("Initial message before forking\n");
  int f = -1;
  f = fork();

  if(f != 0){
    f = fork();
  }

  int sleeptime = 0;
  
  if(f == 0){
    //child process
    printf("pid: %d\n", getpid());
    srand(getpid());
    sleeptime = rand() % 16 + 5;
    printf("sleep time: %d \n", sleeptime);
    sleep(sleeptime);
    printf("pid: %d \tfinished sleeping\n", getpid());
  }
  else{
    //parent process
    int status;
    int childpid = wait(&status);
    printf("childpid: %d \t sleep time:%d\n", childpid, WEXITSTATUS(status));
    printf("finished waiting\n");
  }

  return sleeptime;
}
