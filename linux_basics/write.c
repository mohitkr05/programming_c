
#include <unistd.h>
#include <stdlib.h>

/* size_t write(int fildes, const void *buf, size_t nbytes); */

int main(){
  /* it does not generate any error as it only writes 18 characters */

  if ((write(1,"Here is \n", 8)) != 8)
    write(2,"A write error has occured \n" , 46);

exit(0);
}
