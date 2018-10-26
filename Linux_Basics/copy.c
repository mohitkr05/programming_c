/* a file copy program */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/*
int open(const char *path, int oflags);
int open(const char *path, int oflags, mode_t mode)
*/


int main () {
  char c;
  int in, out;


  in = open("file.in", O_RDONLY);
  out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

  while (read (in, &c, 1)==1) {
    write(out,&c,1);
  }

  exit(0);


}
