#define _XOPEN_SOURCE 600

#include <sys/types.h> //constants
#include <sys/socket.h> //socket
#include <stdio.h>
#include <stdlib.h> //exit
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> //read
#include "erproc.h"

#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <signal.h>


#define check(res, text, err) if ((res) == -1) {       \
    perror(#text); \
    exit(err); \
  }

int Socket(int domain, int type, int protocol) {
    int res = socket(domain, type, protocol);
    check(res, "socket failed", EXIT_FAILURE);
    return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = bind(sockfd, addr, addrlen);
    check(res, "bind failed", EXIT_FAILURE);
}

void Listen(int sockfd, int backlog) {
    int res = listen(sockfd, backlog);
    check(res, "listen failed", EXIT_FAILURE);
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int res = accept(sockfd, addr, addrlen);
    check(res, "accept failed", EXIT_FAILURE);
    return res;
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    int res = connect(sockfd, addr, addrlen);
    check(res, "connect failed", EXIT_FAILURE);
    return posix_openpt(O_RDWR); //open a pseudoterminal device
}

void Inet_pton(int af, const char *src, void *dst) {
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        printf("inet_pton failed: src does not contain a character"
               " string representing a valid network address in the specified"
               " address family\n");
        exit(EXIT_FAILURE);
    }
    check(res, "inet_pton failed", EXIT_FAILURE);
}

