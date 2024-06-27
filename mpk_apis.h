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
#ifndef _MPK_API_H
#define _MPK_API_H
#endif

#ifdef MPK_DBG
  #define MPK_DBM(...)				\
    do {					\
      fprintf(stderr, __VA_ARGS__);		\
      fprintf(stderr, "\n");			\
    } while(0)
#else
   #define MPK_DBM(...)
#endif

unsigned long switch_cnt;

#define INCR_SCNT switch_cnt += 1;


#define MPK_ERR(...)				\
    do {					\
      fprintf(stderr, __VA_ARGS__);		\
      fprintf(stderr, "\n");			\
    } while(0)
  
#define RFLAG 0x1
#define WFLAG 0x2
#define RWFLAG 0x3
#define UNIT 0x1000

#define rwmmap(addr) \
                mpt_mmap(addr, UNIT, RWFLAG , MAP_ANONYMOUS | MAP_PRIVATE)

#define _init(val) \
                mpt_init(val); 

#define BRIDGE_DOMAINRW(dom) \
                mpt_begin(dom, RWFLAG)

#define BRIDGE_DOMAINR(dom) \
                mpt_begin(dom,RFLAG)

#define EXIT_DOMAIN(dom) \
                mpt_end(dom)

#define DESTROY_DOMAIN(dom) \
                mpt_destroy(dom)

