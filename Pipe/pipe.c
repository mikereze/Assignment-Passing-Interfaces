#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main(){

    int fd[2];

    pipe(fd);
    pid_t pid = fork();

    if(pid == 0){
        //child process close the write end
        close(fd[WRITE]);
        int buf;
        read(fd[READ], &buf, sizeof(int));
        printf("The value passed from parent is %d\n", buf);
        
    }else if(pid > 0){
        //parent process close the read end
        close(fd[READ]);
        int val = 3;
        write(fd[WRITE], &val, sizeof(int));

    }else{
        printf("ERROR: fork has failed\n");
    }

    return 0;
}
