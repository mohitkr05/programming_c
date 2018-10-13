/* The purpose of this program is to understand the concept behind fork
 * -we are using a global variable and local variable
 * -After fork the pid is incremented and the global and local variables as well */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
  int var;
  pid_t pid;



  var = 88;
  printf ("Before Fork \n");

  pid = fork();

  if (pid<0) {
    perror("Fork error");
  }
  else if (pid == 0){
    printf("Child Process :");
    var++;
    printf("pid = %d , var = %d \n",getpid(), var );
  }
  else{
    printf("Parent Process :");
    printf("pid = %d , var = %d \n",getpid(), var );
    exit(0);
  }

}
