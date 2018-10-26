/* linux program to move a file */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
int open(const char *path, int oflags);
int open(const char *path, int oflags, mode_t mode)
*/
int main( int argc , char *argv[]) {
  char c , source, destination;
  int in, out;

  if(argc < 3 ) {
    fprintf(stderr, "%s\n", "Usage: mmv.o source target" );
  }

  in = open(argv[1], O_RDONLY);
  out = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

  while (read (in, &c, 1)==1) {
    write(out,&c,1);
  }

  exit(0);


}
