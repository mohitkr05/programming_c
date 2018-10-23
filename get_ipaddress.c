/* The objective of this program is to fetch the IP address of a hostname https://beej.us/guide/bgnet/html/single/bgnet.html#syscalls  */
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main(int argc, char *argv[]) {

  struct addrinfo hints, *res, *p;
  int status;

  /*AF_INET6 src points to a struct in6_addr (in network byte order) which is
  converted to a representation of this address in the most appropriate
  IPv6 network address format for this address.
  The buffer dst must be at least INET6_ADDRSTRLEN bytes long.*/

  char ipstr[INET6_ADDRSTRLEN];

  if (argc != 2) {
    /*The functions in the printf() family produce output according to a format
    as described below. The functions printf() and vprintf() write output to
    stdout, the standard output stream;
    fprintf() and vfprintf() write output to the given output stream;
    sprintf(), snprintf(), vsprintf() and vsnprintf() write to the
    character string str. */
    fprintf(stderr, "%s\n","Usage : get_ipaddress.o hostname");
    return 1;
  }

  /*The result of the sizeof operator is of type size_t, an integral type
  defined in the include file STDDEF.H.
  This operator allows you to avoid specifying machine-dependent data sizes
  in your programs.
  The memset() function fills the first n bytes of the memory area pointed to
   by s with the constant byte c.



  */

  memset(&hints, 0, sizeof hints);


  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  /*
  int getaddrinfo(const char *node, const char *service,
                  const struct addrinfo *hints,
                  struct addrinfo **res);

  Given node and service, which identify an Internet host and a service,
  getaddrinfo() returns one or more addrinfo structures, each of which c
  ontains an Internet address that can be specified in a call to bind(2)
  or connect(2). The getaddrinfo() function combines the functionality
  provided by the gethostbyname(3) and getservbyname(3) functions into
  a single interface, but unlike the latter functions, getaddrinfo()
  is reentrant and allows programs to eliminate IPv4-versus-IPv6
  dependencies. The addrinfo structure used by getaddrinfo() contains
  the following fields:

    struct addrinfo {
        int              ai_flags;
        int              ai_family;
        int              ai_socktype;
        int              ai_protocol;
        socklen_t        ai_addrlen;
        struct sockaddr *ai_addr;
        char            *ai_canonname;
        struct addrinfo *ai_next;
    };

The hints argument points to an addrinfo structure that specifies criteria for
selecting the socket address structures returned in the list pointed to by res.
If hints is not NULL it points to an addrinfo structure whose ai_family,
ai_socktype, and ai_protocol specify criteria that limit the set of socket .

This field specifies the desired address family for the returned addresses. Valid values for this field include AF_INET and AF_INET6. The value AF_UNSPEC indicates that getaddrinfo() should return socket addresses for any address family (either IPv4 or IPv6, for example) that can be used with node and service. */
  if(status = getaddrinfo(argv[1] , NULL, &hints , &res) !=0 ) {


    /*The gai_strerror() function translates these error codes to a human readable
    string, suitable for error reporting.  */

    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status) );
    return 2;
  }

	printf("IP addresses for %s:\n\n", argv[1]);

  for (p = res ; p != NULL ; p = p->ai_next) {
    void *addr;
    char *ipver;

    if (p->ai_family == AF_INET) {
      struct sockaddr_in *ipv4 = (struct sockaddr_in *)p ->ai_addr;
      addr = &(ipv4->sin_addr);
      ipver = "IPv4";
    }
    else {
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
      addr = &(ipv6->sin6_addr);
      ipver = "IPv6";
    }

    /*#include <arpa/inet.h>
    const char *inet_ntop(int af, const void *src,char *dst, socklen_t size);
    Description
    This function converts the network address structure src in the af address
    family into a character string. The resulting string is copied to the buffer
    pointed to by dst, which must be a non-NULL pointer. The caller specifies
    the number of bytes available in this buffer in the argument size.
    inet_ntop() extends the inet_ntoa(3) function to support multiple address
    families, inet_ntoa(3) is now considered to be deprecated in favor of
    inet_ntop(). The following address families are currently supported: */
   inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
   	printf("  %s: %s\n", ipver, ipstr);
  }
  freeaddrinfo(res); // free the linked list
  return 0;

  }
