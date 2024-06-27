#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include<pthread.h>
#include <sys/types.h>
#include <linux/userfaultfd.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <poll.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <stdio_ext.h>
#include "mpk_apis.h"
#include <mpt/mpt.h>
#include <mpt/pkey.h>
#include <mpk_heap.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                                  } while (0)

#define GROUP_1 100

#define DOMAIN 20

int vpkeys[DOMAIN];
const char* private_key = "900f9cc0781e1ef17e1574124751ff8b92f59d59c1b1f34e7391e1af9606fc9d";

int main(void)
{
    mpt_init(0.5);
    char *addr[10];
    addr[0] = (char *)malloc(strlen(private_key) + 1);
    vpkeys[0] = rwmmap((void**)&addr[0]);
    BRIDGE_DOMAINRW(vpkeys[0]);
    strcpy(addr[0], private_key);
    printf("giving the access of domain :%s\n", addr[0]);
    printf("Exit the read write permission fo the domain [0]\n");
    EXIT_DOMAIN(vpkeys[0]);
    DESTROY_DOMAIN(vpkeys[0]);
    printf("%s\n", addr[0]);

    // printf("addr[0]: %s\n", addr[0]);
    // printf("Changed the read write permission fo the domain [0]\n");
	// EXIT_DOMAIN(vpkeys[0]);
    // DESTROY_DOMAIN(vpkeys[0]);
    // printf("addr[0]: %s\n", addr[0]);

    return 0;
}
