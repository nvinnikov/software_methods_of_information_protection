# Lsshell
## About 
Libakrypt Secure Shell (Lsshell) - enable users perform remote control of the Linux operating system using a pseudo-terminal, increasing the authority of the process in the system.
## Man
The program interacts with Linux system calls:
```
grantpt(ptymfd) - grant access to the slave pseudo-terminal
unlockpt(ptymfd) - unlock a pseudoterminal master/slave pair
posix_openpt(O_RDWR) - open a pseudoterminal device
```
# Build
## Run
```
gcc server.c erproc.c -o server
gcc client.c erproc.c -o client
./server
./client
```
## Results
![server](https://user-images.githubusercontent.com/88853518/209653096-cebaef16-0400-4763-9537-dddb2f5aa549.jpg)
![client](https://user-images.githubusercontent.com/88853518/209653118-67fa6cf4-18cd-4eb9-be9b-bb579e41638b.jpg)
