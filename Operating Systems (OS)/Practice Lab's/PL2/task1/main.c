#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc , char ** argv)
{
    //argv[2] : output.txt
    //argv[1] : ls

    int fd;
    fd = open(argv[2],O_CREAT | O_TRUNC | O_RDWR, 0777);
    
    dup2(fd,1)
    close(fd);

    execlp(argv[1],argv[1],NULL);
}
