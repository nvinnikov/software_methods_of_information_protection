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
#include <errno.h>
#include <termios.h>
#include <signal.h>
#include <string.h>
#include <spawn.h>
#include <wait.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(34543);
    Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    int ptymfd = Connect(fd, (struct sockaddr *) &adr, sizeof adr);
    //write(fd, ptymfd, );
    grantpt(ptymfd);
    unlockpt(ptymfd);
    system("whoami");
    system("ls -l /dev/pts");
    char *ptyslavename = ptsname(ptymfd);
    printf("slave pty filename: %s\n", ptyslavename);
    write(fd, ptyslavename, sizeof(ptyslavename)+2);

    //write(ptymfd, "Nikita\n", 1);

    //char buf[256];
    //ssize_t nread;
    //nread = read(ptymfd, buf, 256);

    // if (nread == -1) {
    //     perror("read failed");
    //     exit(EXIT_FAILURE);
    // }
    // if (nread == 0) {
    //     printf("EOF occured\n");
    // }
    
    //write(fd, buf, nread);
    sleep(1);
    close(ptymfd);
    return 0;
}
