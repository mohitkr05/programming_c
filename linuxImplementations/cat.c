/* Program to emulate the cat functionality */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void cat(int rfd) {
  int wfd;
  static char *buf;
  static size_t bsize;
  struct stat sbuf;

  wfd = fileno(stdout);

  if(fstat (wfd, &sbuf)) {
    err(1,"stdout");
  }


  if(!buf) {
    bsize = sbuf.st_blksize;
    buf = malloc(bsize);
    if(!buf) {
      err(1,0);
    }
  }

  ssize_t nr,nw;
  int offset = 0;

  nr = read(rfd, buf, bsize);
  while(nr > 0){
    for(offset =0 ; nr > 0; nr -= nw , offset += nw){
      nw = write(wfd, buf+offset,nr);
      if(nw<0){
        err(1,"Stdout");
      }
    }
    nr = read(rfd,buf,bsize);
  }



}

int main (int argc, char* argv[]) {
  /* file descriptor */
   int fd;
   if (argc < 2) {
     fprintf(stderr, "%s\n", "Usage: cat.o <file1> <file2> ... or cat.o -" );
   }

   /* The function fileno() examines the argument stream and returns its integer descriptor. */

   fd = fileno(stdin);

   do {
     if (*argv) {
       if(strcmp (*argv , "-") == 0 ) {
         fd = fileno(stdin);
       }
       else{
         fd = open(*argv, O_RDONLY);

       }
       if(fd < 0){
         err(1, "%s", *argv);
       }

       ++argv;


     }
     cat(fd);
     if(fd != fileno(stdin)){
       close(fd);
     }

   }while(*argv);




}
