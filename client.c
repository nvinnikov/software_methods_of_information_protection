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
    grantpt(ptymfd);
    unlockpt(ptymfd);
    system("whoami");
    system("ls -l /dev/pts");
    char *ptyslavename = ptsname(ptymfd);
    printf("slave pty filename: %s\n", ptyslavename);
    write(fd, ptyslavename, sizeof(ptyslavename)+2);

    sleep(1);
    close(ptymfd);
    return 0;
}
