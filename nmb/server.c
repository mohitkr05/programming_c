#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


/*The  msgget() system call returns the System V message queue identifier associated with the value of the key argument.
A new message queue is created if key has the value IPC_PRIVATE or key isn't IPC_PRIVATE, no message queue with the given key key exists,
       and IPC_CREAT is specified in msgflg. */
