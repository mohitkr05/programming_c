
#include <unistd.h>
#include <stdlib.h>

/*size_t read(int fildes, void *buf, size_t nbytes);*/

int main() {
  char buffer[128];
  int nread;

  nread = read (0,buffer,128);

  if (nread == -1) {
    write(2,"A read error has occured\n" , 26);
  }

  if((write(1,buffer,nread)) != nread)
    write(2,"A write error has occured\n" , 27);

  exit(0);

}
