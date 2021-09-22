#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/file.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#define READ 0
#define WRITE 1

int main(){

 pid_t pid;
 int fd[2];
 if(pipe(fd) == 0)
 {
    pid=fork();
    
    if(pid == 0)
    {
       close(fd[READ]);
       dup2(fd[WRITE],1);     
       close(fd[WRITE]);
       int f1=open("./input.txt", 0666|O_RDONLY);
       dup2(f1,0);
       close(f1);   
       execlp("grep","grep","m",NULL);
   }
   else if(pid > 0)
   {
      {
         wait(NULL);
         close(fd[WRITE]);
         dup2(fd[READ],0);
         close(fd[READ]);
         int f2=open("./output.txt",0666|O_CREAT|O_TRUNC);
         dup2(f2,1);
         close(f2);
         execlp("sort","sort",NULL);
      }
    }
 

  return 0;
}
