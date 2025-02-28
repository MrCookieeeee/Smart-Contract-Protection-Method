
#include "mpk_apis.h"
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
#include <pthread.h>
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
#include <mpt/mpt.h>
#include <mpt/pkey.h>
#include <mpk_heap.h>

#define DOMAIN 20
int vpkeys[DOMAIN];
int main(){
    printf("Now is add function\n");
    _init(0.5);
    char* addr[DOMAIN];
    int i =0;
    for(i = 0; i< DOMAIN; i++) {
        vpkeys[i] = rwmmap((void**)&addr[i]);
    }

    printf("Creating 100 domains each with one page memory.........\n");
    BRIDGE_DOMAINRW(vpkeys[0]);
    printf("Changed the read write permission fo the domain [0]\n");
    for(i =0;i< 4096;i++) {
        addr[0][i] = '@';
    }
    printf("Filled the page with a character\n");

    for(i =0;i< 4096;i++)
        printf("%c",addr[0][i]);
    printf("\n");
	EXIT_DOMAIN(vpkeys[0]);
    
    //DESTROY_DOMAIN(vpkeys[0]);
    printf("**The access to the page is disabled by writing to the pkru regsiter (AD,WD)\n\
             Any attempt to access this domain would genererate segfault\n");
    printf("%c\n",*addr[0]);
}
