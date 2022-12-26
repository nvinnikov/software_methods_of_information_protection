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

    //int ptymfd = posix_openpt(O_RDWR | O_NOCTTY);
    //grantpt(ptymfd);
    //unlockpt(ptymfd);

    //char *ptyslavename = ptsname(fds);

    //
    // size_t ptyslavenamelen = strlen(ptyslavename);
    // char slave_filename[ptyslavenamelen + 1];
    // strcpy(slave_filename, ptyslavename);
    // printf("slave pty filename: %s\n", slave_filename);
    //
    //int slave_fd = open(slave_filename, O_RDWR);

    // Set up slave pty to not echo input
    // struct termios tty_attrs;
    // tcgetattr(slave_fd, &tty_attrs);

    // tty_attrs.c_lflag &= ~ECHO;
    // tcsetattr(slave_fd, TCSANOW, &tty_attrs);
    // tcgetattr(slave_fd, &tty_attrs);

    // tty_attrs.c_lflag &= ~ISIG;
    // tcsetattr(slave_fd, TCSANOW, &tty_attrs);
    // tcgetattr(slave_fd, &tty_attrs);

    // tty_attrs.c_cflag &= ~CREAD;
    // tcsetattr(slave_fd, TCSANOW, &tty_attrs);
    // tcgetattr(slave_fd, &tty_attrs);



    //printf("The slave side is named : %s\n", ptsname(ptymfd));

    // printf("pty = %s\n", slavename);
    // char ch;
    // read(ptymfd, &ch, 1);
    // if ('A' <= ch && ch < 'Z')
    // 	ch++;
    // 	write(ptymfd, &ch, 1);
	// printf("pty = %s\n, text= %d\n", slavename, ch);
	// FILE *fout;
    //  	fout = fopen("output", "w");
	// fprintf(fout,"%s",slavename);

    printf("\nmain pty = %s\n", mainslavename);
    printf("slave pty = %s\n\n", buff);
    
    // while(1) {
    //     char ch;
    //     int r = read(fd, &ch, 1);
    //     int w = write(ptymfd, &ch, 1);
    // }
    system("ls -l /dev/pts");
    // ssize_t nread;
    // char buf[256];
    // nread = read(fd, buf, 256);
    // if (nread == -1) {
    //     perror("read failed");
    //     exit(EXIT_FAILURE);
    // }
    // if (nread == 0) {
    //     printf("END OF FILE occured\n");
    // }
    // write(STDOUT_FILENO, buf, nread);
    // write(fd, buf, nread);

    // sleep(15);

    close(fd);
    close(server);
    return 0;
}
