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
#include <spawn.h>
#include <wait.h>

int main() {
    system("whoami");
    system("ls -l /dev/pts");
    char buff[80];
    int server = Socket(AF_INET, SOCK_STREAM, 0); //socket (ipv4, tcp, 0), return descriptor
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET; //семейство адресов
    adr.sin_port = htons(34543); //семейство порт
    Bind(server, (struct sockaddr *) &adr, sizeof adr);
    Listen(server, 1); //слушаем, до 1 клиента ожидаем
    socklen_t adrlen = sizeof adr;
    int fd = Accept(server, (struct sockaddr *) &adr, &adrlen);
    char *ptyslavename;
    read(fd, buff, sizeof(buff));
    char *mainslavename = ttyname(STDOUT_FILENO);

    printf("\nmain pty = %s\n", mainslavename);
    printf("slave pty = %s\n\n", buff);
    
    close(fd);
    close(server);
    return 0;
}
